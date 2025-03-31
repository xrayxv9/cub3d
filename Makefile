CFLAGS = -g -Wall -Wextra -Werror

NAME = cub3D
MAKE = make --no-print-directory

OBJS = $(SRCS:.c=.o)

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

LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a

MLX_PATH = MacroLibX
MLX = $(MLX_PATH)/libmlx.so

SRCS = 

#-----------------------------------------------------RULES-----------------------------------------------#

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

$(MLX):
	@$(MAKE) -C $(MLX_PATH) -s -j

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX) -lm -lSDL2
	
%.o: %.c
	@echo -n $(CYAN)
	$(CC) $(CFLAGS) -c -o $@ $<
	@echo -n $(DEFAULT)

clean:
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) -C $(MLX_PATH) clean
	@rm -f $(OBJS)
	
fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(MAKE) -C $(MLX_PATH) fclean
	@rm -f $(NAME)


re: fclean all

.PHONY: all clean fclean re
