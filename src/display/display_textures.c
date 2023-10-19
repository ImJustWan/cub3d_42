#include "display.h"

int	load_texture(t_world *world, t_img *img, char *path, int i)
{
	int	x;
	int	y;
	int	color;

	img->img_ptr = mlx_xpm_file_to_image(world->mlx_ptr, \
		path, &img->width, &img->height);
	img->addr = (int *)mlx_get_data_addr(img->img_ptr, \
		&img->bpp, &img->line_len, &img->endian);
	y = -1;
	while (++y < img->height)
	{
		x = -1;
		while (++x < img->width)
		{
			color = img->addr[img->width * y + x];
			world->texture[i][img->width * y + x] = color;
		}
	}
	return (0);
}

int	get_texture(t_world *world, int i)
{
	char	*file;
	t_img	img;

	file = NULL;
	if (i == 0)
		load_texture(world, &img, "x_north.xpm", i);
	if (i == 1)
		load_texture(world, &img, "x_south.xpm", i);
	if (i == 2)
		load_texture(world, &img, "x_east.xpm", i);
	if (i == 3)
		load_texture(world, &img, "x_west.xpm", i);
	mlx_destroy_image(world->mlx_ptr, img.img_ptr);
	return (0);
}

int	init_textures(t_world *world, int **texture)
{
	int		i;

	(void)texture;
	i = -1;
	while (++i < 4)
		get_texture(world, i);
	return (0);
}