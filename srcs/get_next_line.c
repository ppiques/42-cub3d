/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:08:18 by ldesnoye          #+#    #+#             */
/*   Updated: 2022/06/23 19:49:17 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	if (BUFFER_SIZE < 1 || fd < 0 || !line)
		return (-1);
	return (main_get_next_line(fd, line));
}

int	evaluate(int next, int nb_read)
{
	if (next == -1 && nb_read == BUFFER_SIZE)
		return (1);
	else
		return (2);
}

char	*fill_stock(int c, char *stock, char *buf, int nb_read)
{
	if (c == 0)
		return (gnl_strdup(buf));
	else
		return (append(buf, stock, nb_read));
}

int	main_get_next_line(int fd, char **line)
{
	static char	*stock = 0;
	char		buf[BUFFER_SIZE + 1];
	int			next;
	int			nb_read;
	int			c;

	c = !(!stock);
	while (c != 2)
	{
		nb_read = read(fd, buf, BUFFER_SIZE);
		if (nb_read == -1)
			return (for_the_norme(stock));
		buf[nb_read] = 0;
		stock = fill_stock(c, stock, buf, nb_read);
		if (!stock)
			return (-1);
		next = next_endl(stock);
		c = evaluate(next, nb_read);
	}
	stock = almost_split(stock, line, next);
	if (!stock && next != -1)
		return (-1);
	c = !(next == -1);
	return (c);
}

char	*almost_split(char *stock, char **line, int next)
{
	int		i;
	char	*pcpy;

	if (next == -1)
	{
		*line = gnl_strdup(stock);
		free(stock);
		return (NULL);
	}
	i = -1;
	*line = malloc((next + 1) * sizeof(char));
	if (!(*line))
	{
		free(stock);
		return (0);
	}
	while (++i < next)
		(*line)[i] = stock[i];
	(*line)[next] = 0;
	pcpy = stock;
	stock = gnl_strdup(pcpy + next + 1);
	free(pcpy);
	return (stock);
}
