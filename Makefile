# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atweek <atweek@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/28 15:37:47 by atweek            #+#    #+#              #
#    Updated: 2021/03/30 13:28:29 by atweek           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

MAP = map/cub3d.cub

SRC = src/main3D.c src/parcer.c

SRCO = $(SRC:.c=.o)

FLAGS = -g  -Wall -Wextra -Werror

MAC_BUTTONS = -D W=13 -D S=1 -D D=2 -D A=0 -D LEFT=123 -D RIGHT=124

LINUX_BUTTONS = -D W=119 -D S=115 -D D=100 -D A=97 -D LEFT=65361 -D RIGHT=65363 -D ESC=65307

LIBFT = ./libft/libft.a

all: $(NAME)

%.o: %.c $(HEADER)
	gcc $(FLAGS) -c $< -o $@ 

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
