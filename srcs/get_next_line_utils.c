/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:09:14 by ldesnoye          #+#    #+#             */
/*   Updated: 2022/06/23 19:50:06 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	next_endl(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	gnl_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*append(char *buf, char *stock, int nb_read)
{
	int		lstock;
	char	*pcpy;
	int		i;
	int		j;

	i = -1;
	j = 0;
	pcpy = stock;
	lstock = gnl_strlen(pcpy);
	stock = malloc((lstock + nb_read + 1) * sizeof(char));
	if (!stock)
	{
		free(pcpy);
		return (0);
	}
	while (pcpy[++i])
		stock[i] = pcpy[i];
	free(pcpy);
	while (j <= nb_read)
	{
		stock[i + j] = buf[j];
		j++;
	}
	return (stock);
}

char	*gnl_strdup(char *s)
{
	char	*d;
	int		i;

	i = 0;
	d = malloc((gnl_strlen(s) + 1) * sizeof(char));
	if (!d)
		return (0);
	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = 0;
	return (d);
}

int	for_the_norme(char *stock)
{
	free(stock);
	return (-1);
}
