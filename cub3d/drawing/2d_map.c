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
	char *dst;

	if ((x >= 0 && x < 1050  ) && (y >= 0 && y <  1050))
	{
		//data->addr[y * 1050 +  x ] =  color; 
		//dst = (unsigned int *) (data->addr + y * 1050 + x* (data->bits_per_pixel / 8) );
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
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

void dala(t_data *img , double ray, double *x, int color, double r)
{
	//img->height = 750;
	//img->width = 750;
	// if ((int)img->map->view % 90 != 0)
		//ray = ray * cos(( img->map->angle - (img->map->view)));
		
		double distance = (1050 / 2 ) * tan(M_PI / 6);
		double wall = distance / ((ray ) ) ;
		 wall *= 2;
		double y = (1050  / 2 ) - (wall / 2) ;
		 

		// double i =  (img->map->x_next * 50) * ()  ;
			double i = (r) * (img->t.w);

		//printf(" =>>>>>>>>>>>>>>>>>>x = %f && r = %f \n" , i , r);
		// if(*x == 1000)
			// *x = 0;
		// printf("angle= %f && view = %f && diff  = %f i = %f \n", img->map->angle * (180 / M_PI) ,img->map->view * (180 / M_PI) , ( img->map->angle - (img->map->view)) * (180 / M_PI), (img->map->i) * (180 / M_PI));
			// double wall_d = round(ray   * cos( (img->map->i) ) ) ; 
		// ray *= cos(img->map->angle - (M_PI / 6));	
			
			//double j = 100;cc
			while(y < (1050 / 2) + (wall / 2 )  )
			{
			//	printf("x = %d && j = %f \n ", i , (y - (1050  / 2 ) + (wall / 2)) * (img->t.h / wall));	
				 double j = (y - (1050  / 2 ) + (wall / 2)) * (img->t.h / wall);
		 		//double j = wall * (img->t.h);	
				// printf(" j = %f\n" , j);
				img->t.addr = mlx_get_data_addr(img->t.img, &img->t.bits_per_pixel, &img->t.line_length, &img->t.endian);
				
				//char *dst = img->t.addr + (int)j * img->t.line_length + (int)i ;
				char *dst = img->t.addr + (int)j * img->t.line_length + (int)(i ) * (img->t.bits_per_pixel / 8)  ;
				
				//char *dst = img->t.addr[ y * l + x ]
				color = *(unsigned int*)dst;
				my_mlx_pixel_put(img,*x,y, color);
				y += 1;
				//j++;
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
	//img->height = 750;
	//img->width = 750;
	//printf(" %d %d\n", img->height , img->width);
	int i = 0;
	int j;
	int color = 0xade8f4;


		while(i < 1050 )
		{	
			if(i > 1050 / 2)
				color = 0x454545;

			j = 0;
			while(j < (1050 ) )
			{
				my_mlx_pixel_put(img,j, i, color);
				j++;
			}	
			i++;
		}

}
