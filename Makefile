NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra  $(INCLUDES_D)

SRC = ft_printf.c	
OBJ = $(SRC:.c=.o)

# Directories
OBJ_D = obj/
SRC_D = src/
BIN_D = bin/
INCLUDES_D = -Iincludes/ -Ilibft/includes/

.PHONY: all
all : $(NAME)

OBJ := $(addprefix $(OBJ_D), $(OBJ))
SRC := $(addprefix $(SRC_D), $(SRC))

$(NAME):$(OBJ)
	$(MAKE) -C libft
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJ)

$(OBJ_D)%.o: $(SRC_D)%.c includes/ft_printf.h| $(OBJ_D)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	$(MAKE) clean -C libft
	rm -rf $(OBJ_D)

.PHONY: fclean
fclean: clean
	$(MAKE) fclean -C libft
	rm -f $(NAME)
	rm -f a.out

.PHONY: re
re: fclean all
	$(MAKE) all -C libft

# Create directories

$(OBJ_D):
	mkdir -p $(OBJ_D)
$(BIN_D):
	mkdir -p $(BIN_D)

# Custom command

.PHONY: debug
debug : $(OBJ)
	$(MAKE) re
	@$(CC) $(CFLAGS) -g3 $< libft/libft.a -o a.out