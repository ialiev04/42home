NAME = libft.a
SOURCES = \
	src/ft_strlen.c src/ft_strncmp.c

OBJECTS := $(patsubst src/%.c, obj/%.o, $(SOURCES))

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) -r $@ $^

obj/%.o: src/%.c | obj
	$(CC) -c $(CFLAGS) $< -o $@

obj:
	mkdir -p obj

clean:
	rm -rf obj

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re