NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SOURCES =	ft_strlen.c \
			ft_strncmp.c 

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(AR) -r $@ $?

%.o: %.c
	@$(CC) -c $(CFLAGS) $?

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re