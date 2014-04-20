#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jflorimo <jflorimo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/04/18 12:00:03 by jflorimo          #+#    #+#              #
#    Updated: 2014/04/18 12:00:04 by jflorimo         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so
LN_NAME = libft_malloc.so
GCCW = gcc -Wall -Wextra -Werror
IFLAGS = -I./
SRC = malloc.c
SRC += free.c
SRC += ft_putstr.c
SRC += header.c
SRC += malloc.c
SRC += realloc.c
SRC += show_alloc_mem.c

OBJECT = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJECT)
	ar rc $(NAME) $(OBJECT)
	ranlib $@
	/bin/rm -rf $(LN_NAME)
	ln -s $(NAME) $(LN_NAME)

%.o: %.c
	$(GCCW) -c $^ $(IFLAGS)

clean:
	/bin/rm -f $(OBJECT)

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f $(LN_NAME)

re: fclean all

.PHONY: all clean fclean re