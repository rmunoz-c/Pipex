# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmunoz-c <rmunoz-c@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024-12-24 15:52:35 by rmunoz-c          #+#    #+#              #
#    Updated: 2024-12-24 15:52:35 by rmunoz-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= pipex

LIBFT_DIR= libft
LIBFT = $(LIBFT_DIR)/libft.a

CC= cc
CFLAGS= -Wall -Werror -Wextra -g

SRC=		pipex.c \
			pipex_utils.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ) pipex.h
	$(CC) $(OBJ) $(LIBFT) -o $(NAME) -g

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)

%.o: %.c pipex.h
	$(CC) $(CFLAGS) -o $@ $< -c -g

clean:
	rm -f $(OBJ)
	$(MAKE) fclean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.DEFAULT_GOAL: all

.PHONY: all clean fclean re
