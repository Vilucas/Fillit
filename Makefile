# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: viclucas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 17:18:13 by viclucas          #+#    #+#              #
#    Updated: 2017/12/14 17:08:56 by vimarkov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= fillit

CC		= gcc

CFLAGS 	= -Wall -Werror -Wextra -g

DIR_SRC = ./src
DIR_OBJ = ./obj


INC = -I include/

SRC		=  main.c ft_fillit.c check.c ft_tetris.c ft_resolve.c count_block.c ft_ft.c

OBJ		= $(addprefix $(DIR_OBJ)/,$(SRC:.c=.o))

.PHONY: all clean fclean  re

all: $(NAME)
	
teste:
	@echo $(INC)


$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(INC) $(OBJ)

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c 
	mkdir -p $(DIR_OBJ)
	$(CC) $(CFLAGS) -c $(INC) $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean
	make
