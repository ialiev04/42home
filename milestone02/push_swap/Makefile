NAME := push_swap

CC := cc
CFLAGS := -Wall -Werror -Wextra 

SRC_PATH := src
CMD_PATH := commands
LIBFT_PATH := mini_libft
PRINTF_PATH := ft_printf
LIBFT := $(LIBFT_PATH)/libft.a
PRINTF := $(PRINTF_PATH)/libftprintf.a

SRCS =	main.c \
		$(SRC_PATH)/lst_utils.c \
    	$(SRC_PATH)/sort_stack_utils.c \
		$(SRC_PATH)/sort_stack.c \
		$(SRC_PATH)/sort_three.c \
		$(SRC_PATH)/split.c \
		$(SRC_PATH)/stack_a.c \
		$(SRC_PATH)/stack_utils.c \
		$(CMD_PATH)/push.c \
		$(CMD_PATH)/revrotate.c \
		$(CMD_PATH)/rotate.c \
		$(CMD_PATH)/swap.c \
		$(LIBFT_PATH)/ft_calloc.c


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	@$(CC) $(CFLAGS) -I$(LIBFT_PATH) -c $< -o $@

$(PRINTF):
	@$(MAKE) -C $(PRINTF_PATH)

clean:
	$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) -C $(PRINTF_PATH) clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(MAKE) -C $(PRINTF_PATH) fclean

re: fclean all

.PHONY: all clean fclean re bonus