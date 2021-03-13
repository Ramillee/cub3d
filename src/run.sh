#!/bin/bash

gcc -g main.c parcer.c ../libft/*.c  libmlx.dylib -framework OpenGL -framework Appkit && ./a.out map

echo "процесс запущен

