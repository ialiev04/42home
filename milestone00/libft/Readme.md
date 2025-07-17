# 42 LIBFT by Ilias

This is my libft 42 project.

---

**Usage:**

Include the *libft.h* in your file.
Compile using make.

If you want to include the Makefile into your Makefile add the following rules:

LIBFTNAME = libft.a
LIBFTDIR = ./libft

$(NAME): makelibft ...

makelibft:
	@make -C $(LIBFTDIR)
	@cp $(LIBFTDIR)/$(LIBFTNAME) .
	@mv $(LIBFTNAME) $(NAME)