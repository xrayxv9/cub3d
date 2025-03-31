# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 16:41:32 by mpendilh          #+#    #+#              #
#    Updated: 2024/11/16 10:11:53 by mpendilh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

OBJS = $(SRCS:%.c=%.o)

#-------------------------------------------------------COLORS--------------------------------------------------#

BLACK = "\e[30m"
RED = "\e[31m"
GREEN = "\e[32m"
YELLOW = "\e[33m"
BLUE = "\e[34m"
MAGENTA = "\e[35m"
CYAN = "\e[36m"
LIGHT_GRAY = "\e[37m"
DARK_GRAY = "\e[90m"
LIGHT_RED = "\e[91m"
LIGHT_GREEN = "\e[92m"
LIGHT_YELLOW = "\e[93m"
LIGHT_BLUE = "\e[94m"
LIGHT_MAGENTA = "\e[95m"
LIGHT_CYAN = "\e[96m"
WHITE = "\e[97m"
DEFAULT = "\e[39m"

#-----------------------------------------------------RULES-----------------------------------------------#

SRCS = ft_printf.c \
	   ft_putchar.c \
	   ft_putstr.c \
	   ft_hexa.c \
	   ft_hexaptr.c \
	   ft_putnbr.c \
	   ft_put_un_int.c

#-----------------------------------------------------RULES-----------------------------------------------#

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rc $(NAME) $(OBJS)
	
%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
