# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbuchhol <nbuchhol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/02 by nbuchhol                #+#    #+#              #
#    Updated: 2025/09/02 by nbuchhol                ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME = cub3D

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I$(INCLUDES_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

# MLX flags
MLX_DIR = mlx_linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

# Directories
SRC_DIR = src
INCLUDES_DIR = includes
LIBFT_DIR = libft
OBJS_DIR = build

# Libft
LIBFT = $(LIBFT_DIR)/libft.a

# Source files
SRC_FILES = main.c
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

# Object files
OBJS = $(SRC:$(SRC_DIR)/%.c=$(OBJS_DIR)/%.o)

# Colors for pretty output
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m
RESET = \033[0m

# Main rule
all: $(NAME)

# Build the main program
$(NAME): $(LIBFT) $(OBJS)
	@echo "$(CYAN)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) compiled successfully!$(RESET)"

# Build libft
$(LIBFT):
	@echo "$(YELLOW)Building libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory
	@echo "$(GREEN)✓ libft compiled successfully!$(RESET)"

# Create object files
$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@echo "$(BLUE)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean object files
clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -rf $(OBJS_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@echo "$(GREEN)✓ Object files cleaned!$(RESET)"

# Clean everything
fclean: clean
	@echo "$(RED)Cleaning executable and libraries...$(RESET)"
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
	@echo "$(GREEN)✓ Everything cleaned!$(RESET)"

# Rebuild everything
re: fclean all

# Debug rule
debug: CFLAGS += -fsanitize=address -g3
debug: re

# Valgrind rule
valgrind: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

# Help
help:
	@echo "$(CYAN)Available targets:$(RESET)"
	@echo "  $(WHITE)all$(RESET)      - Build the program"
	@echo "  $(WHITE)clean$(RESET)    - Remove object files"
	@echo "  $(WHITE)fclean$(RESET)   - Remove object files and executable"
	@echo "  $(WHITE)re$(RESET)       - Rebuild everything"
	@echo "  $(WHITE)debug$(RESET)    - Build with debug flags and AddressSanitizer"
	@echo "  $(WHITE)valgrind$(RESET) - Run the program with valgrind"
	@echo "  $(WHITE)help$(RESET)     - Show this help message"

.PHONY: all clean fclean re debug valgrind help
