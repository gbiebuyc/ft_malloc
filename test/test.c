/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbiebuyc <gbiebuyc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 18:55:56 by gbiebuyc          #+#    #+#             */
/*   Updated: 2020/02/08 18:55:56 by gbiebuyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "../include/ft_malloc.h"
#include "../libft/libft.h"

int	main(void)
{
	void	*ptr;
	char	*ptr2;
	char	*p3;
	int		i;

	i = 0;
	while (i++ < 3)
		ptr = malloc(30);
	strcpy(ptr, "hello world\n");
	show_alloc_mem();
	write(1, "\n", 1);
	ptr2 = realloc(ptr, 42000);
	ft_printf(ptr2);
	show_alloc_mem();
	write(1, "\n", 1);
	(void)malloc(4300);
	(void)malloc(4400);
	p3 = malloc(4500);
	(void)malloc(4600);
	(void)malloc(4700);
	free(ptr2);
	free(p3);
	show_alloc_mem();
	write(1, "\n", 1);
}
