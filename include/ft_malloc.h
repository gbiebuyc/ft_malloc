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

/*
** This is the public interface header.
** Internal header is in src/ directory.
*/

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <stdlib.h>

void	free(void *ptr);
void	*malloc(size_t size);
void	*realloc(void *ptr, size_t size);
void	show_alloc_mem();
void	*calloc(size_t count, size_t size);

#endif
