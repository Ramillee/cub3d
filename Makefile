# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atweek <atweek@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/28 15:37:47 by atweek            #+#    #+#              #
#    Updated: 2021/03/28 20:00:47 by atweek           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

MAP = map/cub3d.cub

SRC = src/main3D.c src/parcer.c

SRCO = $(SRC:.c=.o)

FLAGS = -g  -Wall -Wextra -Werror

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

re: fclean all

.PHONY: all clean fclean re
