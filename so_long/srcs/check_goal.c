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
	return (0);
}

int	serch_goal(t_data *data, t_map_direct **index)
{
	if (all_searched(index, data) == 0)
		return (-1);
	move_to_player_y(data);
	if (data->map->row[data->player_x] != 'P')
		serch_all(data);
	if (index[data->player_y][data->player_x].up != 1)
	{
		index[data->player_y][data->player_x].up == 1;
		if (data->map->prev->row[data->player_x] != '1')
		{
			if (data->map->prev->row[data->player_x] == 'C')
				data->collected++;
			if (data->map->prev->row[data->player_x] == 'E')
			{
				data->exit_flag = 1;
				if (data->collected == data->c_num)
					return (0);
			}
			else
			{
				current_pos_img(data);
				data->map->prev->row[data->player_x] = 'P';
			}
			data->player_y -= 1;
		}
		serch_goal(data, index);
	}
	if (index[data->player_y][data->player_x].down != 1)
	{
		index[data->player_y][data->player_x].down == 1;
		if (data->map->next->row[data->player_x] != '1')
		{
			if (data->map->next->row[data->player_x] == 'C')
				data->collected++;
			if (data->map->next->row[data->player_x] == 'E')
			{
				data->exit_flag = 1;
				if (data->collected == data->c_num)
					return (0);
			}
			else
			{
				current_pos_img(data);
				data->map->next->row[data->player_x] = 'P';
			}
			data->player_y += 1;
		}
		serch_goal(data, index);
	}
	if (index[data->player_y][data->player_x].right != 1)
	{
		index[data->player_y][data->player_x].right == 1;
		if (data->map->row[data->player_x + 1] != '1')
		{
			if (data->map->row[data->player_x + 1] == 'C')
				data->collected++;
			if (data->map->row[data->player_x + 1] == 'E')
			{
				data->exit_flag = 1;
				if (data->collected == data->c_num)
					return (0);
			}
			else
			{
				current_pos_img(data);
				data->map->row[data->player_x + 1] = 'P';
			}
			data->player_x += 1;
		}
		serch_goal(data, index);
	}
	if (index[data->player_y][data->player_x].left != 1)
	{
		index[data->player_y][data->player_x].left == 1;
		if (data->map->row[data->player_x - 1] != '1')
		{
			if (data->map->row[data->player_x - 1] == 'C')
				data->collected++;
			if (data->map->row[data->player_x - 1] == 'E')
			{
				data->exit_flag = 1;
				if (data->collected == data->c_num)
					return (0);
			}
			else
			{
				current_pos_img(data);
				data->map->row[data->player_x - 1] = 'P';
			}
			data->player_x -= 1;
		}
		serch_goal(data, index);
	}
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
