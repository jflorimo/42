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

CFILES = main.c eat.c eat2.c data.c data2.c data3.c exit.c

SRC = $(addprefix $(SRCDIR), $(CFILES))
GCC = gcc -Wall -Wextra -Werror -L/usr/X11/lib -lmlx -lXext -lX11
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