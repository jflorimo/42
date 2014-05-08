#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jflorimo <jflorimo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/04/22 18:17:27 by jflorimo          #+#    #+#              #
#    Updated: 2014/04/22 18:17:27 by jflorimo         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =	philo

SRCDIR = srcs/

CFILES = main.c eat.c data.c

SRC = $(addprefix $(SRCDIR), $(CFILES))
GCC = gcc -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)
HDDIR = includes/

all: $(NAME)

$(NAME): $(OBJ)
		make -C libft/
		$(GCC) -o $(NAME) $(OBJ) libft/libft.a

%.o: %.c
	$(GCC) -c -o $@ $^  -I $(HDDIR)

clean:
		make -C libft/ clean
		rm -f $(OBJ)

fclean: clean
		make -C libft/ fclean
		rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re