# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 10:33:15 by gpirozzi          #+#    #+#              #
#    Updated: 2024/12/16 15:21:29 by gpirozzi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME = libftprintf.a
SRC = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_unsigned_putnbr.c ft_hexadecimal.c ft_forpointer.c
OBJECTS = ${SRC:.c=.o}

all: $(NAME)

$(NAME):$(OBJECTS)
		ar rc $(NAME) $(OBJECTS)

%.o: %.c
		$(CC) -c $(CFLAGS) -I. $< -o $@

clean:
		rm -rf $(OBJECTS)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
