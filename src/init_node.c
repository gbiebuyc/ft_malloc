/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 22:58:37 by gbiebuyc          #+#    #+#             */
/*   Updated: 2020/02/11 22:58:37 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void	*init_node(t_node *n, size_t sz, bool is_free, bool clear_next)
{
	n->size = sz;
	n->is_free = is_free;
	if (clear_next)
		n->next = NULL;
	return ((void*)(n + 1));
}

void	*init_node_in_new_zone(t_node **node, t_zone *z, size_t sz)
{
	(*node) = mmap(0, z->prealloc_size,
		PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if (*node == MAP_FAILED)
		return ((*node = NULL));
	return (init_node(*node, sz, false, true));
}
