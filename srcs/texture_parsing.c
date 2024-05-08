/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:19:02 by ldesnoye          #+#    #+#             */
/*   Updated: 2022/06/29 13:53:31 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubmain.h"

char	*line_skip(int fd)
{
	int		i;
	char	*line;

	i = get_next_line(fd, &line);
	while (i == 1 && line[0] == 0)
	{
		free(line);
		i = get_next_line(fd, &line);
	}
	if (i == -1)
		return (NULL);
	return (line);
}

void	gnl_finish_fd(int fd)
{
	int		ret;
	char	*line;

	ret = 1;
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		free(line);
	}
	close(fd);
}

int	texture_parsing(int fd, t_engine *engine)
{
	int		i;
	int		error;
	char	*line;

	i = 0;
	while (i < 6)
	{
		line = line_skip(fd);
		if (!line)
			perror_and_exit(NULL, engine);
		error = path_finder(line, engine->textures);
		if (error == 1)
		{
			ft_putstr_fd("Error\nInvalid identifier\n", 2);
			gnl_finish_fd(fd);
			free_engine(engine);
		}
		i++;
	}
	return (0);
}
