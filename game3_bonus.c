/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game3_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:50:46 by eviscont          #+#    #+#             */
/*   Updated: 2024/03/05 12:25:55 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_player_up(t_game *game)
{
	static int	p_frame ;
	static int	l;

	game->p_u[0] = 4;
	game->p_u[1] = 5;
	game->p_u[2] = 6;
	game->p_u[3] = 5;
	game->p_u[4] = 6;
	game->p_u[5] = 5;
	if (p_frame % (30 / 6) == 0 && p_frame != 0)
	{
		l = l + 1;
	}
	if (p_frame == 30)
	{
		p_frame = 0;
		l = 0;
	}
	mlx_put_image_to_window(game->mlx, game->window, game->imgs[game->p_u[l]], \
	game->map.player.x * PX, game->map.player.y * PX);
	p_frame++;
}

void	put_player_down(t_game *game)
{
	static int	p_frame ;
	static int	k;

	game->p_d[0] = 4;
	game->p_d[1] = 7;
	game->p_d[2] = 8;
	game->p_d[3] = 7;
	game->p_d[4] = 8;
	game->p_d[5] = 7;
	if (p_frame % (30 / 6) == 0 && p_frame != 0)
	{
		k = k + 1;
	}
	if (p_frame == 30)
	{
		p_frame = 0;
		k = 0;
	}
	mlx_put_image_to_window(game->mlx, game->window, game->imgs[game->p_d[k]], \
	game->map.player.x * PX, game->map.player.y * PX);
	p_frame++;
}

void	put_player_left(t_game *game)
{
	static int	p_frame ;
	static int	j;

	game->p_l[0] = 4;
	game->p_l[1] = 11;
	game->p_l[2] = 12;
	game->p_l[3] = 11;
	game->p_l[4] = 12;
	game->p_l[5] = 11;
	if (p_frame % (30 / 6) == 0 && p_frame != 0)
	{
		j = j + 1;
	}
	if (p_frame == 30)
	{
		p_frame = 0;
		j = 0;
	}
	mlx_put_image_to_window(game->mlx, game->window, game->imgs[game->p_l[j]], \
	game->map.player.x * PX, game->map.player.y * PX);
	p_frame++;
}
