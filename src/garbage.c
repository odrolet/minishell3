#include "../include/parsing.h"

t_node	*garbage_collector(void)
{
	static t_node	head = {.next_mb = NULL, .address = NULL};

	return (&head);
}

void	*gc_malloc(size_t size)
{
	t_node	*new_mb;

	new_mb = malloc(sizeof(t_node) * 1);
	if (!new_mb)
	{
		gc_free_all();
		ft_putstr_fd("MALLOC_FAIL", 2);
		exit(1);
	}
	new_mb->next_mb = garbage_collector()->next_mb;
	garbage_collector()->next_mb = (struct Node *)new_mb;
	new_mb->address = malloc(size);
	if (!new_mb->address)
	{
		gc_free_all();
		ft_putstr_fd("MALLOC_FAIL", 2);
		exit(1);
	}
	return (new_mb->address);
}

void	gc_free_all(void)
{
	t_node		*gc_ptr;
	t_node		*ptr_copy;

	gc_ptr = garbage_collector()->next_mb;
	while (gc_ptr)
	{
		if (gc_ptr->address)
			free(gc_ptr->address);
		ptr_copy = gc_ptr;
		gc_ptr = gc_ptr->next_mb;
		free(ptr_copy);
	}
	garbage_collector()->next_mb = NULL;
}

void	gc_free(void *address)
{
	t_node		*gc_ptr;
	t_node		*ptr_copy;

	gc_ptr = garbage_collector()->next_mb;
	ptr_copy = garbage_collector();
	while (gc_ptr)
	{
		if (gc_ptr->address == address)
		{
			ptr_copy->next_mb = gc_ptr->next_mb;
			if (gc_ptr->address)
				free(gc_ptr->address);
			free(gc_ptr);
			return ;
		}
		ptr_copy = gc_ptr;
		gc_ptr = gc_ptr->next_mb;
	}
}
