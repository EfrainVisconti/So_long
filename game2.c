/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:11:12 by eviscont          #+#    #+#             */
/*   Updated: 2024/02/27 16:21:44 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
