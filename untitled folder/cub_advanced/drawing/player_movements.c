/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaadoun <yjaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 14:54:41 by yjaadoun          #+#    #+#             */
/*   Updated: 2023/04/13 15:31:13 by yjaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	move_player_w(t_data *img)
{
	float y = img->map->y;
	float x = img->map->x;
	img->map->y -= sin((img->map->angle - (M_PI / 6) )  ) / 10  ;
	img->map->x += cos((img->map->angle - (M_PI / 6)  ) ) / 10 ;
	if (img->map->map[(int)img->map->y][(int)img->map->x] == '1')
	{
		img->map->y = y;
		img->map->x = x;
	}
}

void	move_player_s(t_data *img)
{
	float y = img->map->y;
	float x = img->map->x;
	img->map->y += sin(img->map->angle - (M_PI / 6) ) / 10  ;
	img->map->x -= cos(img->map->angle - (M_PI / 6) ) / 10 ;
	
	if (img->map->map[(int)img->map->y][(int)img->map->x] == '1')
	{
		img->map->y = y;
		img->map->x = x;
	}
}

void	move_player_a(t_data *img)
{
	if (img->map->map[(int)(img->map->y)][(int)img->map->x - 1] != '1' ||
		(img->map->x - (int)img->map->x > 0.2))
	{
		mlx_put_image_to_window(img->mlx, img->win, img->shadow,
			(img->map->x * 50) - 5, (img->map->y * 50) - 5);
		img->map->y += sin(img->map->angle - (M_PI / 2)) / 10;
		img->map->x -= cos(img->map->angle - (M_PI / 2)) / 10;
	}
}

void	move_player_d(t_data *img)
{
	if (img->map->map[(int)(img->map->y)][(int)img->map->x + 1] != '1' ||
		(img->map->x - (int)img->map->x < 0.8))
	{
		mlx_put_image_to_window(img->mlx, img->win, img->shadow,
			(img->map->x * 50) - 5, (img->map->y * 50) - 5);
		img->map->y -= sin(img->map->angle - (M_PI / 2) ) / 10;
		img->map->x += cos(img->map->angle - (M_PI / 2)) / 10;
	}
}

void	turn_right(t_data *img)
{
	img->map->angle -= 0.1;
	if (img->map->angle < 0)
		img->map->angle += (2 * M_PI);
}

void	turn_left(t_data *img)
{
	img->map->angle += 0.1;
	if (img->map->angle > (2 * M_PI))
		img->map->angle -= (2 * M_PI);
	
}
