NAME = libftprintf.a

SRC = printf.c ft_put_n_char.c ft_putstr.c ft_print_str.c

OBJ = *.o

all: $(NAME)

$(NAME): $(SRC)
		@gcc -c $(SRC)
		@ar rc $(NAME) $(OBJ)
		@gcc -g $(NAME)
		./a.out

clean: $(OBJ)
		@rm $(OBJ)

fclean: clean
		@rm -rf $(NAME)

re: fclean all