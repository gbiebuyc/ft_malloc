
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "include/ft_malloc.h"
#include "libft/libft.h"

int main()
{
    void *ptr;

	for (int i = 0; i < 3; i++)
    	ptr = malloc(30);
    strcpy(ptr, "hello world\n");
    show_alloc_mem();
    write(1, "\n", 1);

    char *ptr2 = realloc(ptr, 42000);
    ft_printf(ptr2);
    show_alloc_mem();
    write(1, "\n", 1);

    malloc(4300);
    malloc(4400);
    char *p3 = malloc(4500);
    malloc(4600);
    malloc(4700);
    free(ptr2);
    free(p3);
    show_alloc_mem();
    write(1, "\n", 1);
}
