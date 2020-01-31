/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:25:08 by gbiebuyc          #+#    #+#             */
/*   Updated: 2020/01/31 15:25:09 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

t_data g_data = {0};

size_t	get_zone_prealloc_size(size_t elem_size, size_t pagesize)
{
	size_t	result;

	result = 100 * (sizeof(t_node) + elem_size);
	result += (pagesize - (result % pagesize)) % pagesize;
	return (result);
}

void free(void *ptr)
{
	ft_printf("yolo\n");
}

char	*find_free_block(t_zone *z, size_t sz, size_t max_sz)
{
	t_node *node;

	if (!z->head)
	{
		z->prealloc_size = get_zone_prealloc_size(max_sz, getpagesize());
		z->head = mmap(0, z->prealloc_size,
			PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
		z->head->size = sz;
		z->head->next = NULL;
		z->head->is_free = true;
		return ((char*)(z->head + 1));
	}
	node = z->head;
	while (node)
	{
		if (node->is_free && node->size >= sz)
		{
			node->size = sz;
			node->is_free = false;
			return ((char*)(node + 1));
		}
		if (!node->next)
		{
			node->next = (t_node*)((char*)(node + 1) + node->size);
			node->next->size = sz;
			node->next->is_free = false;
			node->next->next = NULL;
			return ((char*)(node->next + 1));
		}
		node = node->next;
	}
	return (0);
}

void	*malloc(size_t size)
{
	if (size <= TINY)
		return (find_free_block(&g_data.tiny, size, TINY));
	else if (size <= SMALL)
		return (find_free_block(&g_data.small, size, SMALL));
	else
		;
	ft_printf("[debug] malloc failed.");
	return (0);
}

// void *realloc(void *ptr, size_t size)
// {
// 	write(1, "realloc\n", 8);
// 	// char *new = malloc(size);
// 	// memcpy(new, ptr, )
// 	return 0;
// }
