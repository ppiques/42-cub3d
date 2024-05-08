/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesnoye <ldesnoye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:01:21 by ldesnoye          #+#    #+#             */
/*   Updated: 2022/07/06 15:36:41 by ldesnoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubmain.h"

int	map_setup(int fd, t_engine *engine)
{
	int	ret;
	int	i;

	ret = 1;
	engine->map = ft_calloc(engine->map_height + 1, sizeof(char *));
	if (engine->map)
		*engine->map = line_skip(fd);
	if (!engine->map || !*engine->map)
	{
		gnl_finish_fd(fd);
		free_engine(engine);
	}
	i = 1;
	while (ret == 1)
	{
		ret = get_next_line(fd, engine->map + i);
		i++;
	}
	close(fd);
	if (ret == -1)
		perror_and_exit(NULL, engine);
	return (0);
}

int	count_lines(int fd)
{
	int		ret;
	int		i;
	char	*line;

	line = line_skip(fd);
	ret = (line != NULL);
	free(line);
	i = 1;
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		free(line);
		i++;
	}
	close(fd);
	if (ret == -1)
		return (-1);
	return (i);
}

int	map_reader(char *filename, t_engine *engine)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	i = 0;
	while (i < 6)
	{
		line = line_skip(fd);
		if (!line)
			perror_and_exit(NULL, engine);
		free(line);
		i++;
	}
	if (map_setup(fd, engine))
		return (-1);
	return (0);
}
