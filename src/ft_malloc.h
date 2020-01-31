/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 13:09:22 by gbiebuyc          #+#    #+#             */
/*   Updated: 2020/01/30 13:09:24 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <libft.h>
# include <sys/mman.h>

# define TINY_MAX 0x100
# define SMALL_MAX 0x1000

typedef struct		s_node
{
	size_t			size;
	struct s_node	*next;
	bool			is_free;
}					t_node;

typedef struct		s_zone
{
	t_node			*head;
	size_t			prealloc_size;
}					t_zone;

typedef struct		s_data
{
	t_zone			tiny;
	t_zone			small;
}					t_data;

extern t_data g_data;

void				show_alloc_mem();

#endif
