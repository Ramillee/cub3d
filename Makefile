NAME = cub3D

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Imlx -I.

SRC = main.c

# HEADER = src/ft_printf.h

OBJ = $(SRC:.c=.o)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	make -C libft/
	make -C gnl/
	ar rcs $(NAME) $(OBJ) libft/*.o
	$(CC) $(SRC) libmlx.dylib -framework OpenGL -framework Appkit -o $(NAME)
	# $(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	# gcc "твой файл" libmlx.dylib -framework OpenGL -framework Appkit

clean:
	rm -f $(OBJ)
	make clean -C libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C libft/
	make fclean -C gnl/

re: fclean all

norm:
	norminette $(SRC) $(HEADER) libft/

.PHONY: all clean fclean re norme