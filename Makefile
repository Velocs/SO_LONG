# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aliburdi <aliburdi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/30 15:54:27 by aliburdi          #+#    #+#              #
#    Updated: 2022/11/28 17:46:59 by aliburdi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long
SRCS	=	./get_next_line/get_next_line_utils.c \
			./get_next_line/get_next_line.c \
			so_long.c map.c matrix.c utils.c \
			player_movement.c collisions.c \
			enemy_movement.c ft_itoa.c \
			animations.c ft_strcmp.c
			

OBJS	=	$(patsubst %.c, %.o, $(SRCS))
OBJS_B	=	$(patsubst %.c, %.o, $(SRCS_B))
CC		=	gcc
FLAGS	=	-g -Wall -Wextra -Werror
MINILIBX	=	-lmlx -framework OpenGL -framework AppKit
all: $(NAME)
$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(MINILIBX) $(OBJS) -o $(NAME)
%.o: %.c
	$(CC) $(FLAGS) -c $<  -o $@
clean:
	rm -f $(OBJS) $(OBJS_B)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re bonus