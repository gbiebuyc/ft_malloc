
#include <stdlib.h>
#include <unistd.h>
#include "include/ft_malloc.h"

int main()
{
    void *ptr;

	for (int i = 0; i < 3; i++)
    	ptr = malloc(3);
	for (int i = 0; i < 3; i++)
    	ptr = malloc(5000);
    malloc(6000);
    show_alloc_mem();
    write(1, "\n", 1);

    // show_alloc_mem();
    // write(1, "\n", 1);
    
    free(ptr);

    show_alloc_mem();
    write(1, "\n", 1);
}
