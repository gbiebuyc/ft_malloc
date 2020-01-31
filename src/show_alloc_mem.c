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

size_t	print_zone(t_node *node, char *zone_name)
{
	size_t ret;

	ret = 0;
	ft_printf("%s : %#x\n", zone_name, node);
	while (node)
	{
		ft_printf("%#x - %#x : %d bytes\n", node + 1,
			(char*)(node + 1) + node->size, node->size);
		ret += node->size;
		node = node->next;
	}
	return (ret);
}

void	show_alloc_mem()
{
	size_t	total;

	total = 0;
	if (g_data.tiny.head)
		total += print_zone(g_data.tiny.head, "TINY");
	if (g_data.small.head)
		total += print_zone(g_data.small.head, "SMALL");
	ft_printf("Total : %d bytes\n", total);
}
