/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaadoun <yjaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:22:31 by yjaadoun          #+#    #+#             */
/*   Updated: 2023/04/17 02:44:46 by yjaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	check_empty_line(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[0] == '\n' || (map[i] == '\n' && map[i + 1] == '\n')
			|| (map[i] == '\n' && map[i + 1] == '\0'))
			exit_error("empty line in the map\n");
		i++;
	}
}

t_bool	check_top_bottom(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1' && line[i] != SPACE && line[i] != TAB)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_bool	check_border_left_and_right(char **map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		len = ft_strlen(map[i]);
		if ((map[i][0] != '1' && map[i][0] != SPACE && map[i][0] != TAB)
			|| (map[i][len - 1] != '1' && map[i][len - 1] != SPACE
			&& map[i][len - 1] != TAB))
			return (FALSE);
		i++;
	}
	return (TRUE);
}	

t_bool	check_border(t_map *map)
{
	int	len;

	len = doble_arr_len(map->map);
	if (!check_top_bottom(map->map[0])
		|| !check_top_bottom(map->map[len -1])
		|| !check_border_left_and_right(map->map)
		|| !is_map_valid(map))
		exit_error("ERROR : unclosed map\n");
	return (TRUE);
}

t_bool	check_elements(char **map)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (!ft_strchr("01NSEW \t", map[i][j]))
				exit_error("ERROR : wrong element\n");
			else if (ft_strchr("NSEW", map[i][j]))
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
		exit_error("ERROR : wrong element\n");
	return (TRUE);
}

float start_angle(char c)
{
	float	angle;

	angle = 0.0;
	if (c == 'S')
		angle = (3 * M_PI) / 2;
	else if (c == 'W')
		angle = M_PI;
	else if (c == 'N')
		angle = M_PI / 2;
	else if (c == 'E')
		angle = 2 * M_PI;
	return (angle);
}

void	player_position(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i] != NULL)
	{
		j = 0;
		while (map->map[i][j] != '\0')
		{
			if (ft_strchr("NSEW", map->map[i][j]))
			{
				map->x_player = j ;
				map->y_player = i ;
				map->angle = start_angle(map->map[i][j]);
				map->map[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}
