/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:34:36 by ppiques           #+#    #+#             */
/*   Updated: 2022/06/29 13:59:07 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubmain.h"

int	arg_number_check(int argc)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error\nInvalid number of arguments\n", 2);
		return (-1);
	}
	return (0);
}

int	check_arg_format(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (str[--i] != 'b')
		return (-1);
	if (str[--i] != 'u')
		return (-1);
	if (str[--i] != 'c')
		return (-1);
	if (str[--i] != '.')
		return (-1);
	return (0);
}

int	check_file(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (-1);
	close(fd);
	return (0);
}

/*
Function to check if args are valid, *str is argv[1]
*/

int	arg_check(int argc, char *str, t_engine *engine)
{
	if (arg_number_check(argc) == -1)
		free_engine(engine);
	if (check_arg_format(str) == -1)
	{
		ft_putstr_fd("Error\nFile not in .cub format\n", 2);
		free_engine(engine);
	}
	if (check_file(str) == -1)
	{
		ft_putstr_fd("Error\nFile is not valid\n", 2);
		free_engine(engine);
	}
	return (0);
}
