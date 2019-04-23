NAME = libft.a
SRC_DIR = ./srcs
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ_DIR = ./objs
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))
INCLUDES = includes

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@gcc -Wall -Werror -Wextra -I $(INCLUDES) -o $@ -c $<

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_DIR) $(OBJ)
	@ar rcs $(NAME) $(OBJ)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean $(NAME)

norm:
	@norminette $(SRC) $(INCLUDES)
