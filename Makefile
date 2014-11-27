# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eteyssed <eteyssed@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/24 18:24:10 by eteyssed          #+#    #+#              #
#    Updated: 2014/11/24 18:24:11 by eteyssed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf
SRC		=	main.c line.c square.c

FLAGS =		-Wall -Wextra -Werror
CC	=		gcc

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra $(SRC) -I. -o $(NAME) libft/libft.a -L/usr/X11/lib -lmlx -lXext -lX11
	./fdf 240 240 240 360

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
