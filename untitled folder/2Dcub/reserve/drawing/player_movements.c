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
int	move_player(int keycode, t_data *img)
{
	if (keycode == W_KEY)
		move_player_w(img);
	if (keycode == A_KEY)
		move_player_a(img);
	if (keycode == D_KEY)
		move_player_d(img);
	if (keycode == S_KEY)
		move_player_s(img);
	if (keycode == ESC_KEY)
		close_window(img);
	if (keycode == 124)
		turn_right(img);
	if (keycode == 123)
		turn_left(img);
	draw_map(img);
	cast_rays(img);
	return (0);
}
void	move_player_w(t_data *img)
{
	float	x;
	float	y;
	// if ((img->map->map[(int)(img->map->y  - 0.3 )][(int)(img->map->x - 0.3 )] != '1' && img->map->map[(int)(img->map->y  + 0.3 )][(int)(img->map->x + 0.3 )] != '1') ) //  || (img->map->y - (int)img->map->y > 0.2))
	// {
	// 	printf("x = %f &&  y = %f \n", img->map->x, img->map->y);
	// 	mlx_put_image_to_window(img->mlx, img->win, img->shadow,(img->map->x * 50) - 5 , (img->map->y * 50) - 5 );
	// 	img->map->y -= sin(img->map->angle + (M_PI /6) ) / 5  ;
	// 	img->map->x += cos(img->map->angle + (M_PI /6)) / 5 ;
	// }
	y = img->map->y;
	x = img->map->x;
	img->map->y -= sin(img->map->angle + (M_PI /6) ) / 5  ;
	img->map->x += cos(img->map->angle + (M_PI /6)) / 5 ;
	if (img->map->map[(int)img->map->y][(int)img->map->x] == '1')
	{
		img->map->y = y;
		img->map->x = x;
	}
}

void	move_player_s(t_data *img)
{
	float	x;
	float	y;
	// if ((img->map->map[(int)(img->map->y  - 0.2 )][(int)(img->map->x - 0.2 )] != '1' && img->map->map[(int)(img->map->y  + 0.2 )][(int)(img->map->x + 0.2 )] != '1') )
	// 	{
	// 		mlx_put_image_to_window(img->mlx, img->win, img->shadow,
	// 			(img->map->x * 50) - 5, (img->map->y * 50) - 5);
	// 		img->map->y += sin(img->map->angle + (M_PI /6)) / 5;
	// 		img->map->x -= cos(img->map->angle + (M_PI /6)) / 5;
	// 	}
	y = img->map->y;
	x = img->map->x;
	img->map->y += sin(img->map->angle + (M_PI /6) ) / 5  ;
	img->map->x -= cos(img->map->angle + (M_PI /6)) / 5 ;
	
	if (img->map->map[(int)img->map->y][(int)img->map->x] == '1')
	{
		img->map->y = y;
		img->map->x = x;
	}
}

void	move_player_a(t_data *img)
{
		mlx_put_image_to_window(img->mlx, img->win, img->shadow,
			(img->map->x * 50) - 5, (img->map->y * 50) - 5);
		img->map->y += sin(img->map->angle - (M_PI / 2 - (M_PI / 6))) / 5;
		img->map->x -= cos(img->map->angle - (M_PI / 2 - (M_PI / 6))) / 5;
}
void	move_player_d(t_data *img)
{
		mlx_put_image_to_window(img->mlx, img->win, img->shadow,
			(img->map->x * 50) - 5, (img->map->y * 50) - 5);
		img->map->y -= sin(img->map->angle - (M_PI / 2 - (M_PI / 6))) / 5;
		img->map->x += cos(img->map->angle - (M_PI / 2 - (M_PI / 6))) / 5;
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
