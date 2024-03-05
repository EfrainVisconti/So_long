/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:40:42 by eviscont          #+#    #+#             */
/*   Updated: 2024/03/04 16:47:16 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
# define IMAGES_COUNT	13

//Textures location
# define FLOOR	"./textures/black.xpm"
# define WALL	"./textures/wall.xpm"
# define EXIT	"./textures/portal.xpm"
# define COLL	"./textures/coll.xpm"

# define PLAYER_C	"./textures/pac_closed.xpm"
# define PLAYER_U1 "./textures/pac_up_sem.xpm"
# define PLAYER_U2 "./textures/pac_up_open.xpm"
# define PLAYER_D1 "./textures/pac_down_sem.xpm"
# define PLAYER_D2 "./textures/pac_down_open.xpm"
# define PLAYER_R1 "./textures/pac_right_sem.xpm"
# define PLAYER_R2 "./textures/pac_right_open.xpm"
# define PLAYER_L1 "./textures/pac_left_sem.xpm"
# define PLAYER_L2 "./textures/pac_left_open.xpm"

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
	int		player_dir;
	int		p_u[6];
	int		p_d[6];
	int		p_r[6];
	int		p_l[6];
}	t_game;

//map1_bonus.c
int		map_creation(t_map *map);
int		check_playable(t_map *map);
void	flood_fill(int x, int y, t_map *map, t_vec *exit_coll);
int		ff_get_position(char old, t_vec *exit_coll);
void	get_player_position(t_map *map);

//map2_bonus.c
int		check_walls(t_map *map);
int		map_size(t_map *map);
char	**get_map_grid(t_map *map);
char	**get_map_grid_copy(char *entire_line);
int		check_items(char *entire_line, t_map *map);

//map3_bonus.c
int		check_invalid_items(char s);
char	*open_map(char *arg_map, char *entire_line, int fd);
int		validate_arg(t_map *map);

//utils_bonus.c
void	free_doublepointer(char **array);

//game1_bonus.c
int		key_handler(int keycode, t_game *game);
void	load_images(t_game *game);
void	copy_images(char imgs[IMAGES_COUNT][40], t_game *game);
void	put_map(t_game *game);
void	player_movements(t_game *game, int x, int y);

//game2_bonus.c
void	winning_check(t_game *game);
void	close_game(t_game *game);
void	put_moves(t_game *game);
int		put_animation(t_game *game);
void	put_player_right(t_game *game);

//game3_bonus.c
void	put_player_up(t_game *game);
void	put_player_down(t_game *game);
void	put_player_left(t_game *game);

//main_bonus.c
void	game_init(t_game *game);
int		close_mouse(void);

#endif