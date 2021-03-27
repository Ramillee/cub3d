NAME = Cub3D

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I. -Os -g

SRC = src/main3D.c src/parcer.c

HEADER = src/cub.h

OBJ = $(SRC:.c=.o)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	make -C libft/
	gcc  {SRC} {CFLAGS} libft/libft.a libmlx.dylib -framework OpenGL -framework Appkit 

clean:
	rm -f $(OBJ)
	make clean -C libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C libft/

re: fclean all

norm:
	norminette $(SRC) $(HEADER) libft/

run:
	./{NAME}

.PHONY: all clean fclean re norme