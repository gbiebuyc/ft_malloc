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

size_t	get_prealloc_size(size_t elem_size, size_t pagesize)
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

char	*allocate_node(t_node **node, t_zone *z, size_t sz)
{
	(*node) = mmap(0, z->prealloc_size,
		PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	(*node)->size = sz;
	(*node)->next = NULL;
	(*node)->is_free = false;
	return ((char*)(*node + 1));
}

char	*find_free_block(t_zone *z, size_t sz, size_t max_sz)
{
	t_node	*node;
	t_node	*last;
	char	*base;

	if (!z->head)
	{
		z->prealloc_size = get_prealloc_size(max_sz, getpagesize());
		return (allocate_node(&z->head, z, sz));
	}
	node = z->head;
	last = NULL;
	base = (char*)z->head;
	while (node)
	{
		if ((char*)node < base || (char*)node - base >= z->prealloc_size)
			base = (char*)node;
		if (node->is_free && node->size >= sz)
		{
			node->size = sz;
			node->is_free = false;
			return ((char*)(node + 1));
		}
		last = node;
		node = node->next;
	}
	last->next = (t_node*)((char*)(last + 1) + last->size);
	if ((char*)(last->next + 1) + sz - base >= z->prealloc_size)
		return (allocate_node(&last->next, z, sz));
	last->next->size = sz;
	last->next->is_free = false;
	last->next->next = NULL;
	return ((char*)(last->next + 1));
}

char	*alloc_large(t_node **node, size_t sz)
{
	while (*node)
		node = &((*node)->next);
	(*node) = mmap(0, sizeof(t_node) + sz,
		PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	(*node)->size = sz;
	(*node)->next = NULL;
	(*node)->is_free = false;
	return ((char*)(*node + 1));
}

void	*malloc(size_t size)
{
	if (size <= TINY)
		return (find_free_block(&g_data.tiny, size, TINY));
	else if (size <= SMALL)
		return (find_free_block(&g_data.small, size, SMALL));
	else
		return (alloc_large(&g_data.large, size));
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
