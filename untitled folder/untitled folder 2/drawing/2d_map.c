/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaadoun <yjaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:10:10 by yjaadoun          #+#    #+#             */
/*   Updated: 2023/04/13 14:17:32 by yjaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	draw_lines(t_data *img)
{
	float	x;
	float	y;

	x = 0;
	while (x < img->width)
	{
		y = 0;
		while (y < img->height)
			mlx_pixel_put(img->mlx, img->win, x, y++, 0xdee2e6);
		x += 50;
	}
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
			mlx_pixel_put(img->mlx, img->win, x++, y, 0xdee2e6);
		y += 50;
	}
	return (0);
}

int	draw_map(t_data *img)
{
		int	x;
	int	y;

	x = 0;
	while (x < img->map->len - 1)
	{
		y = 0;
		while (y < img->map->long_line)
		{
			if (img->map->map[x][y] == '1')
				mlx_put_image_to_window(img->mlx, img->win, img->wall,
					y * 50, x * 50);
			else
				mlx_put_image_to_window(img->mlx, img->win, img->shadow,
					y * 50, x * 50);
			y++;
		}
		x++;
	}
	draw_lines(img);
	mlx_put_image_to_window(img->mlx, img->win, img->player,
		(img->map->x * 50 - 5), (img->map->y * 50) - 5);
	// int	x;
	// int	y;

	// x = 0;
	// while (x < img->map->len - 1)
	// {
	// 	y = 0;
	// 	while (y < img->map->long_line)
	// 	{
	// 		if (img->map->map[x][y] == '1')
	// 			mlx_put_image_to_window(img->mlx, img->win, img->wall,
	// 				y * 10, x * 10);
	// 		else
	// 			mlx_put_image_to_window(img->mlx, img->win, img->shadow,
	// 				y * 10, x * 10);
	// 		y++;
	// 	}
	// 	x++;
	// }
	// my_mlx_pixel_put(img,img->map->x * 50 , img->map->y * 50  ,0xc1121f);
	// mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0); 
	// //		mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);	img->map->y, img->map->x);
	//mlx_pixel_put(img->mlx,img->win, img->map->x  , img->map->y , 0xc1121f);
	//draw_lines(img);
	//mlx_put_image_to_window(img->mlx, img->win, img->player,
	//	(x * 10), (y * 10) );
	return (0);
}

void dala(t_data *img , double ray, double *x, int color)
{
		//ray = ray * cos(img->map->angle - img->map->view);
		double distance = (img->width  / 2) * tan((M_PI / 3) / 2);
		
		//double wall_d = (ray * 50 ) * cos(img->map->angle); 
		double wall = round(distance/ray  ) ;
		double y = ((img->height  / 2 ) - (wall / 2)) ;
		//int i = (( ray ) * 5 ;
			
			while(y <= (img->height / 2) + (wall )) 
			{
				// mlx_pixel_put(img->mlx,img->win, *x, y, color);
				my_mlx_pixel_put(img,(*x),(int) y, color);
				y += 1;
 			}
	//mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
}
// void dala(t_data *img , double ray, double *s, int color)
// {
// 	(void)s;
// 	(void)color;
// 	(void)ray;
// 	int	x;
// 	int	y;

// 	x = 0;
// 	while (x < img->map->len - 1)
// 	{
// 		y = 0;
// 		while (y < img->map->long_line)
// 		{
// 			if (img->map->map[x][y] == '1')
// 				mlx_put_image_to_window(img->mlx, img->win, img->wall,
// 					y * 50, x * 50);
// 			else
// 				mlx_put_image_to_window(img->mlx, img->win, img->shadow,
// 					y * 50, x * 50);
// 			y++;
// 		}
// 		x++;
// 	}
// 	draw_lines(img);
// 	mlx_put_image_to_window(img->mlx, img->win, img->player,
// 		(img->map->x * 50 - 5), (img->map->y * 50) - 5);

// }
void draw_world(t_data *img)
{
	int i = 0;
	int j;
	int color = 0xade8f4;


		while(i < img->height )
		{	
			if(i > img->height / 2)
				color = 0x000000;

			j = 0;
			while(j < (img->width + 50) )
			{
				my_mlx_pixel_put(img,j, i, color);
				j++;
			}	
			i++;
		}

}
