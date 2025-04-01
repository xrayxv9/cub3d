# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/09 16:45:26 by mpendilh          #+#    #+#              #
#    Updated: 2025/04/01 16:12:54 by mpendilh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CFLAGS = -Wall -Werror -Wextra

NAME = libft.a

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

#-------------------------------------------------------SRCS----------------------------------------------------#

PRINTF_PATH = ft_printf
PRINTF_OBJ = $(PRINTF_PATH)/ft_hexa.o \
		 	$(PRINTF_PATH)/ft_hexaptr.o \
		 	$(PRINTF_PATH)/ft_printf.o \
		 	$(PRINTF_PATH)/ft_put_un_int.o \
		 	$(PRINTF_PATH)/ft_putchar.o \
		 	$(PRINTF_PATH)/ft_putnbr.o \
		 	$(PRINTF_PATH)/ft_putstr.o

SRCS = 		ft_atoi.c \
			ft_bzero.c \
			ft_is_sign.c \
			ft_is_isspace.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_strchr.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_strcmp.c \
			gnl.c \
			gnl_utils.c

#-----------------------------------------------------RULES-----------------------------------------------#

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS) 
	@make --no-print-directory -C $(PRINTF_PATH)
	@ar -rc $(NAME) $(OBJS) $(PRINTF_OBJ)
	@echo -n $(GREEN)
	@echo ">>>   Libft is compiled ✅  <<<"
	@echo -n $(DEFAULT)

clean:
	@make --no-print-directory -C $(PRINTF_PATH) clean
	@rm -f $(OBJS) 

fclean: clean
	@make --no-print-directory -C $(PRINTF_PATH) fclean
	@rm -f $(NAME)
	@echo -n $(YELLOW)
	@echo ">>>   Libft is cleaned 🧹  <<<"
	@echo -n $(DEFAULT)

re: fclean all

.PHONY: all bonus clean fclean re
