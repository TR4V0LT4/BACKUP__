#include "../cub.h"
void draw(t_data *img , float ray)
{
	float y = img->map->y * 50;
	float x = img->map->x * 50;
	int i = (( ray ) * 50);
	while(i--) 
	{
		mlx_pixel_put(img->mlx,img->win, x, y, 0xfee440);
		y -= sin(img->map->angle);
		x += cos(img->map->angle);
 	}
}
double c1(t_data *img)
{	
	float	ry = 0;
	float 	rx = 0;
	int line = 0;
	float ray = 0;
	int next_x = 0;
	int next_y = 0;
	
	line = floor(img->map->y) ;
	ry = img->map->y - (float)line; 
	rx = (ry / tan(img->map->view))  ;
	ray =  (sqrt((pow(ry,2)+pow(rx,2))));	
	next_y = floor(img->map->y - ry );
	next_x = floor(img->map->x + rx );
	
if((next_y < ((img->height / 50)) && next_y > 0) && (next_x <= (img->width / 50 ) && next_x >= 0))
	if(img->map->map[next_y - 1  ][next_x ] == '1')
		return ray;

			while (TRUE)
			 {	
					ry += 1; 
					rx = fabs((fabs(ry) / tan(img->map->view)));
					next_x = floor(img->map->x + rx );
					next_y = floor(img->map->y - ry);
					ray =  sqrt((pow(ry,2) + pow(rx,2)));

					if((next_y < ((img->height / 50)) && next_y > 0) && (next_x <= (img->width / 50 ) && next_x >= 0))
					{

						if(img->map->map[next_y - 1  ][next_x ] == '1')
						{
							//printf("  x = %d \n", next_x);
							break;
						}
					}
					else
						break;
			 }
	return (ray);
}
double c2(t_data *img)
{
	float	ry = 0;
	float 	rx = 0;
	float ray = 0;
	int next_x = 0;
	int next_y = 0;	
	
	rx =   ceil(img->map->x) - img->map->x  ;
	ry = rx * tan( img->map->view); 
	ray =  (sqrt((pow(ry,2)+pow(rx,2))));	
	next_y = floor(img->map->y - ry );
	next_x = floor(img->map->x + rx ) ;

if((next_y < ((img->height / 50)) && next_y > 0) && (next_x <= (img->width / 50 ) && next_x >= 0))
	if(img->map->map[next_y ][next_x ] == '1')
		return ray;

	 	while(TRUE)
		{	
	 			rx +=  1;
				ry = rx * tan( img->map->view); 
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

double c3(t_data *img)
{
	float	ry = 0;
	float 	rx = 0;
	float ray = 0;
	int next_x = 0;
	int next_y = 0;	
	
	rx =  img->map->x - floor(img->map->x);
	ry = rx * tan(M_PI -  img->map->view);
	ray =  (sqrt((pow(ry,2)+pow(rx,2))));	
	next_y = floor(img->map->y - ry );
	next_x = floor(img->map->x - rx ) ;

	if((next_y < ((img->height / 50)) && next_y > 0) && (next_x <= (img->width / 50 ) && next_x >= 0))
	 	if(img->map->map[next_y ][next_x - 1 ] == '1')
	 		return ray;

	 	while(TRUE)
		{	
	 			rx +=  1;
				ry = rx * tan( M_PI  - img->map->view); 
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

double c4(t_data *img)
{	
	float	ry = 0;
	float 	rx = 0;
	int line = 0;
	float ray = 0;
	int next_x = 0;
	int next_y = 0;
	
	line = floor(img->map->y) ;
	ry = img->map->y - (float)line; 
	rx = (ry / tan(M_PI - img->map->view))  ;
	ray =  (sqrt((pow(ry,2)+pow(rx,2))));	
	next_y = floor(img->map->y - ry );
	next_x = floor(img->map->x - rx );
	
	if((next_y < ((img->height / 50)) && next_y > 0) && (next_x <= (img->width / 50 ) && next_x >= 0))
		if(img->map->map[next_y - 1  ][next_x ] == '1')
			return ray;

			while (TRUE)
			 {	
					ry += 1; 
					rx = fabs((fabs(ry) / tan(M_PI - img->map->view)));
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

double c5(t_data *img)
{	
	float	ry = 0;
	float 	rx = 0;
	int line = 0;
	float ray = 0;
	int next_x = 0;
	int next_y = 0;
	
	line = ceil(img->map->y) ;
	ry = (float)line -  img->map->y  ; 
	rx = (ry / tan(img->map->view - M_PI))  ;
	ray =  (sqrt((pow(ry,2)+pow(rx,2))));	
	next_y = floor(img->map->y + ry );
	next_x = floor(img->map->x - rx );
	
	if((next_y < ((img->height / 50)) && next_y > 0) && (next_x <= (img->width / 50 ) && next_x >= 0))
		if(img->map->map[next_y   ][next_x ] == '1')
			return ray;

			while (TRUE)
			 {				
					ry += 1; 
					rx = fabs((fabs(ry) / tan(M_PI - img->map->view)));
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

double c6(t_data *img)
{	
	float	ry = 0;
	float 	rx = 0;
	int line = 0;
	float ray = 0;
	int next_x = 0;
	int next_y = 0;
	
	line = ceil(img->map->y) ;
	ry = (float)line -  img->map->y  ; 
	rx = ry * tan( ((3 * M_PI) / 2) - img->map->view )  ;
	ray =  (sqrt((pow(ry,2)+pow(rx,2))));	
	next_y = floor(img->map->y + ry );
	next_x = floor(img->map->x - rx );
	
	if((next_y < ((img->height / 50)) && next_y > 0) && (next_x <= (img->width / 50 ) && next_x >= 0))
		if(img->map->map[next_y ][next_x ] == '1')
			return ray;

			while (TRUE)
			 {	
					ry += 1; 
					rx = (ry * tan( ((3 * M_PI) / 2) - img->map->view )) ;
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
void debug(t_data *img)
{
	double ray1 = 0;
	double ray2 = 0;
	double ray3 = 0;
	double ray4 = 0;
	double ray5 = 0;
	double ray6 = 0;
img->map->view = img->map->angle;
while(img->map->view <=  img->map->angle + (M_PI / 3)   )
{
	 if(img->map->angle >= 0 && img->map->angle <= (M_PI * 2))
	 { 	
		if(img->map->angle <= (M_PI / 2)+ 0.1)	
		{
		  	ray1 = c1(img);
		 	ray2 = c2(img);	
			if (ray2 && ray1 > ray2  )
		 		draw(img, ray2);
			else
	 			draw(img, ray1);
	 	}
		else if( img->map->angle > (M_PI / 2) && img->map->angle <= M_PI )	
		{
			ray4 = c4(img);
			ray3 = c3(img);	
			
			if (ray3 && ray4 > ray3  )
		  		draw(img, ray3);
			else
	 			draw(img, ray4);	
		 }
		 else if( img->map->angle > M_PI && img->map->angle <=  (( 3 * M_PI) / 2 ))	
		{
			ray5 = c5(img);
			ray3 = c3(img);	
			
			if (ray3 && ray5 > ray3  )
		  		draw(img, ray3);
			else
	 			draw(img, ray5);	
		 }
		 else if( img->map->angle >  (( 3 * M_PI) / 2 )  && img->map->angle <= M_PI * 2 )	
		{
			ray6 = c6(img);
			ray2 = c2(img);	
			
			if (ray2 && ray6 > ray2  )
		  		draw(img, ray2);
			else
	 			draw(img, ray6);	
		 }
	 }
	 img->map->view += ((M_PI / 3) /( img->width + 50 ));
	}
} 