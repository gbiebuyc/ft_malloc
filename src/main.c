#include "ft_malloc.h"

size_t	get_zone_size(size_t elem_size, size_t pagesize)
{
	size_t	result;

	result = 100 * elem_size;
	while(result % pagesize)
		result += elem_size;
	return (result);
}

void free(void *ptr)
{
	printf("yolo\n");
}

void	init()
{
	d.tiny_zone_size = get_zone_size(TINY_MAX, getpagesize());
	d.small_zone_size = get_zone_size(SMALL_MAX, getpagesize());
	ft_printf("tiny zone size: %d\n", d.small_zone_size);
	exit(0);
}

void *malloc(size_t size)
{
	if (!d.head_tiny)
		init();
	write(1, "yolo from malloc\n", 17);
	return mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
}

// void *realloc(void *ptr, size_t size)
// {
// 	write(1, "realloc\n", 8);
// 	// char *new = malloc(size);
// 	// memcpy(new, ptr, )
// 	return 0;
// }
