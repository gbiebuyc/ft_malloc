/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 16:53:13 by gbiebuyc          #+#    #+#             */
/*   Updated: 2020/02/08 16:53:13 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

bool	find_and_free_node(t_node **haystack, t_node *needle, bool unmap)
{
	size_t sz;

	while (*haystack)
	{
		if (*haystack == needle)
		{
			if ((*haystack)->is_free)
				return (false);
			(*haystack)->is_free = true;
			if (unmap)
			{
				sz = (*haystack)->size + sizeof(t_node);
				(*haystack) = (*haystack)->next;
				if (munmap((void*)needle, sz) == -1)
					return (false);
			}
			return (true);
		}
		haystack = &((*haystack)->next);
	}
	return (false);
}

void	free(void *ptr)
{
	if (!ptr)
		return ;
	ptr -= sizeof(t_node);
	if (!find_and_free_node(&g_data.tiny.head, ptr, false))
		if (!find_and_free_node(&g_data.small.head, ptr, false))
			find_and_free_node(&g_data.large, ptr, true);
}
