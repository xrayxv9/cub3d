CFLAGS = -g -Wall -Wextra -Werror -I MacroLibX/includes -I mandatory/include -I libft 
CFLAGS_BONUS = -g -Wall -Wextra -Werror -I MacroLibX/includes -I bonus/include -I libft

NAME = cub3D
NAME_BONUS = cub3D_bonus
MAKE = make --no-print-directory

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

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


PARSING_PATH = mandatory/src/parsing
RAYCASTING_PATH = mandatory/src/raycasting
RENDER_PATH = mandatory/src/render

PARSING_PATH_BONUS = bonus/src/parsing
RAYCASTING_PATH_BONUS = bonus/src/raycasting
RENDER_PATH_BONUS = bonus/src/render
SCENE_PATH_BONUS = bonus/src/scene
MINIMAP_PATH_BONUS = bonus/src/minimap
PORTAL_PATH_BONUS = bonus/src/portal

SRCS = $(PARSING_PATH)/parsing.c \
	   $(PARSING_PATH)/parsing_error.c \
	   $(PARSING_PATH)/textures.c \
	   $(PARSING_PATH)/map.c \
	   $(PARSING_PATH)/utils.c \
	   $(PARSING_PATH)/utils2.c \
	   $(RAYCASTING_PATH)/casting.c \
	   $(RAYCASTING_PATH)/utils.c \
	   $(RAYCASTING_PATH)/init.c \
	   $(RENDER_PATH)/main.c \
	   $(RENDER_PATH)/utils.c \
	   $(RENDER_PATH)/event.c \
	   $(RENDER_PATH)/render.c

SRCS_BONUS = $(PARSING_PATH_BONUS)/parsing_bonus.c \
			 $(PARSING_PATH_BONUS)/parsing_error_bonus.c \
			 $(PARSING_PATH_BONUS)/textures_bonus.c \
			 $(PARSING_PATH_BONUS)/map_bonus.c \
			 $(PARSING_PATH_BONUS)/utils_bonus.c \
			 $(PARSING_PATH_BONUS)/utils2_bonus.c \
			 $(RAYCASTING_PATH_BONUS)/casting_bonus.c \
			 $(RAYCASTING_PATH_BONUS)/utils_bonus.c \
			 $(RAYCASTING_PATH_BONUS)/init_bonus.c \
			 $(RENDER_PATH_BONUS)/main_bonus.c \
			 $(RENDER_PATH_BONUS)/utils_bonus.c \
			 $(RENDER_PATH_BONUS)/event_bonus.c \
			 $(RENDER_PATH_BONUS)/event2_bonus.c \
			 $(RENDER_PATH_BONUS)/event3_bonus.c \
			 $(RENDER_PATH_BONUS)/keyboard_event_bonus.c \
			 $(RENDER_PATH_BONUS)/render_bonus.c \
			 $(SCENE_PATH_BONUS)/scene_bonus.c \
			 $(SCENE_PATH_BONUS)/scene_error_bonus.c \
			 $(SCENE_PATH_BONUS)/load_scene_bonus.c \
			 $(SCENE_PATH_BONUS)/display_bonus.c \
			 $(SCENE_PATH_BONUS)/display2_bonus.c \
			 $(MINIMAP_PATH_BONUS)/minimap_bonus.c \
			 $(PORTAL_PATH_BONUS)/portal_bonus.c \
			 $(PORTAL_PATH_BONUS)/render_portal_bonus.c \
			 $(PORTAL_PATH_BONUS)/init_portal_bonus.c \
			 $(PORTAL_PATH_BONUS)/calcul_portal_bonus.c \

#-----------------------------------------------------RULES-----------------------------------------------#

all: $(NAME) 

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX) -lm -lSDL2
	@echo ">>> CUB3D COMPILED <<<"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

$(MLX):
	@$(MAKE) -C $(MLX_PATH) -s -j

ifeq ($(MAKECMDGOALS), bonus)
%.o: %.c
	@$(CC) $(CFLAGS_BONUS) -c -o $@ $<
else
%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<
endif

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS_BONUS) -o $(NAME_BONUS) $(OBJS_BONUS) $(LIBFT) $(MLX) -lm -lSDL2
	@echo ">>> CUB3D BONUS COMPILED <<<"

run: bonus
	@./$(NAME_BONUS) maps/.zizimap.cub

run2: all
	@valgrind --track-origins=yes --leak-check=full --suppressions=MacroLibX/valgrind.supp ./$(NAME_BONUS) maps/.zizimap.cub

clean:
	@$(MAKE) -C $(LIBFT_PATH) clean
	@# $(MAKE) -C $(MLX_PATH) clean
	@rm -f $(OBJS)
	@rm -f $(OBJS_BONUS)

fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@# $(MAKE) -C $(MLX_PATH) fclean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)


re: fclean all

.PHONY: all clean fclean re bonus
