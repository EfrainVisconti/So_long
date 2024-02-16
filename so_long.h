/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:51:31 by eviscont          #+#    #+#             */
/*   Updated: 2024/02/15 16:24:56 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_map
{
	char	**grid;
	char	*name;
	int		h;
	int		w;
	int		n_coll;		
}	t_map;

typedef struct s_vec
{
	int	x;
	int	y;
}	t_vec;

typedef struct s_game
{
	t_vec	position;
}	t_game;

#endif