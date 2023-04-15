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
	
	// && img->map->y + 1 < (((img->height - 1) / 50) - 0.5))
	// if (img->map->map[(int)(img->map->y - 1)][(int)img->map->x] != '1' ||
	// 	(img->map->y - (int)img->map->y > 0.5))
	printf("y = %f && height = %f \n", img->map->y, (((img->height - 1) / 50) - 0.5)) ;
	printf("angle = %f\n" , (img->map->angle +(M_PI / 6)) * ( 180 / (M_PI)));
	if(img->map->y < img->height / 100)
	{
		if(img->map->y >= 1.5  || (img->map->angle >= (M_PI - (M_PI /6))))
		{
			mlx_put_image_to_window(img->mlx, img->win, img->shadow,
				(img->map->x * 50) - 5, (img->map->y * 50) - 5);
			img->map->y -= sin(img->map->angle + (M_PI /6)) / 10;
			img->map->x += cos(img->map->angle + (M_PI /6)) / 10;
		}
	}
	else if( (img->map->y  < (((img->height - 1) / 50) - 0.5))  || (((img->map->angle + (M_PI /6)) >= 0) && (img->map->angle + (M_PI /6) <= (M_PI )  )))
	{
		mlx_put_image_to_window(img->mlx, img->win, img->shadow,
				(img->map->x * 50) - 5, (img->map->y * 50) - 5);
			img->map->y -= sin(img->map->angle + (M_PI /6)) / 10;
			img->map->x += cos(img->map->angle + (M_PI /6)) / 10;
	}
}

void	move_player_s(t_data *img)
{
	printf("img->height %d\n", img->height);
	// if (img->map->map[(int)(img->map->y + 1)][(int)img->map->x] != '1' 
	// || img->map->map[(int)(img->map->y )][(int)img->map->x - 1] != '1'
	//  ||(img->map->y - (int)img->map->y < 0.5))
	if(img->map->y < img->height  / 100)
	{
		if(img->map->y >= 1.5  || (img->map->angle <= (M_PI - (M_PI /6))))
		{
			mlx_put_image_to_window(img->mlx, img->win, img->shadow,
				(img->map->x * 50) - 5, (img->map->y * 50) - 5);
			img->map->y += sin(img->map->angle + (M_PI /6)) / 10;
			img->map->x -= cos(img->map->angle + (M_PI /6)) / 10;
		}
	}
	else 
	{
		if(img->map->y <=  (img->height / 50) - 1.5  || (img->map->angle >= (M_PI - (M_PI /6))))
		{
			mlx_put_image_to_window(img->mlx, img->win, img->shadow,
				(img->map->x * 50) - 5, (img->map->y * 50) - 5);
			img->map->y += sin(img->map->angle + (M_PI /6)) / 10;
			img->map->x = cos(img->map->angle + (M_PI /6)) / 10;
		}
	}
}

void	move_player_a(t_data *img)
{
	//if (img->map->map[(int)(img->map->y)][(int)img->map->x - 1] != '1' ||
	//	(img->map->x - (int)img->map->x > 0.5))
	if(img->map->y > 1.5 && (img->map->angle >= 0 &&  img->map->angle <= (M_PI)) )
	{
		mlx_put_image_to_window(img->mlx, img->win, img->shadow,
			(img->map->x * 50) - 5, (img->map->y * 50) - 5);
		img->map->y += sin(img->map->angle - (M_PI / 2 - (M_PI / 6))) / 10;
		img->map->x -= cos(img->map->angle - (M_PI / 2 - (M_PI / 6))) / 10;
		// draw_map(img);
		// cast_rays(img);
	}
}

void	move_player_d(t_data *img)
{
	if (img->map->map[(int)(img->map->y)][(int)img->map->x + 1] != '1' ||
		(img->map->x - (int)img->map->x < 0.5))
	{
		mlx_put_image_to_window(img->mlx, img->win, img->shadow,
			(img->map->x * 50) - 5, (img->map->y * 50) - 5);
		img->map->y -= sin(img->map->angle - (M_PI / 2 - (M_PI / 6))) / 10;
		img->map->x += cos(img->map->angle - (M_PI / 2 - (M_PI / 6))) / 10;
		// draw_map(img);
		// cast_rays(img);
	}
}

void	turn_right(t_data *img)
{
	img->map->angle -= 0.1;
	if (img->map->angle < 0)
		img->map->angle += (2 * M_PI);
	// draw_map(img);
	// cast_rays(img);
}

void	turn_left(t_data *img)
{
	img->map->angle += 0.1;
	if (img->map->angle > (2 * M_PI))
		img->map->angle -= (2 * M_PI);
	// draw_map(img);
	// cast_rays(img);
}
