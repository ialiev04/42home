NAME := minitalk
NAME_SERVER := server
NAME_CLIENT := client

CC := cc
CFLAGS := -Wall -Wextra -Werror

OBJ_DIR := ./obj
FT_PRINTF_DIR := ft_printf
FT_PRINTF_LIB := $(FT_PRINTF_DIR)/libftprintf.a

SRCS_SERVER := src_server/server.c
OBJS_SERVER := $(OBJ_DIR)/server.o

SRCS_CLIENT := src_client/client.c src_client/libft_helper.c
OBJS_CLIENT := $(OBJ_DIR)/client.o $(OBJ_DIR)/libft_helper.o

all : $(FT_PRINTF_LIB) $(NAME_SERVER) $(NAME_CLIENT)

$(FT_PRINTF_LIB):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(NAME_SERVER): $(OBJS_SERVER) $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) $^ -o $@

$(NAME_CLIENT): $(OBJS_CLIENT) $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) $^ -L$(FT_PRINTF_DIR) -lftprintf -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/server.o: src_server/server.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/client.o: src_client/client.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/libft_helper.o: src_client/libft_helper.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) -r $(OBJ_DIR)
	@cd ft_printf && make fclean
fclean: clean
	@$(RM) $(NAME_SERVER) $(NAME_CLIENT)
	@cd ft_printf && make clean

re: fclean all

.PHONY: all clean fclean re