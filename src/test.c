#include <mlx.h>

int     main(void)
{
    void    *mlx;
    void    *img;
    char    *relative_path = "../img/colorstone.xpm";
    int     img_width;
    int     img_height;
    int conf_x = 1980 / img_width;
    int conf_y = 1080 / img_height;

    mlx = mlx_init();
    void *win = mlx_new_window(mlx,1980,1080,"Cub3D");
    img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
    mlx_put_image_to_window(mlx, win, img, 0, 0);
    mlx_loop(mlx);
}