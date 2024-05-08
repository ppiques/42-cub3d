/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:50:13 by ldesnoye          #+#    #+#             */
/*   Updated: 2022/07/07 16:26:03 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubmain.h"

int	create_image(t_engine *engine)
{
	int			i;
	int			j;
	int			color;
	double		small_angle;
	t_player	*p;

	small_angle = M_PI * FOV / 360 / WIN_WIDTH;
	p = engine->player;
	j = 0;
	while (j < WIN_HEIGHT)
	{
		i = 0;
		while (i < WIN_WIDTH)
		{
			color = projection(p->screen_origin, engine);
			my_mlx_pixel_put(engine->buf_frame, i, j, color);
			vect_flat_rot(p->screen_origin, -small_angle);
			i++;
		}
		vect_flat_rot(p->screen_origin, small_angle * WIN_WIDTH);
		vect_rot(p->screen_origin, p->screen_rot_axis, small_angle);
		j++;
	}
	return (0);
}

int	show_frame(t_engine *engine)
{
	void	*japli;

	japli = engine->cur_frame->img;
	mlx_put_image_to_window(engine->mlx, engine->win, japli, 0, 0);
	return (0);
}

int	render_buf_frame(t_engine *engine)
{
	t_img	*swap;
	void	*japli;

	japli = engine->buf_frame->img;
	calc_origin(engine->player);
	create_image(engine);
	mlx_put_image_to_window(engine->mlx, engine->win, japli, 0, 0);
	swap = engine->cur_frame;
	engine->cur_frame = engine->buf_frame;
	engine->buf_frame = swap;
	return (0);
}
