/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:09:34 by eviscont          #+#    #+#             */
/*   Updated: 2024/02/16 16:51:24 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_arg(t_map *map)
{
	int		l;
	char	*s;

	s = map->name;
	l = ft_strlen(s);
	if (l >= 4)
	{
		if (s[l - 1] == 'r' && s[l - 2] == 'e'
			&& s[l - 3] == 'b' && s[l - 4] == '.')
			return (1);
	}
	return (0);
}

//Open the map and create an entire line
char	*open_map(char *arg_map, char *entire_line)
{
	int		fd;
	char	*line;
	char	*temp;

	fd = open(arg_map, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (line != NULL)
		{
			temp = ft_strdup(entire_line);
			free(entire_line);
			entire_line = ft_strjoin(temp, line);
			free(line);
			free(temp);
		}
		if (line == NULL)
			break ;
	}
	close(fd);
	return (entire_line);
}

//Checks if there are invalid elements
int	check_invalid_items(char s)
{
	if (s != '1' && s != '0' && s != 'E' && s != 'P' && s != 'C' && s != '\n')
		return (0);
	return (1);
}

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
			return (ft_printf("Invalid items found on the map!"), 0);
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
	return (ft_printf("Map must contain one P, one E and at least one C!"), 0);
}

//Create map grid
char	**get_map_grid(t_map *map)
{
	char	**grid;
	char	*entire_line;

	entire_line = ft_strdup("");
	entire_line = open_map(map->name, entire_line);
	if (entire_line == NULL)
		return (ft_printf("Error reading map!"), NULL);
	if (check_items(entire_line, map) == 0)
		return (NULL);
	grid = ft_split(entire_line, '\n');
	if (grid == NULL)
		return (ft_printf("Error getting map grid!"), NULL);
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
			return (ft_printf("Error:\nMap is not rectangular!"), 0);
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

// int	flood_fill(t_map *map)
// {
	
// }

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
		return (ft_printf("Error:\nThe map must be within walls!"), 0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		return (ft_printf("Error:\nWrong number of arguments"), 0);
	map.name = argv[1];
	if (map_creation(&map) == 0)
		return (0);
	ft_printf("\n%s", map.grid[0]);
	ft_printf("\n%s", map.grid[1]);
	ft_printf("\n%s", map.grid[2]);
	ft_printf("\n%s", map.grid[3]);
	ft_printf("\n%s", map.grid[4]);
	ft_printf("\n%s", map.grid[5]);
	//system("leaks so_long");
	return (0);
}
