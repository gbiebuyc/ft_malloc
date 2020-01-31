#include "ft_malloc.h"

size_t	get_zone_prealloc_size(size_t elem_size, size_t pagesize)
{
	size_t	result;

	result = 100 * (sizeof(t_node) + elem_size);
	while(result % pagesize)
		result += (sizeof(t_node) + elem_size);
	return (result);
}

void free(void *ptr)
{
	ft_printf("yolo\n");
}

void	init()
{
	g_data.tiny.prealloc_size = get_zone_prealloc_size(TINY_MAX, getpagesize());
	g_data.small.prealloc_size = get_zone_prealloc_size(SMALL_MAX, getpagesize());
	g_data.tiny.head = mmap(0, g_data.tiny.prealloc_size,
		PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	g_data.small.head = mmap(0, g_data.small.prealloc_size,
		PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	g_data.tiny.head->is_free = true;
	g_data.small.head->is_free = true;
}

char	*find_free_block(t_zone *z, size_t sz)
{
	t_node *node;

	node = z->head;
	while (node)
	{
		if (node->is_free)
			return ((char*)node + sizeof(t_node));
		node = node->next;
	}
	return (0);
}

void	show_alloc_mem()
{
	size_t	total;

	total = 0;
	if (g_data.tiny.head)
		ft_printf("TINY : %x\n", g_data.tiny.head);
	if (g_data.small.head)
		ft_printf("SMALL : %x\n", g_data.small.head);
	ft_printf("Total : %d bytes\n", total);
}

void	*malloc(size_t size)
{
	if (!g_data.tiny.head)
		init();
	if (size <= TINY_MAX)
		return (find_free_block(&g_data.tiny, size));
	else if (size <= SMALL_MAX)
		return (find_free_block(&g_data.small, size));
	else
		;
	ft_printf("[debug] malloc failed.");
	return (0);
}

// void *realloc(void *ptr, size_t size)
// {
// 	write(1, "realloc\n", 8);
// 	// char *new = malloc(size);
// 	// memcpy(new, ptr, )
// 	return 0;
// }
