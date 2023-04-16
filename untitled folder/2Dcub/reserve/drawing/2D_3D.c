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

// void	up_right_rays(t_data *img , double *x)
// {
// 	double	ray1;
// 	double	ray2;

// 	ray1 = cast_rays1(img, img->map->view);
// 	ray2 = cast_rays2(img, img->map->view);
// 	if (ray2 && ray1 > ray2)
// 		dala(img,ray2,x,0x343a40);
// 	else
// 		dala(img,ray1,x,0x343a40);
// }

// void	up_left_rays(t_data *img , double *x)
// {
// 	double	ray3;
// 	double	ray4;

// 	ray4 = cast_rays4(img, img->map->view);
// 	ray3 = cast_rays3(img, img->map->view);
// 	if (ray3 && ray4 > ray3)
// 		dala(img,ray3,x,0x343a40);
// 	else
// 		dala(img,ray4,x,0x343a40);
// }

// void	down_right_rays(t_data *img , double *x)
// {
// 	double	ray2;
// 	double	ray6;

// 	ray6 = cast_rays6(img, img->map->view);
// 	ray2 = cast_rays2(img, img->map->view);
// 	if (ray2 && ray6 > ray2)
// 		dala(img,ray2,x,0x343a40);
// 	else
// 		dala(img,ray6,x,0x343a40);
// }

// void	down_left_rays(t_data *img , double *x)
// {
// 	double	ray3;
// 	double	ray5;

// 	ray5 = cast_rays5(img, img->map->view);
// 	ray3 = cast_rays3(img, img->map->view);
// 	if (ray3 && ray5 > ray3)
// 		dala(img,ray3,x,0x343a40);
// 	else
// 		dala(img,ray5,x,0x343a40);
// }