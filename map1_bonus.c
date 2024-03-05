/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map1_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:49:31 by eviscont          #+#    #+#             */
/*   Updated: 2024/03/04 16:49:53 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_player_position(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->grid[y])
	{
		x = 0;
		while (map->grid[y][x])
		{
			if (map->grid[y][x] == 'P')
			{
				map->player.x = x;
				map->player.y = y;
				break ;
			}
			x++;
		}
		y++;
	}
}

//Evaluate position for flood fill
int	ff_get_position(char old, t_vec *exit_coll)
{
	if (old == 'P' || old == '0')
		return (0);
	else if (old == 'E')
	{
		exit_coll->x++;
		return (0);
	}
	else if (old == 'C')
	{
		exit_coll->y++;
		return (0);
	}
	return (1);
}

void	flood_fill(int x, int y, t_map *map, t_vec *exit_coll)
{
	if (ff_get_position(map->gridcopy[y][x], exit_coll) == 0)
	{
		map->gridcopy[y][x] = 'F';
		flood_fill(x, y + 1, map, exit_coll);
		flood_fill(x + 1, y, map, exit_coll);
		flood_fill(x, y - 1, map, exit_coll);
		flood_fill(x - 1, y, map, exit_coll);
	}
}

int	check_playable(t_map *map)
{
	t_vec	exit_coll;

	exit_coll.x = 0;
	exit_coll.y = 0;
	flood_fill(map->player.x, map->player.y, map, &exit_coll);
	if (exit_coll.y == map->n_coll && exit_coll.x == 1)
		return (1);
	return (0);
}

int	map_creation(t_map *map)
{
	if (validate_arg(map) == 0)
		return (ft_printf("Error:\nMap format is not .ber"), 0);
	map->grid = get_map_grid(map);
	if (map->grid == NULL)
		return (0);
	if (map_size(map) == 0)
		return (0);
	if (check_walls(map) == 0)
	{
		free_doublepointer(map->grid);
		free_doublepointer(map->gridcopy);
		return (ft_printf("Error:\nThe map must be within walls!"), 0);
	}
	get_player_position(map);
	if (check_playable(map) != 1)
	{
		free_doublepointer(map->grid);
		free_doublepointer(map->gridcopy);
		return (ft_printf("Error:\nThe map is not playable!"), 0);
	}
	return (1);
}
