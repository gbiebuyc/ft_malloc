
#include <stdlib.h>
#include <unistd.h>

void free(void *ptr);
void *malloc(size_t size);
void *realloc(void *ptr, size_t size);
void show_alloc_mem();

int main()
{
    void *ptr;

	for (int i = 0; i < 110; i++)
    	ptr = malloc(4096);

    show_alloc_mem();
    write(1, "\n", 1);

    // show_alloc_mem();
    // write(1, "\n", 1);
    
    free(ptr);
}
