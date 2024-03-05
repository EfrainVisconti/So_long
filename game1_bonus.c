/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game1_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:52:20 by eviscont          #+#    #+#             */
/*   Updated: 2024/03/04 16:52:42 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	player_movements(t_game *game, int x, int y)
{
	if (game->map.grid[y][x] && game->map.grid[y][x] != '1')
	{
		if (game->map.grid[y][x] == 'C')
		{
			game->map.n_coll--;
			game->map.grid[y][x] = '0';
		}
		game->map.player.x = x;
		game->map.player.y = y;
		game->steps++;
		ft_printf("%d moves\n", game->steps);
		winning_check(game);
	}
}

void	put_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.grid[y])
	{
		x = 0;
		while (game->map.grid[y][x])
		{
			if (game->map.grid[y][x] == '0' || game->map.grid[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->window, \
				game->imgs[0], x * PX, y * PX);
			if (game->map.grid[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->window, \
				game->imgs[1], x * PX, y * PX);
			if (game->map.grid[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->window, \
				game->imgs[2], x * PX, y * PX);
			if (game->map.grid[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->window, \
				game->imgs[3], x * PX, y * PX);
			x++;
		}
		y++;
	}
}

void	copy_images(char imgs[IMAGES_COUNT][40], t_game *game)
{
	int	i;
	int	h;
	int	w;

	i = 0;
	while (i < IMAGES_COUNT)
	{
		game->imgs[i] = mlx_xpm_file_to_image(game->mlx, imgs[i], &w, &h);
		if (game->imgs[i] == NULL)
		{
			ft_printf("Error loading images!");
			return ;
		}
		i++;
	}
}

void	load_images(t_game *game)
{
	char	imgs[IMAGES_COUNT][40];

	ft_strlcpy(imgs[0], FLOOR, 39);
	ft_strlcpy(imgs[1], WALL, 39);
	ft_strlcpy(imgs[2], EXIT, 39);
	ft_strlcpy(imgs[3], COLL, 39);
	ft_strlcpy(imgs[4], PLAYER_C, 39);
	ft_strlcpy(imgs[5], PLAYER_U1, 39);
	ft_strlcpy(imgs[6], PLAYER_U2, 39);
	ft_strlcpy(imgs[7], PLAYER_D1, 39);
	ft_strlcpy(imgs[8], PLAYER_D2, 39);
	ft_strlcpy(imgs[9], PLAYER_R1, 39);
	ft_strlcpy(imgs[10], PLAYER_R2, 39);
	ft_strlcpy(imgs[11], PLAYER_L1, 39);
	ft_strlcpy(imgs[12], PLAYER_L2, 39);
	copy_images(imgs, game);
}

int	key_handler(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_game(game);
	else if (keycode == KEY_UP || keycode == KEY_W)
	{
		player_movements(game, game->map.player.x, game->map.player.y - 1);
		game->player_dir = 1;
	}
	else if (keycode == KEY_DOWN || keycode == KEY_S)
	{
		player_movements(game, game->map.player.x, game->map.player.y + 1);
		game->player_dir = 2;
	}
	else if (keycode == KEY_LEFT || keycode == KEY_A)
	{
		player_movements(game, game->map.player.x - 1, game->map.player.y);
		game->player_dir = 4;
	}
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
	{
		player_movements(game, game->map.player.x + 1, game->map.player.y);
		game->player_dir = 3;
	}
	return (0);
}
