/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaadoun <yjaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:13:40 by yjaadoun          #+#    #+#             */
/*   Updated: 2023/04/13 16:12:33 by yjaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void up_right_rays(t_data *img, double *x)
{
	double ray1;
	double ray2;
	ray1 = cast_rays1(img, img->map->view);
	ray2 = cast_rays2(img, img->map->view);
	if (ray2 && ray1 > ray2)
		dala(img, ray2, x, 0xFF6000);
	else
		dala(img, ray1, x, 0xFFA559);
}

void up_left_rays(t_data *img, double *x)
{
	double ray3;
	double ray4;
	ray4 = cast_rays4(img, img->map->view);
	ray3 = cast_rays3(img, img->map->view);
	if (ray3 && ray4 > ray3)
		dala(img, ray3, x, 0xFF6000);
	else
		dala(img, ray4, x, 0xFFA559);
}

void down_right_rays(t_data *img, double *x)
{
	double ray2;
	double ray6;
	ray6 = cast_rays6(img, img->map->view);
	ray2 = cast_rays2(img, img->map->view);
	if (ray2 && ray6 > ray2)
		dala(img, ray2, x, 0xFF6000);
	else
		dala(img, ray6, x, 0xFFA559);
}

void down_left_rays(t_data *img, double *x)
{
	double ray3;
	double ray5;
	ray5 = cast_rays5(img, img->map->view);
	ray3 = cast_rays3(img, img->map->view);
	if (ray3 && ray5 > ray3)
		dala(img, ray3, x, 0xFF6000);
	else
		dala(img, ray5, x, 0xFFA559);
}

void cast_rays(t_data *img)
{
	double i = 0;
	double x = 0;
	mlx_clear_window(img->mlx, img->win);
	// if(img->map->view >= (M_PI / 6))
		
	while (i < (M_PI / 3))
	{
		//printf("view = %f && angle = %f \n", img->map->view *( 180 / M_PI) , img->map->angle *( 180 / M_PI));
		
		img->map->view = img->map->angle  - i;
		if (img->map->view >= (2 * M_PI))
			img->map->view -= (2 * M_PI);
		if(img->map->view < 0 )
			img->map->view += 2 * M_PI;
		if (img->map->view >= 0 && img->map->view <= (M_PI / 2))
			up_right_rays(img, &x);
		else if (img->map->view > (M_PI / 2) && img->map->view < M_PI)
			up_left_rays(img, &x);
		else if (img->map->view >= M_PI && img->map->view < ((3 * M_PI) / 2))
			down_left_rays(img, &x);
		else if (img->map->view >= ((3 * M_PI) / 2) && img->map->view <= M_PI * 2)
			down_right_rays(img, &x);
		i += (M_PI / 3) / (1050);
		x += 1;
		img->map->i = i;
	}
	// img->map->view = save_angle;
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	// mini_map(img);
	// my_mlx_pixel_put(img,img->map->x  , img->map->y  ,0x9381ff);
	// mlx_pixel_put(img->mlx,img->win,img->map->x * 10, img->map->y*10,0x9381ff);
}