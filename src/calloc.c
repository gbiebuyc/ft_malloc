/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 16:53:03 by gbiebuyc          #+#    #+#             */
/*   Updated: 2020/02/08 16:53:03 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

void			*calloc(size_t count, size_t size)
{
	void	*ret;

	if ((ret = malloc(count * size)))
		ft_bzero(ret, count * size);
	return (ret);
}
