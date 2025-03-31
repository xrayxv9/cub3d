NAME = cub3D

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

# Couleurs pour les messages
GREEN = \033[32m
RED = \033[31m
YELLOW = \033[33m
BLUE = \033[38;2;15;101;214m
RESET = \033[0m

LIBFT_DIR = libft/
LIBFT_FILE = libft.a
MLX_DIR = MacroLibX/
MLX_FILE = libmlx.so

OBJ_PATH = obj/
RENDER_PATH = mandatory/src/render/
PARSING_PATH = mandatory/src/parsing/
SIGNALS_PATH = mandatory/src/raycasting/


RAYCASTING = 
PARSING = 
RENDER = main.c

RAYCASTING = $(addprefix $(RAYCASTING_PATH), $(RAYCASTING))
RENDER = $(addprefix $(RENDER_PATH), $(RENDER))
PARSING = $(addprefix $(PARSING_PATH), $(PARSING))


OBJ_PARSING = $(PARSING:.c=.o)
OBJ_RENDER = $(RENDER:.c=.o)
OBJ_RAYCASTING = $(RAYCASTING:.c=.o)

OBJS_PARSING = $(addprefix $(OBJ_PATH), $(OBJ_PARSING))
OBJS_RENDER = $(addprefix $(OBJ_PATH), $(OBJ_RENDER))
OBJS_RAYCASTING = $(addprefix $(OBJ_PATH), $(OBJ_RAYCASTING))


LIBFT_LIB = $(addprefix $(LIBFT_DIR), $(LIBFT_FILE))
MLX_LIB = $(addprefix $(MLX_DIR), $(MLX_FILE))

all: $(NAME)
	@:	

$(NAME): $(LIBFT_LIB) $(OBJS_RENDER) $(OBJS_PARSING) $(OBJS_RAYCASTING)
	@$(CC) $(CFLAGS) $(OBJS_RENDER) $(OBJS_RAYCASTING) $(OBJS_PARSING) -o -lm -lSDL2 $@
	@echo "$(GREEN)>>>	CUBE COMPILED	<<<"

$(LIBFT_LIB):
	@make --no-print-directory -C $(LIBFT_DIR) bonus

$(MLX_LIB):
	@make --no-print-directory -C $(MLX_DIR) -s -j

$(OBJ_PATH)%.o: $(PARSING_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)%.o: $(RENDER_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)%.o: $(RAYCASTING_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@



clean:
	@echo ">>> $(RED)SUPPRESSION DES FICHIERS .o $(RESET)<<<"
	@rm -rf $(OBJ_PATH)
	@make --no-print-directory -C $(LIBFT_DIR) clean

fclean: clean
	@echo ">>> $(RED)SUPPRESSION DE L'EXECUTABLE $(RESET)<<<"
	@rm -f $(NAME)
	@make --no-print-directory -C $(LIBFT_DIR) fclean

re: fclean all
	@echo "$(RESET)"

.PHONY: all clean fclean re

