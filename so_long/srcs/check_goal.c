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
			if (index[y][x].up == 0 && index[y][x].down == 0
				&& index[y][x].left == 0 && index[y][x].right == 0)
				return (1);
			x++;
		}
		y++;
	}
	print_error(data);
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
		print_error(data);
	map_direct_init(index, data);
	serch_goal(data, index);
}

//another pattern　マップの行けるところをマーキングして行けないところにCかEがあったらエラー

// void	updata_map_status(int **map_status, t_data *data)
// {
// 	move_to_player_y(data);
// 	if (data->map->row[data->player_x] != 'P')
// 		serch_all(data);
// 	map_status[data->player_y][data->player_x] = 1;
// 	if (map_status[data->player_y - 1][data->player_x] != 1 && data->map->prev->row[data->player_x] != 1)
// 	{
// 		map_status[data->player_y - 1][data->player_x] = 1;
// 		data->player_y -= 1;
// 		updata_map_status(map_status, data);
// 	}
// 	if (map_status[data->player_y + 1][data->player_x] != 1 && data->map->next->row[data->player_x] != 1)
// 	{
// 		map_status[data->player_y + 1][data->player_x] = 1;
// 		data->player_y += 1;
// 		updata_map_status(map_status, data);
// 	}
// 	if (map_status[data->player_y][data->player_x - 1] != 1 && data->map->row[data->player_x - 1] != 1)
// 	{
// 		map_status[data->player_y][data->player_x - 1] = 1;
// 		data->player_x -= 1;
// 		updata_map_status(map_status, data);
// 	}
// 	if (map_status[data->player_y][data->player_x + 1] != 1 && data->map->row[data->player_x + 1] != 1)
// 	{
// 		map_status[data->player_y][data->player_x + 1] = 1;
// 		data->player_x += 1;
// 		updata_map_status(map_status, data);
// 	}
// }

// void	check_map_status(int **map_status, t_data *data)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	y = 0;
// 	data->map = data->head.next;
// 	while (y < data->height)
// 	{
// 		x = 0;
// 		while (x < data->width)
// 		{
// 			if (map_status[y][x] == 0 && (data->map->row[x] == 'C' || data->map->row[x] == 'E'))
// 				print_error(data);
// 			x++;
// 		}
// 		y++;
// 		data->map = data->map->next;
// 	}
// }

// int	check_goal(t_data *data)
// {
// 	int	**map_status;

// 	map_status = (int **)malloc(sizeof(int *) * data->height);
// 	if (!map_status)
// 		print_error(data);
// 	map_status_init(map_status, data);
// 	updata_map_status(map_status, data);
// 	check_map_status(map_status, data);
//  return (1);
// }