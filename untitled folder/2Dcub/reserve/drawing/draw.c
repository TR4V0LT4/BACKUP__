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
	return (0);
}

void dala(t_data *img , double ray, double *x, int color)
{
		double distance = (img->height  / 2) * tan(M_PI  / 3);
		//double wall_d = (ray * 50 ) * cos(img->map->angle); 
		double wall = round((distance * 50) / (ray * 50 )) ;
		
		double y = (img->height  / 2 ) - (wall / 2) ;
	
		//int i = (( ray ) * 5 ;
			
			while(y <= (img->height / 2) + (wall / 2)) 
			{
				 //mlx_pixel_put(img->mlx,img->win, *x, y, color);
				my_mlx_pixel_put(img,*x, y, color);
				y += 1;
 			}
	//mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
}

void	draw_rays(t_data *img, float ray,int color)
{
	double	x;
	double	y;
	int		i;

	y = img->map->y * 50;
	x = img->map->x * 50;
	i = (( ray ) * 50);
	while(i--) 
	{
		mlx_pixel_put(img->mlx,img->win, x, y, color);
		y -= sin(img->map->view);
		x += cos(img->map->view);
 	}
}