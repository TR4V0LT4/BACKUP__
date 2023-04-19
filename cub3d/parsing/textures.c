/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaadoun <yjaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 00:21:48 by yjaadoun          #+#    #+#             */
/*   Updated: 2023/04/16 17:46:54 by yjaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

t_bool	check_path(char *av, t_bool a)
{
	int		i;
	char	*extension;

	i = 0;
	if (a)
		extension = ft_strnstr(av, ".cub", ft_strlen(av));
	else
		extension = ft_strnstr(av, ".xpm", ft_strlen(av));
	if (extension && ft_strlen(extension) == 4)
		return (TRUE);
	else
		return (FALSE);
}

char	*check_textures(char *path)
{
	char	**str;

	str = ft_split(path, ' ');
	if (str[1] && !check_path(str[1], FALSE))
		exit_error("ERROR : PATH must be *.xpm\n");
	else
		return (str[1]);
	return (str[1]);
}
