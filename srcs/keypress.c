/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesnoye <ldesnoye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:38:18 by ldesnoye          #+#    #+#             */
/*   Updated: 2022/07/06 18:42:01 by ldesnoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubmain.h"

void	movement_key(int keycode, t_engine *engine)
{
	if (keycode == Z_KEY || keycode == W_KEY)
	{
		step_front(engine->player, engine);
		render_buf_frame(engine);
	}
	if (keycode == Q_KEY || keycode == A_KEY)
	{
		step_left(engine->player, engine);
		render_buf_frame(engine);
	}
	if (keycode == S_KEY)
	{
		step_back(engine->player, engine);
		render_buf_frame(engine);
	}
	if (keycode == D_KEY)
	{
		step_right(engine->player, engine);
		render_buf_frame(engine);
	}
}

void	rotation_key(int keycode, t_engine *engine)
{
	if (keycode == UP)
	{
		rot_up(engine->player);
		render_buf_frame(engine);
	}
	if (keycode == LEFT)
	{
		rot_left(engine->player);
		render_buf_frame(engine);
	}
	if (keycode == DOWN)
	{
		rot_down(engine->player);
		render_buf_frame(engine);
	}
	if (keycode == RIGHT)
	{
		rot_right(engine->player);
		render_buf_frame(engine);
	}
}

int	key_press(int keycode, t_engine *engine)
{
	rotation_key(keycode, engine);
	movement_key(keycode, engine);
	if (keycode == ESC)
		free_engine(engine);
	return (0);
}
