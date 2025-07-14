NAME := fractol
CC := cc
CFLAGS := -Wall -Werror -Wextra -O3 -march=native

MLX_DIR := MLX42
MLX_INC := $(MLX_DIR)/include
MLX_LIB := $(MLX_DIR)/build
MLX_LIBFILE := $(MLX_LIB)/libmlx42.a

LIBFT_DIR := mini_libft
LIBFT_LIB := $(LIBFT_DIR)/libft.a

PRINTF_DIR := ft_printf
PRINTF_LIB := $(PRINTF_DIR)/libftprintf.a

SRCS :=	main.c \
		src/utils.c \
		src/calc_fractol.c \
		src/fractol_render.c \
		src/events.c \
		src/init.c \
		src/atof.c

OBJS := $(SRCS:.c=.o)

all: $(MLX_LIBFILE) $(LIBFT_LIB) $(PRINTF_LIB) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -I $(MLX_INC) -L $(MLX_LIB) -lmlx42 -lglfw \
		-L $(LIBFT_DIR) -lft -L $(PRINTF_DIR) -lftprintf \
		-framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo \
		-o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I $(MLX_INC) -I $(LIBFT_DIR) -I $(PRINTF_DIR) -c $< -o $@

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
	$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean

mlxclean:
	$(RM) $(OBJS)
	$(RM) $(NAME)

fclean: clean
	$(RM) $(NAME)
	$(RM) -r $(MLX_DIR)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean mlxclean re