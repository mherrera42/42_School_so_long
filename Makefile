###### MAKEFILE ######

# Global Config
NAME		= so_long
SRC_FILES	= main.c
SRC_DIR		= src
SRC			= $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ_DIR		= $(SRC_DIR)/obj
OBJ			= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

# MLX42 Config
MLX42_DIR	= includes/MLX42/build
MLX42		= $(MLX42_DIR)/libmlx42.a
CFLAGS		= -Wall -Wextra -Werror
FLAGS_MLX	= -ldl -lglfw -pthread

# RULES
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX42) -o $(NAME) $(FLAGS_MLX)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	$(RM) -rf $(OBJ) 

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
