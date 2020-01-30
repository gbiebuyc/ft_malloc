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
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/mman.h>

# define TINY_MAX 0x100
# define SMALL_MAX 0x1000

typedef struct		s_node
{
	size_t			size;
	struct s_node	*next;
	bool			is_free;
}					t_node;

typedef struct		s_data
{
	t_node			*head_tiny;
	t_node			*head_small;
	size_t			tiny_zone_size;
	size_t			small_zone_size;
}					t_data;

t_data d = {0};

#endif
