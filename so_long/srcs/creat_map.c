#include "so_long.h"

void	insert(t_map *head, t_map *new)
{
	new->prev = head->prev;
	head->prev->next = new;
	head->prev = new;
	new->next = head;
}

t_map	creat_map(int fd, t_data *data)
{
	char	*line;
	t_map	*map;

	data->height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map = (t_map *)malloc(sizeof(t_map));
		if (!map)
			return (data->head);
		map->row = line;
		insert(&data->head, map);
		data->height++;
	}
	data->width = ft_strlen(data->head.next->row) - 1;
	return (data->head);
}
