###### MAKEFILE ######

# Global Config
NAME		= so_long

# Source Files
SRC_FILES	= main.c
SRC_DIR		= src
SRC			= $(addprefix $(SRC_DIR)/, $(SRC_FILES))

# Objects Files
OBJ_DIR		= $(SRC_DIR)/obj
OBJ			= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

# MLX42 Config
MLX42_DIR	= includes/MLX42/build
MLX42		= $(MLX42_DIR)/libmlx42.a
CFLAGS		= -Wall -Wextra -Werror
FLAGS_MLX	= -ldl -lglfw -pthread

# Colors
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
BLUE=\033[0;34m
PINK=\033[0;35m
NC=\033[0m  # (reset)

# RULES
all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(PINK) 🌱🐞 Littlebugs started to work $... 🌱⚒️$(NC)"
	$(CC) $(CFLAGS) $(OBJ) $(MLX42) -o $(NAME) $(FLAGS_MLX)
	@echo "$(GREEN) Linking finished!🌱🌼 $(NAME!)$(NC)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "$(PINK) $< 🌱 Bugs are building$... 🐞$(NC)"
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	@echo "$(RED) 🧼 Bugs are cleaning $(NAME) objects ... 🫧🐛 $"
	$(RM) -rf $(OBJ) 

fclean: clean
	@echo "$(RED) 🧼 Just cleaning up a bit more! 🫧🐝 $"
	$(RM) $(NAME)
	@echo "$(BLUE)🦋🫧🧼🫧 The bugs have clean everything! 🫧🧼🫧🐞$(NC)"

re: fclean all

.PHONY: all clean fclean re
