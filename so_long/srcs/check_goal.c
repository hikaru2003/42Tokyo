#include "so_long.h"

int	all_searched(t_map_direct **index, t_data *data)
{
	int	x;
	int	y;

	x = 1;
	y = 1;
	while (y < data->height - 1)
	{
		x = 1;
		while (x < data->width - 1)
		{
			if (index[y][x] == 0)
				return (1);
			x++;
		}
		y++;
	}
	print_error();
}

int	serch_goal(t_data *data, t_map_direct **index)
{
	all_searched(index, data);
	move_to_player_y(data);
	if (data->map->row[data->player_x] != 'P')
		serch_all(data);
	if (index[data->player_y][data->player_x].up != 1 && go_up(data, index) == 1)
		return (1);
	if (index[data->player_y][data->player_x].down != 1 && go_down(data, index) == 1)
		return (1);
	if (index[data->player_y][data->player_x].right != 1 && go_right(data, index) == 1)
		return (1);
	if (index[data->player_y][data->player_x].left != 1 && go_left(data, index) == 1)
		return (1);
	serch_goal(data, index);
}

int	check_goal(t_data *data)
{
	t_map_direct	**index;

	index = (t_map_direct **)malloc(sizeof(t_map_direct*) * data->height);
	if (!index)
		print_error();
	map_direct_init(index);
	serch_goal(data, index);
}
