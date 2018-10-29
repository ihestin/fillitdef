# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abossard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/25 12:27:53 by abossard          #+#    #+#              #
#    Updated: 2018/01/30 11:39:54 by ihestin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc
CFLAGS= -Wall -Werror -Wextra
SRC   = fillit.c ft_init.c read_fic.c solver.c tool.c cal_square.c
OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

%.o: %.c
	        $(CC) -o $@ -c  $< $(CFLAGS)
clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all
