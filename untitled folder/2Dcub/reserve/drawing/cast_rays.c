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

void	up_right_rays(t_data *img)
{
	double	ray1;
	double	ray2;

	ray1 = cast_rays1(img, img->map->view);
	ray2 = cast_rays2(img, img->map->view);
	if (ray2 && ray1 > ray2)
		draw_rays(img, ray2, 0x00b4d8);
	else
		draw_rays(img, ray1, 0x00b4d8);
}

void	up_left_rays(t_data *img)
{
	double	ray3;
	double	ray4;

	ray4 = cast_rays4(img, img->map->view);
	ray3 = cast_rays3(img, img->map->view);
	if (ray3 && ray4 > ray3)
		draw_rays(img, ray3, 0xffd60a);
	else
		draw_rays(img, ray4, 0xffd60a);
}

void	down_right_rays(t_data *img)
{
	double	ray2;
	double	ray6;

	ray6 = cast_rays6(img, img->map->view);
	ray2 = cast_rays2(img, img->map->view);
	if (ray2 && ray6 > ray2)
		draw_rays(img, ray2, 0x80ed99);
	else
		draw_rays(img, ray6, 0x80ed99);
}

void	down_left_rays(t_data *img)
{
	double	ray3;
	double	ray5;

	ray5 = cast_rays5(img, img->map->view);
	ray3 = cast_rays3(img, img->map->view);
	if (ray3 && ray5 > ray3)
		draw_rays(img, ray3, 0xfb6107);
	else
		draw_rays(img, ray5, 0xfb6107);
}

void	right_side_angle(t_data *img)
{
	double	i;

	i = 0;
	while (i <= (M_PI / 6))
	{
		img->map->view = img->map->angle + i;
		if (img->map->view >= (2 * M_PI))
			img->map->view -= (2 * M_PI);
		if (img->map->view >= 0 && img->map->view <= (M_PI / 2))
			up_right_rays(img);
		else if (img->map->view > (M_PI / 2) && img->map->view < M_PI)
			up_left_rays(img);
		else if (img->map->view >= M_PI && img->map->view < ((3 * M_PI) / 2))
			down_left_rays(img);
		else if (img->map->view >= ((3 * M_PI) / 2)
			&& img->map->view <= M_PI * 2)
			down_right_rays(img);
		i += 0.005;
		
	}
}

void	left_side_angle(t_data *img)
{
	double	i;

	i = 0;
	while (i < (M_PI / 3))
	{
		img->map->view = img->map->angle - i;
		if (img->map->view >= (2 * M_PI))
			img->map->view -= (2 * M_PI);
		if(img->map->view < 0)
			img->map->view += (2 * M_PI);
		if (img->map->view >= 0 && img->map->view <= (M_PI / 2))
			up_right_rays(img);
		else if (img->map->view > (M_PI / 2) && img->map->view < M_PI)
			up_left_rays(img);
		else if (img->map->view >= M_PI && img->map->view < ((3 * M_PI) / 2))
			down_left_rays(img);
		else if (img->map->view >= ((3 * M_PI) / 2)
			&& img->map->view <= M_PI * 2)
			down_right_rays(img);
		i += 0.005;
	}
}

void	cast_rays(t_data *img)
{
	double	i = 0;

	
	while (i <  (M_PI / 3))
	{
		img->map->view = img->map->angle + i;
		if (img->map->view >= (2 * M_PI))
			img->map->view -= (2 * M_PI);
		if(img->map->view < 0)
			img->map->view += (2 * M_PI);
		if (img->map->view >= 0 && img->map->view <= (M_PI / 2))
			up_right_rays(img);
		else if (img->map->view > (M_PI / 2) && img->map->view < M_PI)
			up_left_rays(img);
		else if (img->map->view >= M_PI && img->map->view < ((3 * M_PI) / 2))
			down_left_rays(img);
		else if (img->map->view >= ((3 * M_PI) / 2)
			&& img->map->view <= M_PI * 2)
			down_right_rays(img);
		i += (M_PI / 3) / (img->width + 50);
	}
}
