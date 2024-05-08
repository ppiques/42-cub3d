/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:11:22 by ldesnoye          #+#    #+#             */
/*   Updated: 2022/06/29 13:53:12 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubmain.h"

void	path_copy(int i, char **path, char *trimmed)
{
	while (trimmed[i] == ' ')
		i++;
	if (*path)
		free(*path);
	*path = ft_strdup(trimmed + i);
}

int	path_finder(char *line, t_textures *textures)
{
	char	*trimmed;

	trimmed = ft_strtrim(line, " ");
	free(line);
	if (!trimmed)
		return (-1);
	if (!ft_strncmp(trimmed, "NO ", 3))
		path_copy(2, &textures->path_n, trimmed);
	else if (!ft_strncmp(trimmed, "SO ", 3))
		path_copy(2, &textures->path_s, trimmed);
	else if (!ft_strncmp(trimmed, "EA ", 3))
		path_copy(2, &textures->path_e, trimmed);
	else if (!ft_strncmp(trimmed, "WE ", 3))
		path_copy(2, &textures->path_w, trimmed);
	else if (!ft_strncmp(trimmed, "F ", 2))
		path_copy(1, &textures->str_f, trimmed);
	else if (!ft_strncmp(trimmed, "C ", 2))
		path_copy(1, &textures->str_c, trimmed);
	else
	{
		free(trimmed);
		return (1);
	}
	free(trimmed);
	return (0);
}
