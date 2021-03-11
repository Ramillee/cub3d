#!/bin/bash

gcc -o cub3D -g -Wall -Wextra -Werror *.c ../libft/*.c libmlx.dylib -framework OpenGL -framework Appkit

echo "процесс запущен