/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesnoye <ldesnoye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:40:29 by ldesnoye          #+#    #+#             */
/*   Updated: 2022/07/06 18:47:45 by ldesnoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubmain.h"

void	step_front(t_player *player, t_engine *engine)
{
	double	norm;
	double	x_step;
	double	z_step;
	int		new_x;
	int		new_z;

	norm = vect_norm(player->angle->x, 0, player->angle->z);
	x_step = player->angle->x * player->mv_step / norm;
	z_step = player->angle->z * player->mv_step / norm;
	player->x += x_step;
	player->z += z_step;
	new_x = (int)floor(player->x);
	new_z = (int)floor(player->z);
	if (get_map_char(new_x, new_z, engine) != '0')
	{
		player->x -= x_step;
		player->z -= z_step;
	}
}

void	step_back(t_player *player, t_engine *engine)
{
	double	norm;
	double	x_step;
	double	z_step;
	int		new_x;
	int		new_z;

	norm = vect_norm(player->angle->x, 0, player->angle->z);
	x_step = player->angle->x * player->mv_step / norm;
	z_step = player->angle->z * player->mv_step / norm;
	player->x -= x_step;
	player->z -= z_step;
	new_x = (int)floor(player->x);
	new_z = (int)floor(player->z);
	if (get_map_char(new_x, new_z, engine) != '0')
	{
		player->x += x_step;
		player->z += z_step;
	}
}

void	step_right(t_player *player, t_engine *engine)
{
	double	norm;
	double	x_step;
	double	z_step;
	int		new_x;
	int		new_z;

	norm = vect_norm(player->angle->x, 0, player->angle->z);
	x_step = player->angle->x * player->mv_step / norm;
	z_step = player->angle->z * player->mv_step / norm;
	player->x += z_step;
	player->z -= x_step;
	new_x = (int)floor(player->x);
	new_z = (int)floor(player->z);
	if (get_map_char(new_x, new_z, engine) != '0')
	{
		player->x -= z_step;
		player->z += x_step;
	}
}

void	step_left(t_player *player, t_engine *engine)
{
	double	norm;
	double	x_step;
	double	z_step;
	int		new_x;
	int		new_z;

	norm = vect_norm(player->angle->x, 0, player->angle->z);
	x_step = player->angle->x * player->mv_step / norm;
	z_step = player->angle->z * player->mv_step / norm;
	player->x -= z_step;
	player->z += x_step;
	new_x = (int)floor(player->x);
	new_z = (int)floor(player->z);
	if (get_map_char(new_x, new_z, engine) != '0')
	{
		player->x += z_step;
		player->z -= x_step;
	}
}
