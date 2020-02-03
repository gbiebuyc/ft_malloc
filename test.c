
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "include/ft_malloc.h"

int main()
{
    void *ptr;

	for (int i = 0; i < 3; i++)
    	ptr = malloc(30);
    strcpy(ptr, "hello world\n");
    show_alloc_mem();
    write(1, "\n", 1);

    char *ptr2 = realloc(ptr, 42000);
    printf(ptr2);
    show_alloc_mem();
    write(1, "\n", 1);
}
