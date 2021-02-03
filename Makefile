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
	# ar rcs $(NAME) $(OBJ) libft/*.o
	$(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C libft/

re: fclean all

norm:
	norminette $(SRC) $(HEADER) libft/

.PHONY: all clean fclean re norme