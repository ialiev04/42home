NAME        = minishell

CC            = cc
CFLAGS        = -Wall -Werror -Wextra
INCLUDES    = -I./inc -I./libft/include

LIBFT_DIR    = ./libft
LIBFT        = $(LIBFT_DIR)/libft.a

SRC_DIR        = src
OBJ_DIR        = obj

SRCS        = $(shell find $(SRC_DIR) -name "*.c")

OBJS        = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

GREEN        = \033[0;32m
RED            = \033[0;31m
RESET        = \033[0m

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -lreadline -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) compiled successfully!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(GREEN)Compiled: $<$(RESET)"

$(LIBFT):
	@echo "$(GREEN)Building libft...$(RESET)"
	@make -C $(LIBFT_DIR) --no-print-directory

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean --no-print-directory
	@echo "$(RED)✓ Object files cleaned$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean --no-print-directory
	@echo "$(RED)✓ Executable removed$(RESET)"

re: fclean all

.PHONY: all clean fclean re