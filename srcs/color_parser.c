/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesnoye <ldesnoye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:08:16 by ldesnoye          #+#    #+#             */
/*   Updated: 2022/07/06 15:05:22 by ldesnoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubmain.h"

int	lazy_atoi(char *s, char color)
{
	int	tot;

	tot = -1;
	if (s[0] == '0')
	{
		tot = 0;
		while (*s == '0')
			s++;
	}
	if (tot == 0 && !ft_isdigit(s[0]))
		tot = 0;
	else if (!ft_isdigit(s[0]))
		tot = -1;
	else if (!ft_isdigit(s[1]))
		tot = s[0] - '0';
	else if (!ft_isdigit(s[2]))
		tot = (s[0] - '0') * 10 + s[1] - '0';
	else if (s[3] == ',' || color == 'b')
		tot = (s[0] - '0') * 100 + (s[1] - '0') * 10 + s[2] - '0';
	else
		tot = -1;
	if (tot > 255)
		tot = -1;
	return (tot);
}

int	str_skip(char *str)
{
	int	i;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	return (i);
}

int	only_spaces_left(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

unsigned int	create_color(int r, int g, int b)
{
	unsigned int	color;

	color = (r << 16) + (g << 8) + b;
	return (color);
}

unsigned int	color_parser(char *str, t_engine *engine, char *id)
{
	int	r;
	int	g;
	int	b;

	r = lazy_atoi(str, 'r');
	str += str_skip(str) + 1;
	g = lazy_atoi(str, 'g');
	str += str_skip(str) + 1;
	b = lazy_atoi(str, 'b');
	str += str_skip(str);
	if (r == -1 || g == -1 || b == -1 || !only_spaces_left(str))
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(id, 2);
		ft_putstr_fd(": invalid color format\n", 2);
		free_engine(engine);
	}
	return (create_color(r, g, b));
}
