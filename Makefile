# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/03 17:57:20 by eviscont          #+#    #+#              #
#    Updated: 2024/02/14 15:18:25 by eviscont         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Comandos
CFLAGS = -Wall -Wextra -Werror

# Nombre ejecutable
NAME = so_long

# Ficheros
SRCS = map1.c
OBJS = $(SRCS:.c=.o)
HEADER = so_long.h

LIBS = libft/libft.a

# Reglas
all: libs $(NAME)

# Compilar
libs:
	@make -C libft

$(NAME): $(OBJS)
	gcc $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

%.o: %.c
		gcc $(CFLAGS) -c -o $@ $<

# Eliminar temporales

clean:
	@make clean -C libft
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(LIBS)

re: fclean all