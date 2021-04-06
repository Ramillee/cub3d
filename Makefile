# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atweek <atweek@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/28 15:37:47 by atweek            #+#    #+#              #
#    Updated: 2021/04/06 02:11:05 by atweek           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

MAP = map/cub3d.cub

SRC = src/main3D.c src/parcer.c src/paint_sprite.c src/hook.c src/paint.c src/rays.c src/init.c \
		src/free_all.c src/sort.c

SRCO = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror -g -O3

MAC_BUTTONS = -D W=13 -D S=1 -D D=2 -D A=0 -D LEFT=123 -D RIGHT=124 -D ESC=53

LINUX_BUTTONS = -D W=119 -D S=115 -D D=100 -D A=97 -D LEFT=65361 -D RIGHT=65363 -D ESC=65307 -O3

LIBFT = ./libft/libft.a

all: $(NAME)

%.o: %.c $(HEADER)
	gcc $(FLAGS) ${MAC_BUTTONS} -c $< -o $@ 

$(NAME) : $(SRCO) 
	rm -rf $(NAME)
	make -C ./libft
	make -C ./minilibx_mms_20200219
	cp ./minilibx_mms_20200219/libmlx.dylib ./
	gcc $(FLAGS) $(SRCO) libmlx.dylib -framework OpenGL -framework AppKit $(LIBFT) -o $(NAME)

run : all
	./$(NAME) $(MAP)

save : all	
	./$(NAME) $(MAP) --save

clean:
	rm -f $(SRCO)
	make clean -C ./libft 
	make clean -C ./minilibx_mms_20200219

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

linux:
	make -C ./mlx_linux
	make -C ./libft
	gcc ${LINUX_BUTTONS} ${SRC} ./mlx_linux/libmlx.a -Os -lX11 -lbsd -lm -lXext ${LIBFT} && ./a.out

re: fclean all

.PHONY: all clean fclean re run
