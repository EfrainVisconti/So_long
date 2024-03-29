/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:51:31 by eviscont          #+#    #+#             */
/*   Updated: 2024/03/04 16:43:24 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "minilibx/mlx.h"
# include "libft/libft.h"

//Size of every tile (32x32)
# define PX	32

//Key codes for MacOS
# define KEY_ESC	53
# define KEY_UP		126
# define KEY_DOWN	125
# define KEY_LEFT	123
# define KEY_RIGHT	124
# define KEY_W	13
# define KEY_A	0
# define KEY_S	1
# define KEY_D	2

//Number of textures
# define IMAGES_COUNT	5

//Textures location
# define FLOOR	"./textures/black.xpm"
# define WALL	"./textures/wall.xpm"
# define EXIT	"./textures/portal.xpm"
# define COLL	"./textures/coll.xpm"
# define PLAYER	"./textures/pacman.xpm"

typedef struct s_vec
{
	int	x;
	int	y;
}	t_vec;

typedef struct s_map
{
	char	**grid;
	char	**gridcopy;
	char	*name;
	int		h;
	int		w;
	int		n_coll;	
	t_vec	player;
}	t_map;

typedef struct s_game
{
	t_map	map;
	void	*mlx;
	void	*window;
	void	*imgs[IMAGES_COUNT];
	int		steps;
}	t_game;

//map1.c
int		map_creation(t_map *map);
int		check_playable(t_map *map);
void	flood_fill(int x, int y, t_map *map, t_vec *exit_coll);
int		ff_get_position(char old, t_vec *exit_coll);
void	get_player_position(t_map *map);

//map2.c
int		check_walls(t_map *map);
int		map_size(t_map *map);
char	**get_map_grid(t_map *map);
char	**get_map_grid_copy(char *entire_line);
int		check_items(char *entire_line, t_map *map);

//map3.c
int		check_invalid_items(char s);
char	*open_map(char *arg_map, char *entire_line, int fd);
int		validate_arg(t_map *map);

//utils.c
void	free_doublepointer(char **array);

//game1.c
int		key_handler(int keycode, t_game *game);
void	load_images(t_game *game);
void	copy_images(char imgs[IMAGES_COUNT][30], t_game *game);
void	put_map(t_game *game);
void	player_movements(t_game *game, int x, int y);

//game2.c
void	winning_check(t_game *game);
void	close_game(t_game *game);

//main.c
void	game_init(t_game *game);
int		close_mouse(void);

#endif