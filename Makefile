NAME = libftprintf.a

SRC = pf_printf.c ft_put_n_char.c ft_putstr.c ft_putstr.c \
		pf_save_strct.c pf_types_one.c pf_types_two.c ft_strlen.c \
		ft_strcat.c ft_strcpy.c ft_strjoin.c ft_strnew.c ft_memset.c \
		ft_strsub.c ft_strdup.c ft_itoa_base.c ft_toupper.c \
		pf_mods.c pf_type_f.c ft_strdup.c

OBJ = *.o

all: $(NAME)

$(NAME): $(SRC)
		@gcc -c $(SRC)
		@ar rc $(NAME) $(OBJ)

clean: $(OBJ)
		@rm -f $(OBJ)

fclean: clean
		@rm -f $(NAME)

re: fclean all