NAME = libft.a

# Folders - Updated to match your structure
SRC_DIR = src
OBJ_DIR = obj
GNL_DIR = gnl
INC_DIR = include

# Source Files
SOURCES = \
    $(SRC_DIR)/ft_isalpha.c $(SRC_DIR)/ft_isdigit.c $(SRC_DIR)/ft_isalnum.c \
    $(SRC_DIR)/ft_isascii.c $(SRC_DIR)/ft_isprint.c $(SRC_DIR)/ft_strlen.c \
    $(SRC_DIR)/ft_memset.c $(SRC_DIR)/ft_bzero.c $(SRC_DIR)/ft_memcpy.c \
    $(SRC_DIR)/ft_memmove.c $(SRC_DIR)/ft_strlcpy.c $(SRC_DIR)/ft_strlcat.c \
    $(SRC_DIR)/ft_toupper.c $(SRC_DIR)/ft_tolower.c $(SRC_DIR)/ft_strchr.c \
    $(SRC_DIR)/ft_strrchr.c $(SRC_DIR)/ft_strncmp.c $(SRC_DIR)/ft_memchr.c \
    $(SRC_DIR)/ft_memcmp.c $(SRC_DIR)/ft_strnstr.c $(SRC_DIR)/ft_atoi.c \
    $(SRC_DIR)/ft_calloc.c $(SRC_DIR)/ft_strdup.c $(SRC_DIR)/ft_substr.c \
    $(SRC_DIR)/ft_strjoin.c $(SRC_DIR)/ft_strtrim.c $(SRC_DIR)/ft_split.c \
    $(SRC_DIR)/ft_itoa.c $(SRC_DIR)/ft_strmapi.c $(SRC_DIR)/ft_striteri.c \
    $(SRC_DIR)/ft_putchar_fd.c $(SRC_DIR)/ft_putstr_fd.c \
    $(SRC_DIR)/ft_putendl_fd.c $(SRC_DIR)/ft_putnbr_fd.c \
    $(GNL_DIR)/get_next_line.c

# Bonus logic
BSOURCES = $(SRC_DIR)/ft_lstnew.c # ... (add the rest of your bonus files here)

# This logic handles files in both src/ and gnl/
OBJECTS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(SOURCES)))

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR) -I$(GNL_DIR)
AR = ar -rc

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(AR) $@ $^

# Use VPATH so make knows where to look for .c files
vpath %.c $(SRC_DIR) $(GNL_DIR)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re