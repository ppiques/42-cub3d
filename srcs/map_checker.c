/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesnoye <ldesnoye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 19:13:45 by ldesnoye          #+#    #+#             */
/*   Updated: 2022/07/06 15:19:30 by ldesnoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubmain.h"

// Return 1 if there is an invalid char in the map.
int	invalid_char_checker(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!is_valid_char(map[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

// Return 1 if there is a single spawn position.
int	spawn_checker(char **map, t_engine *engine)
{
	int	i;
	int	j;
	int	spawn;

	i = 0;
	spawn = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_spawn_point(map[i][j]))
			{
				if (spawn == 0)
					player_init_pos(engine, i, j, map[i][j]);
				map[i][j] = '0';
				spawn++;
			}
			j++;
		}
		i++;
	}
	return (spawn == 1);
}

// Return 1 if the map isn't surrounded by walls.
int	wall_checker(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' && !is_surrounded(i, j, map))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	map_checker(char **map, t_engine *engine)
{
	if (engine->map_height == 0)
	{
		ft_putstr_fd("Error\nMap is empty fdp\n", 2);
		free_engine(engine);
	}
	if (invalid_char_checker(map))
	{
		ft_putstr_fd("Error\nInvalid character in map\n", 2);
		free_engine(engine);
	}
	if (!spawn_checker(map, engine))
	{
		ft_putstr_fd("Error\nMap must have one single spawn point\n", 2);
		free_engine(engine);
	}
	if (wall_checker(map))
	{
		ft_putstr_fd("Error\nMap must be surrounded by walls\n", 2);
		free_engine(engine);
	}
	return (0);
}
