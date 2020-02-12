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
# include <pthread.h>

# define TINY   1024
# define SMALL  32768

typedef struct		s_node
{
	size_t			size;
	struct s_node	*next;
	bool			is_free;
	char			padding[8];
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
	t_node			*large;
}					t_data;

extern t_data g_data;
extern pthread_mutex_t mutex;

void				free(void *ptr);
void				free_main(void *ptr);
void				*malloc(size_t size);
void				*malloc_main(size_t size);
void				*realloc(void *ptr, size_t size);
void				show_alloc_mem();
void				*calloc(size_t count, size_t size);
uintptr_t			align_ptr(uintptr_t ptr);
size_t				get_prealloc_size(size_t elem_size, size_t pagesize);
void				*init_node(t_node *n, size_t sz, bool f, bool c);
void				*init_node_in_new_zone(t_node **n, t_zone *z, size_t sz);

#endif
