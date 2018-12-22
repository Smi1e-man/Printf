NAME = libftprintf.a

SRC = printf.c ft_put_n_char.c ft_putstr.c ft_print_str.c

OBJ = *.o

all: $(NAME)

$(NAME): $(SRC) 
		@gcc -c $(SRC)
		@ar rc $(NAME) $(OBJ)
		@gcc -g main.c $(NAME)
		./a.out

clean: $(OBJ)
		@rm -rf $(OBJ)

fclean: clean
		@rm -f $(NAME)

re: fclean all