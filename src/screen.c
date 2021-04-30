#include "cub.h"

void	take_pix(t_all *all, int line, int *x, int y)
{
	char	save;
	int		a;

	a = 4;
	while (--a >= 0)
	{
		save = all->win->addr[*x + line * all->win->line_l];
		all->win->addr[*x + line * all->win->line_l]
			= all->win->addr[y - a + (line * all->win->line_l - 1)];
		all->win->addr[y - a + (line * all->win->line_l - 1)] = save;
		*x += 1;
	}
}

void	take_line(t_all *all)
{
	int		line;
	int		x;
	int		y;

	line = -1;
	while (++line < all->info->h)
	{
		x = 0;
		y = all->win->line_l;
		while (x < y)
		{
			take_pix(all, line, &x, y);
			y -= 4;
		}
	}
}

void	name_file(t_all *all, int fd)
{
	int		size;
	int		n;

	size = 40;
	n = 1;
	write(fd, &size, 4);
	write(fd, &all->info->w, 4);
	write(fd, &all->info->h, 4);
	write(fd, &n, 2);
	write(fd, &all->win->bpp, 2);
	write(fd, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 28);
}

void	screenshot(t_all *all)
{
	int		fd;
	int		size;
	int		i;
	int		a;

	fd = open("screenvs.bmp", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IROTH);
	if (fd < 0)
	{
		printf("failed to create file");
		exit(1);
	}
	size = 14 + 40 + all->info->w * all->info->h * 4;
	i = 14 + 40;
	write(fd, "BM", 2);
	write(fd, &size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &i, 4);
	name_file(all, fd);
	take_line(all);
	a = all->info->w * all->info->h;
	while (--a >= 0)
		write(fd, &all->win->addr[a * all->win->bpp / 8], 4);
	close(fd);
	exit(0);
}
