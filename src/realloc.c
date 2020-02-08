/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 16:53:19 by gbiebuyc          #+#    #+#             */
/*   Updated: 2020/02/08 16:53:19 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

bool	find_node_size(t_node *haystack, t_node *needle, size_t *sz)
{
	while (haystack)
	{
		if (haystack == needle)
		{
			if (haystack->is_free)
				return (false);
			*sz = haystack->size;
			return (true);
		}
		haystack = haystack->next;
	}
	return (false);
}

void	*realloc(void *ptr, size_t new_sz)
{
	size_t	sz;
	char	*new_ptr;

	if (ptr == NULL)
		return (malloc(new_sz));
	if (new_sz == 0)
	{
		free(ptr);
		return (0);
	}
	if (!find_node_size(g_data.tiny.head, ptr - sizeof(t_node), &sz) &&
		!find_node_size(g_data.small.head, ptr - sizeof(t_node), &sz) &&
		!find_node_size(g_data.large, ptr - sizeof(t_node), &sz))
		return (NULL);
	if (!(new_ptr = malloc(new_sz)))
		return (NULL);
	ft_memcpy(new_ptr, ptr, sz);
	free(ptr);
	return (new_ptr);
}
