NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar
ARFLAGS = rcs

SRCS =	src/ft_printf.c \
		src/ft_printf_utils.c \
		src/print_csp.c \
		src/print_diu.c \
		src/print_x.c

OBJ_DIR := ./obj
OBJS = $(SRCS:src/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@ar $(ARFLAGS) $(NAME) $(OBJS)

clean:
	@rm -rf $(OBJ_DIR)
	
fclean: clean
	@rm -f $(NAME)
	
re: fclean all
