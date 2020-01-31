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

void	show_alloc_mem()
{
	size_t	total;

	total = 0;
	if (g_data.tiny.head)
		ft_printf("TINY : %#x\n", g_data.tiny.head);
	if (g_data.small.head)
		ft_printf("SMALL : %#x\n", g_data.small.head);
	ft_printf("Total : %d bytes\n", total);
}
