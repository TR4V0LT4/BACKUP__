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

void	cast_rays(t_data *img)
{
	double	i = 0;
	double	x = 0;
	while (i <  (M_PI / 3))
	{
		img->map->view = img->map->angle + i;
		if (img->map->view >= (2 * M_PI))
			img->map->view -= (2 * M_PI);
		if(img->map->view < 0)
			img->map->view += (2 * M_PI);
		if (img->map->view >= 0 && img->map->view <= (M_PI / 2))
			up_right_rays(img );
		else if (img->map->view > (M_PI / 2) && img->map->view < M_PI)
			up_left_rays(img );
		else if (img->map->view >= M_PI && img->map->view < ((3 * M_PI) / 2))
			down_left_rays(img );
		else if (img->map->view >= ((3 * M_PI) / 2)
			&& img->map->view <= M_PI * 2)
			down_right_rays(img );
		i +=  (M_PI / 3) / (img->width + 50);
		x++;
	}
	//mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
}

double cast_rays1(t_data *img , float view)
{	
	float	ry = 0;
	float 	rx = 0;
	int line = 0;
	float ray = 0;
	int next_x = 0;
	int next_y = 0;
	
	line = floor(img->map->y) ;
	ry = img->map->y - line; 
	rx = (ry / tan(view))  ;
	ray = (sqrt((pow(ry, 2) + pow(rx, 2))));
	next_y = floor(img->map->y - ry);
	next_x = floor(img->map->x + rx);
	if((next_y < ((img->height / 50)) && next_y > 0) && (next_x <= (img->width / 50 ) && next_x >= 0))
		if(img->map->map[next_y - 1  ][next_x ] == '1')
			return (ray);
	while (TRUE)
	{	
		ry += 1; 
		rx = fabs((fabs(ry) / tan(view)));
		next_x = floor(img->map->x + rx );
		next_y = floor(img->map->y - ry);
		ray =  sqrt((pow(ry,2) + pow(rx,2)));
		if((next_y < ((img->height / 50)) && next_y > 0) && (next_x <= (img->width / 50 ) && next_x >= 0))
		{
			if(img->map->map[next_y - 1][next_x] == '1')
				break;		
		}
		else
			break;
	}
	return (ray);
}

double cast_rays2(t_data *img , float view)
{
	float	ry = 0;
	float 	rx = 0;
	float ray = 0;
	int next_x = 0;
	int next_y = 0;	
	
	rx =   ceil(img->map->x) - img->map->x  ;
	ry = rx * tan( view); 
	ray =  (sqrt((pow(ry,2)+pow(rx,2))));	
	next_y = floor(img->map->y - ry );
	next_x = floor(img->map->x + rx ) ;

if((next_y < ((img->height / 50)) && next_y > 0) && (next_x <= (img->width / 50 ) && next_x >= 0))
	if(img->map->map[next_y ][next_x ] == '1')
		return ray;

	 	while(TRUE)
		{	
	 			rx +=  1;
				ry = rx * tan( view); 
				if(ry > img->map->y)
					ry = img->map->y;
				ray =  (sqrt((pow(ry,2)+pow(rx,2))));	
				next_y = floor(img->map->y - ry );
				next_x = floor(img->map->x + rx ) ;
				if((next_y < ((img->height / 50)) && next_y > 0) && (next_x <= (img->width / 50 ) && next_x >= 0))
				{
					if(img->map->map[next_y ][next_x ] == '1')
						break;		
				}
				else
					break;
		} 		
	return (ray);
}

double cast_rays3(t_data *img, float view)
{
	float	ry = 0;
	float 	rx = 0;
	float ray = 0;
	int next_x = 0;
	int next_y = 0;	
	
	rx =  img->map->x - floor(img->map->x);
	ry = rx * tan(M_PI -  view);
	ray =  (sqrt((pow(ry,2)+pow(rx,2))));	
	next_y = floor(img->map->y - ry );
	next_x = floor(img->map->x - rx ) ;

	if((next_y < ((img->height / 50)) && next_y > 0) && (next_x <= (img->width / 50 ) && next_x >= 0))
	 	if(img->map->map[next_y ][next_x - 1 ] == '1')
	 		return ray;
	 	while(TRUE)
		{	
	 			rx +=  1;
				ry = rx * tan( M_PI  - view); 
				ray =  (sqrt((pow(ry,2)+pow(rx,2))));	
				next_y = floor(img->map->y - ry );
				next_x = floor(img->map->x - rx ) ;
				if((next_y < ((img->height / 50)) && next_y > 0) && (next_x <= (img->width / 50 ) && next_x >= 0))
				{
					if(img->map->map[next_y ][next_x -  1] == '1')
						break;		
				}
				else
					break;
		} 		
	return (ray);
}

