/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:14:22 by eviscont          #+#    #+#             */
/*   Updated: 2024/02/29 12:06:34 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	copy_images(char imgs[IMAGES_COUNT][30], t_game *game)
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
	char	imgs[IMAGES_COUNT][30];

	ft_strlcpy(imgs[0], FLOOR, 29);
	ft_strlcpy(imgs[1], WALL, 29);
	ft_strlcpy(imgs[2], EXIT, 29);
	ft_strlcpy(imgs[3], COLL, 29);
	ft_strlcpy(imgs[4], PLAYER, 29);
	copy_images(imgs, game);
}

int	key_handler(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_game(game);
	else if (keycode == KEY_UP || keycode == KEY_W)
		player_movements(game, game->map.player.x, game->map.player.y - 1);
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		player_movements(game, game->map.player.x, game->map.player.y + 1);
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		player_movements(game, game->map.player.x - 1, game->map.player.y);
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		player_movements(game, game->map.player.x + 1, game->map.player.y);
	mlx_clear_window(game->mlx, game->window);
	put_map(game);
	mlx_put_image_to_window(game->mlx, game->window, \
	game->imgs[4], game->map.player.x * PX, game->map.player.y * PX);
	return (0);
}
