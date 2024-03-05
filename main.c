/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:50:06 by eviscont          #+#    #+#             */
/*   Updated: 2024/03/05 12:24:27 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_mouse(void)
{
	exit(0);
}

void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_printf("Error initializing MiniLibX!");
	game->window = mlx_new_window(game->mlx, game->map.w * PX, \
	game->map.h * PX, "So_Long");
	if (!game->window)
		free(game->mlx);
	load_images(game);
	put_map(game);
	mlx_put_image_to_window(game->mlx, game->window, \
	game->imgs[4], game->map.player.x * PX, game->map.player.y * PX);
	mlx_key_hook(game->window, key_handler, game);
	mlx_hook(game->window, 17, 0, close_mouse, 0);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_map	map;

	if (argc != 2)
		return (ft_printf("Error:\nWrong number of arguments!"), 0);
	map.name = argv[1];
	if (map_creation(&map) == 0)
		return (0);
	game.map = map;
	game.steps = 0;
	game_init(&game);
	return (0);
}
