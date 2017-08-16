#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yli <yli@student.42.us.org>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/11 16:08:57 by yli               #+#    #+#              #
#    Updated: 2017/07/12 15:15:59 by yli              ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = lem-in
CC = gcc
CFLAGS = -Wall -Werror -Wextra

LIBFT_DIR = ./src/libft
LIBFT = $(LIBFT_DIR)/libft.a
SRC = ./src

FILENAMES = main.c

OBJECTS = $(FILENAMES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(LIBFT) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c -I $(LIBFT_DIR) -o $@ $<

$(LIBFT): force
	$(MAKE) -C $(LIBFT_DIR)

force:
	true

clean:
	/bin/rm -f $(OBJECTS)
	cd $(LIBFT_DIR) && make clean

fclean: clean
	cd $(LIBFT_DIR) && make fclean
	cd ../
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re force
