/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:24:57 by gbiebuyc          #+#    #+#             */
/*   Updated: 2020/01/31 15:25:00 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

size_t	print_zone(t_zone *z, t_node *node, char *zone_name)
{
	size_t		ret;
	uintptr_t	base;

	ret = 0;
	base = (uintptr_t)node;
	while (node)
	{
		if (((uintptr_t)node < base) ||
				((uintptr_t)node - base >= z->prealloc_size))
			base = (uintptr_t)node;
		if (!node->is_free)
		{
			if ((uintptr_t)node == base)
				ft_printf("%s : %p\n", zone_name, base);
			ft_printf("%p - %p : %zd octets\n", node + 1,
				(char*)(node + 1) + node->size, node->size);
			ret += node->size;
		}
		node = node->next;
	}
	return (ret);
}

size_t	print_large(t_node *node, char *zone_name)
{
	size_t ret;

	ret = 0;
	while (node)
	{
		ft_printf("%s : %p\n", zone_name, node);
		ft_printf("%p - %p : %zd octets\n", node + 1,
			(char*)(node + 1) + node->size, node->size);
		ret += node->size;
		node = node->next;
	}
	return (ret);
}

void	show_alloc_mem(void)
{
	size_t	total;

	if (pthread_mutex_lock(&mutex) != 0)
		return ;
	total = 0;
	if (g_data.tiny.head)
		total += print_zone(&g_data.tiny, g_data.tiny.head, "TINY");
	if (g_data.small.head)
		total += print_zone(&g_data.small, g_data.small.head, "SMALL");
	if (g_data.large)
		total += print_large(g_data.large, "LARGE");
	ft_printf("Total : %zd octets\n", total);
	pthread_mutex_unlock(&mutex);
}
