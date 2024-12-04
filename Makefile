NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror $(INCLUDES_D)

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
	mv libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

$(OBJ_D)%.o: $(SRC_D)%.c includes/ft_printf.h| $(OBJ_D)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJ)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all

# Create directories
$(OBJ_D):
	mkdir -p $(OBJ_D)
$(BIN_D):
	mkdir -p $(BIN_D)

# Custom command

.PHONY: debug
debug : $(OBJ)
	@$(CC) $(CFLAGS) -g $< libft/libft.a -o $(BIN_D)a.out

run : debug
	@./$(BIN_D)./a.out