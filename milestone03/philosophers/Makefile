NAME := philo

CC := cc
CFLAGS := -Wall -Werror -Wextra 

SRC_PATH := src

SRCS =	main.c \
		$(SRC_PATH)/init.c \
    	$(SRC_PATH)/simulation.c \
		$(SRC_PATH)/threads.c \
		$(SRC_PATH)/utils.c \
		$(SRC_PATH)/errors.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) 
	@$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	@$(CC) $(CFLAGS) -Iinclude -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re