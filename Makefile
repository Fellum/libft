NAME = libft.a
SRCS = *.c
INCLUDES = .
OBJECTS = *.o

all: $(NAME)

$(NAME): $(SRCS)
	@gcc -c -Wall -Werror -Wextra $(SRCS)
	@ar rcs $(NAME) $(OBJECTS)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean $(NAME)

norm:
	@norminette $(SRCS) *.h