# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/03 17:57:20 by eviscont          #+#    #+#              #
#    Updated: 2024/03/05 13:24:13 by eviscont         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Comandos
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -framework OpenGL -framework AppKit

# Nombre ejecutable
NAME = so_long
NAME_BONUS = so_long_bonus

# Ficheros
SRCS = map1.c map2.c map3.c utils.c game1.c game2.c main.c
OBJS = $(SRCS:.c=.o)
HEADER = so_long.h

# Ficheros Bonus
SRCS_BONUS = map1_bonus.c map2_bonus.c map3_bonus.c utils_bonus.c game1_bonus.c game2_bonus.c game3_bonus.c main_bonus.c
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
HEADER_BONUS = so_long_bonus.h

LIBS = libft/libft.a
MLX = minilibx/libmlx.a

# Reglas
all: libs $(NAME)

bonus: libs $(NAME_BONUS)

# Compilar
libs:
	@make -C libft
	@make -C minilibx 

$(NAME): $(OBJS)
	gcc $(CFLAGS) $(MLXFLAGS) $(OBJS) $(LIBS) $(MLX) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS)
	gcc $(CFLAGS) $(MLXFLAGS) $(OBJS_BONUS) $(LIBS) $(MLX) -o $(NAME_BONUS)

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $<

# Eliminar temporales
clean:
	@make clean -C minilibx
	@make clean -C libft
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS) $(LIBS) $(MLX)

re: fclean all