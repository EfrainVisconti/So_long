/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map3_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:47:46 by eviscont          #+#    #+#             */
/*   Updated: 2024/03/04 16:48:04 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	validate_arg(t_map *map)
{
	int		l;
	char	*s;

	s = map->name;
	l = ft_strlen(s);
	if (l > 4)
	{
		if (s[l - 1] == 'r' && s[l - 2] == 'e'
			&& s[l - 3] == 'b' && s[l - 4] == '.')
			return (1);
	}
	return (0);
}

//Open the map and create an entire line
char	*open_map(char *arg_map, char *entire_line, int fd)
{
	char	*line;
	char	*temp;
	char	*path;

	path = ft_strjoin("./maps/", arg_map);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (free(path), free(entire_line), NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (ft_strlen(line) == 1)
			line[0] = 'Q';
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
	return (close(fd), free(path), entire_line);
}

//Checks if there are invalid elements
int	check_invalid_items(char s)
{
	if (s != '1' && s != '0' && s != 'E' && s != 'P' && s != 'C' && s != '\n')
	{
		return (0);
	}
	return (1);
}
