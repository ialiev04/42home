NAME := fractol
CC := cc
CFLAGS := -Wall -Werror -Wextra -O3 -march=native

# GLFW library path (auto-detects Homebrew installation)
GLFW_LIB := $(shell brew --prefix)/lib

MLX_DIR := MLX42
MLX_INC := $(MLX_DIR)/include
MLX_LIB := $(MLX_DIR)/build
MLX_LIBFILE := $(MLX_LIB)/libmlx42.a

LIBFT_DIR := mini_libft
LIBFT_LIB := $(LIBFT_DIR)/libft.a

PRINTF_DIR := ft_printf
PRINTF_LIB := $(PRINTF_DIR)/libftprintf.a

OBJ_DIR := obj

SRCS :=	main.c \
		src/utils.c \
		src/calc_fractol.c \
		src/fractol_render.c \
		src/events.c \
		src/init.c \
		src/atof.c

OBJS := $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

all: $(MLX_LIBFILE) $(LIBFT_LIB) $(PRINTF_LIB) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -I $(MLX_INC) -L $(MLX_LIB) -lmlx42 \
		-L $(GLFW_LIB) -lglfw \
		-L $(LIBFT_DIR) -lft -L $(PRINTF_DIR) -lftprintf \
		-framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo \
		-o $(NAME)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(MLX_INC) -I $(LIBFT_DIR) -I $(PRINTF_DIR) -c $< -o $@

$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(MLX_INC) -I $(LIBFT_DIR) -I $(PRINTF_DIR) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(MLX_LIBFILE):
	@git clone --recursive https://github.com/codam-coding-college/MLX42.git $(MLX_DIR) || true
	@cd $(MLX_DIR) && git submodule update --init --recursive
	@cmake -B $(MLX_LIB) -S $(MLX_DIR)
	@cmake --build $(MLX_LIB)

$(LIBFT_LIB):
	@$(MAKE) -C $(LIBFT_DIR)

$(PRINTF_LIB):
	@$(MAKE) -C $(PRINTF_DIR)

clean:
	$(RM) -r $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean

mlxclean:
	$(RM) -r $(OBJ_DIR)
	$(RM) $(NAME)

fclean: clean
	$(RM) $(NAME)
	$(RM) -r $(MLX_DIR)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean mlxclean re