/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:53:53 by eviscont          #+#    #+#             */
/*   Updated: 2024/02/29 15:45:14 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Checks collectables, player and exit on the map
int	check_items(char *entire_line, t_map *map)
{
	int	i;
	int	exit;
	int	player;

	i = 0;
	exit = 0;
	player = 0;
	map->n_coll = 0;
	while (entire_line[i] != '\0')
	{
		if (check_invalid_items(entire_line[i]) == 0)
			return (free(entire_line), ft_printf("Invalid items found!"), 0);
		if (entire_line[i] == 'E')
			exit++;
		else if (entire_line[i] == 'P')
			player++;
		else if (entire_line[i] == 'C')
			map->n_coll++;
		i++;
	}
	if (exit == 1 && player == 1 && map->n_coll >= 1)
		return (1);
	free (entire_line);
	return (ft_printf("Map must contain one P, one E and at least one C!"), 0);
}

//Create map grid's copy for flood fill
char	**get_map_grid_copy(char *entire_line)
{
	char	**grid;

	grid = ft_split(entire_line, '\n');
	if (grid == NULL)
		return (ft_printf("Error getting map grid's copy!"), NULL);
	return (grid);
}

//Create map grid
char	**get_map_grid(t_map *map)
{
	char	**grid;
	char	*entire_line;

	entire_line = ft_strdup("");
	entire_line = open_map(map->name, entire_line, 0);
	if (entire_line == NULL)
		return (ft_printf("Error reading map!"), NULL);
	if (check_items(entire_line, map) == 0)
		return (NULL);
	grid = ft_split(entire_line, '\n');
	if (grid == NULL)
		return (ft_printf("Error getting map grid!"), NULL);
	map->gridcopy = get_map_grid_copy(entire_line);
	free(entire_line);
	return (grid);
}

//Checks map size
int	map_size(t_map *map)
{
	int	y;
	int	x;
	int	x_temp;

	y = 0;
	x_temp = 0;
	while (map->grid[y] != NULL)
	{
		x = 0;
		while (map->grid[y][x] != '\0')
			x++;
		if (x_temp == 0)
			x_temp = x;
		if (x_temp != 0 && x_temp != x)
		{
			free_doublepointer(map->grid);
			free_doublepointer(map->gridcopy);
			return (ft_printf("Error:\nMap is not rectangular!"), 0);
		}
		y++;
	}
	map->w = x;
	map->h = y;
	return (1);
}

//Check if the map is correctly closed
int	check_walls(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (x < map->w)
	{
		if ((map->grid[0][x] != '1') || (map->grid[map->h - 1][x] != '1'))
			return (0);
		x++;
	}
	while (y < map->h)
	{
		if ((map->grid[y][0] != '1') || (map->grid[y][map->w - 1] != '1'))
			return (0);
		y++;
	}
	return (1);
}
