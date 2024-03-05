/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:51:19 by eviscont          #+#    #+#             */
/*   Updated: 2024/03/05 12:26:26 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_player_right(t_game *game)
{
	static int	p_frame ;
	static int	i;

	game->p_r[0] = 4;
	game->p_r[1] = 9;
	game->p_r[2] = 10;
	game->p_r[3] = 9;
	game->p_r[4] = 10;
	game->p_r[5] = 9;
	if (p_frame % (30 / 6) == 0 && p_frame != 0)
	{
		i = i + 1;
	}
	if (p_frame == 30)
	{
		p_frame = 0;
		i = 0;
	}
	mlx_put_image_to_window(game->mlx, game->window, game->imgs[game->p_r[i]], \
	game->map.player.x * PX, game->map.player.y * PX);
	p_frame++;
}

int	put_animation(t_game *game)
{
	mlx_clear_window(game->mlx, game->window);
	put_map(game);
	if (game->player_dir == 1)
		put_player_up(game);
	if (game->player_dir == 2)
		put_player_down(game);
	if (game->player_dir == 3)
		put_player_right(game);
	if (game->player_dir == 4)
		put_player_left(game);
	put_moves(game);
	return (0);
}

void	put_moves(t_game *game)
{
	char	*steps;

	steps = ft_itoa(game->steps);
	mlx_string_put(game->mlx, game->window, PX / 2, PX / 2, 0x00FFFFFF, steps);
}

void	close_game(t_game *game)
{
	mlx_clear_window(game->mlx, game->window);
	free_doublepointer(game->map.grid);
	free_doublepointer(game->map.gridcopy);
	exit(0);
}

void	winning_check(t_game *game)
{
	int	x;
	int	y;

	x = game->map.player.x;
	y = game->map.player.y;
	if (game->map.n_coll == 0 && game->map.grid[y][x] == 'E')
	{
		ft_printf("Congrats! You won!");
		close_game(game);
	}
}
