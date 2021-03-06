/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 17:38:39 by gbiebuyc          #+#    #+#             */
/*   Updated: 2020/02/08 17:38:39 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

t_data g_data;
pthread_mutex_t g_mutex = PTHREAD_MUTEX_INITIALIZER;

void	*alloc_tiny_or_small(t_zone *z, size_t sz, size_t max_sz)
{
	t_node		*node;
	t_node		*last;
	uintptr_t	base;

	if (!z->head)
	{
		z->prealloc_size = get_prealloc_size(max_sz, getpagesize());
		return (init_node_in_new_zone(&z->head, z, sz));
	}
	node = z->head;
	base = (uintptr_t)z->head;
	while (node)
	{
		if (((uintptr_t)node < base) ||
				((uintptr_t)node - base >= z->prealloc_size))
			base = (uintptr_t)node;
		if (node->is_free && node->size >= sz)
			return (init_node(node, sz, false, false));
		last = node;
		node = node->next;
	}
	last->next = (t_node*)(align_ptr((uintptr_t)(last + 1) + last->size));
	if (((uintptr_t)(last->next + 1) + sz - base) >= z->prealloc_size)
		return (init_node_in_new_zone(&last->next, z, sz));
	return (init_node(last->next, sz, false, true));
}

void	*alloc_large(t_node **node, size_t sz)
{
	while (*node)
		node = &((*node)->next);
	(*node) = mmap(0, sizeof(t_node) + sz,
		PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if (*node == MAP_FAILED)
		return ((*node = NULL));
	return (init_node(*node, sz, false, true));
}

void	*malloc_main(size_t size)
{
	if (size <= TINY)
		return (alloc_tiny_or_small(&g_data.tiny, size, TINY));
	else if (size <= SMALL)
		return (alloc_tiny_or_small(&g_data.small, size, SMALL));
	else
		return (alloc_large(&g_data.large, size));
	return (0);
}

void	*malloc(size_t size)
{
	void *ret;

	if (pthread_mutex_lock(&g_mutex) != 0)
		return (0);
	ret = malloc_main(size);
	pthread_mutex_unlock(&g_mutex);
	return (ret);
}
