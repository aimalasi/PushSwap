# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aimalasi <aimalasi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/21 18:45:34 by aimalasi          #+#    #+#              #
#    Updated: 2026/04/24 17:37:40 by aimalasi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

HEADER	= ./push_swap.h

SRC		= ./push_swap.c		\
		  ./operations.c	\
		  ./radix.c			\
		  ./small_sort.c	\
		  ./utils.c

OBJ = $(SRC:.c=.o)



all: $(NAME)

$(NAME): $(HEADER) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all



.PHONY: all clean fclean re