double cast_rays4(t_data *img, float view)
{	
	float	ry = 0;
	float 	rx = 0;
	int line = 0;
	float ray = 0;
	int next_x = 0;
	int next_y = 0;
	
	line = floor(img->map->y) ;
	ry = img->map->y - (float)line; 
	rx = (ry / tan(M_PI - view))  ;
	ray =  (sqrt((pow(ry,2)+pow(rx,2))));	
	next_y = floor(img->map->y - ry );
	next_x = floor(img->map->x - rx );
	
	if((next_y < ((img->height / 50)) && next_y > 0) && (next_x <= (img->width / 50 ) && next_x >= 0))
		if(img->map->map[next_y - 1  ][next_x ] == '1')
			return ray;

			while (TRUE)
			 {	
					ry += 1; 
					rx = fabs((fabs(ry) / tan(M_PI - view)));
					next_x = floor(img->map->x - rx );
					next_y = floor(img->map->y - ry);
					ray =  sqrt((pow(ry,2) + pow(rx,2)));

					if((next_y < ((img->height / 50)) && next_y > 0) && (next_x <= (img->width / 50 ) && next_x >= 0))
					{
						if(img->map->map[next_y - 1  ][next_x ] == '1')
							break;		
					}
					else
						break;	
			 }
	return (ray);
}

double cast_rays5(t_data *img, float view)
{	
	float	ry = 0;
	float 	rx = 0;
	int line = 0;
	float ray = 0;
	int next_x = 0;
	int next_y = 0;
	
	line = ceil(img->map->y) ;
	ry = (float)line -  img->map->y  ; 
	rx = (ry / tan(view - M_PI))  ;
	ray =  (sqrt((pow(ry,2)+pow(rx,2))));	
	next_y = floor(img->map->y + ry );
	next_x = floor(img->map->x - rx );
	
	if((next_y < ((img->height / 50)) && next_y > 0) && (next_x <= (img->width / 50 ) && next_x >= 0))
		if(img->map->map[next_y   ][next_x ] == '1')
			return ray;

			while (TRUE)
			 {				
					ry += 1; 
					rx = fabs((fabs(ry) / tan(M_PI - view)));
					next_x = floor(img->map->x - rx );
					next_y = floor(img->map->y + ry);
					ray =  sqrt((pow(ry,2) + pow(rx,2)));

					if((next_y < ((img->height / 50)) && next_y > 0) && (next_x <= (img->width / 50 ) && next_x >= 0))
					{
						if(img->map->map[next_y   ][next_x ] == '1')
							break;		
					}
					else
						break;
			 }
	return (ray);
}

double cast_rays6(t_data *img, float view)
{	
	float	ry = 0;
	float 	rx = 0;
	int line = 0;
	float ray = 0;
	int next_x = 0;
	int next_y = 0;
	
	line = ceil(img->map->y) ;
	ry = (float)line -  img->map->y  ; 
	rx = ry * tan( ((3 * M_PI) / 2) - view )  ;
	ray =  (sqrt((pow(ry,2)+pow(rx,2))));	
	next_y = floor(img->map->y + ry );
	next_x = floor(img->map->x - rx );
	if((next_y < ((img->height / 50)) && next_y > 0) && (next_x <= (img->width / 50 ) && next_x >= 0))
		if(img->map->map[next_y ][next_x ] == '1')
			return ray;

			while (TRUE)
			 {	
					ry += 1; 
					rx = (ry * tan( ((3 * M_PI) / 2) - view )) ;
					next_x = floor(img->map->x - rx );
					next_y = floor(img->map->y + ry);
					ray =  sqrt((pow(ry,2) + pow(rx,2)));

					if((next_y < ((img->height / 50)) && next_y > 0) && (next_x <= (img->width / 50 ) && next_x >= 0))
					{
						if(img->map->map[next_y   ][next_x  ] == '1')
							break;		
					}
					else
						break;
			 }
	return (ray);
}


