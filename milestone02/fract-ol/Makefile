NAME := fractol
CC := cc
CFLAGS := -Wall -Werror -Wextra -O3 -march=native

MLX_DIR := MLX42
MLX_INC := $(MLX_DIR)/include
MLX_LIB := $(MLX_DIR)/build
MLX_LIBFILE := $(MLX_LIB)/libmlx42.a

SRCS :=	main.c \
		utils.c \
		calc_fractol.c \
		fractol_render.c \
		events.c \
		libft/ft_strncmp.c \
		libft/ft_atoi.c \
		libft/ft_strlen.c

OBJS := $(SRCS:.c=.o)

all: $(MLX_LIBFILE) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -I $(MLX_INC) -L $(MLX_LIB) -lmlx42 -lglfw \
		-framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo \
		-o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I $(MLX_INC) -c $< -o $@

$(MLX_LIBFILE):
	@git clone --recursive https://github.com/codam-coding-college/MLX42.git $(MLX_DIR) || true
	@cd $(MLX_DIR) && git submodule update --init --recursive
	@cmake -B $(MLX_LIB) -S $(MLX_DIR)
	@cmake --build $(MLX_LIB)

clean:
	$(RM) $(OBJS)

mlxclean:
	$(RM) $(OBJS)
	$(RM) $(NAME)

fclean: clean
	$(RM) $(NAME)
	$(RM) -r $(MLX_DIR)

re: fclean all

.PHONY: all clean fclean mlxclean re