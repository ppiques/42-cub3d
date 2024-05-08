/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:49:48 by ppiques           #+#    #+#             */
/*   Updated: 2022/06/29 13:53:58 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubmain.h"

// Return 1 if c is a spawn character.
int	is_spawn_point(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	else
		return (0);
}

// Return 1 if c is a valid character for the map.
int	is_valid_char(char c)
{
	if (c == '0' || c == '1' || c == ' ' || is_spawn_point(c))
		return (1);
	else
		return (0);
}

// Return 1 if the char map[i][j] is surrounded by other tiles.
// This function is called only if map[i][j] is '0'.
int	is_surrounded(int i, int j, char **map)
{
	if (i == 0 || j == 0 || !map[i + 1] || !map[i][j + 1])
		return (0);
	if (map[i][j - 1] == ' ' || map[i][j + 1] == ' ')
		return (0);
	if ((int)ft_strlen(map[i - 1]) <= j || (int)ft_strlen(map[i + 1]) <= j)
		return (0);
	if (map[i - 1][j] == ' ' || map[i + 1][j] == ' ')
		return (0);
	return (1);
}
