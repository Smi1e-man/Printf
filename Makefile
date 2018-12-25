NAME = libftprintf.a

SRC = pf_printf.c ft_put_n_char.c ft_putstr.c ft_putstr.c \
		pf_save_strct.c pf_types.c ft_strlen.c

OBJ = *.o

all: $(NAME)

$(NAME): $(SRC) 
		@gcc -c $(SRC)
		@ar rc $(NAME) $(OBJ)
		@gcc -g main.c $(NAME)
		./a.out

clean:
		@rm -rf $(OBJ)

fclean: clean
		@rm -f $(NAME)

re: fclean all