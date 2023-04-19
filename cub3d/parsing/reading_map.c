/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjaadoun <yjaadoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:57:36 by yjaadoun          #+#    #+#             */
/*   Updated: 2023/04/17 02:57:52 by yjaadoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	**get_map(char *av)
{
	char	*buf;
	char	*current;
	char	**line;
	int		fd;
	t_bool	n;

	fd = open(av, O_RDWR);
	if (fd < 0)
		exit_error("ERROR : no such file\n");
	buf = 0;
	n = FALSE;
	current = get_next_line(fd);
	while (current)
	{
		if (current[skip_spaces_begin(current)] == '1')
			n = TRUE;
		if (n && current[skip_spaces_begin(current)] == '\n')
			exit_error("ERROR : map not valid");
		buf = ft_strjoin(buf, current);
		current = get_next_line(fd);
	}
	line = ft_split(buf, '\n');
	if (!line)
		exit_error("ERROR : Empty file\n");
	return (line);
}
