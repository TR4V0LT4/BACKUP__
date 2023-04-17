/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colores.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaadoun <yjaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 01:22:16 by yjaadoun          #+#    #+#             */
/*   Updated: 2023/04/17 02:39:42 by yjaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	check_colors(char *str)
{
	char	**div;
	int		i;

	i = 0;
	if (!str)
		exit_error("ERROR : invalid color code1\n");
	div = ft_split1(str + 1, ',');
	while (div[i] != NULL)
	{	
		if (ft_atoi(div[i]) > 255)
			exit_error("ERROR : invalid color code2\n");
		i++;
	}
	if (i != 3)
		exit_error("ERROR : invalid color code N˚\n");
}

int	check_co(char *str)
{
	char	**div;
	int		color;
	int		i;

	i = 0;
	color = 0;
	if (!str)
		exit_error("ERROR : invalid color code1\n");
	div = ft_split1(str + 1, ',');
	while (div[i] != NULL)
	{	
		if (ft_atoi(div[i]) > 255)
			exit_error("ERROR : invalid color code2\n");
		i++;
	}
	if (i != 3)
		exit_error("ERROR : invalid color code N˚\n");
	else
		color = encode_rgb(ft_atoi(div[0]), ft_atoi(div[1]), ft_atoi(div[2]));
	return (color);
}
