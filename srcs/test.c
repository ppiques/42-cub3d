/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesnoye <ldesnoye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:00:47 by ldesnoye          #+#    #+#             */
/*   Updated: 2022/07/06 16:39:30 by ldesnoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubmain.h"

void	perror_and_exit(char *s, t_engine *engine)
{
	ft_putstr_fd("Error\n", 2);
	perror(s);
	free_engine(engine);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	main(int ac, char **av)
{
	t_engine	*engine;
	int			fd;

	engine = new_engine();
	fd = open(av[1], O_RDONLY);
	arg_check(ac, av[1], engine);
	texture_parsing(fd, engine);
	engine->map_height = count_lines(fd);
	texture_checking(engine);
	map_reader(av[1], engine);
	map_reverser(engine);
	map_checker(engine->map, engine);
	player_reverser(engine->player);
	init_window(engine);
	render_buf_frame(engine);
	mlx_key_hook(engine->win, key_press, engine);
	mlx_loop_hook(engine->mlx, show_frame, engine);
	mlx_hook(engine->win, 17, 1L << 5, free_engine, engine);
	mlx_loop(engine->mlx);
}
