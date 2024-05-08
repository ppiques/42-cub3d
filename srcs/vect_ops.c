/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesnoye <ldesnoye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:44:31 by ldesnoye          #+#    #+#             */
/*   Updated: 2022/06/24 04:52:07 by ldesnoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubmain.h"

double	vect_norm(double x, double y, double z)
{
	return (sqrt(x * x + y * y + z * z));
}

void	calc_origin(t_player *player)
{
	t_vect	*origin;
	t_vect	*rot_axis;
	double	rot_fov;

	origin = player->screen_origin;
	rot_axis = player->screen_rot_axis;
	rot_fov = M_PI_2 * FOV / 360;
	origin->x = player->angle->x;
	origin->y = player->angle->y;
	origin->z = player->angle->z;
	rot_axis->x = player->right_axis->x;
	rot_axis->y = player->right_axis->y;
	rot_axis->z = player->right_axis->z;
	vect_flat_rot(origin, rot_fov);
	vect_flat_rot(rot_axis, rot_fov);
	vect_rot(origin, rot_axis, -rot_fov * WIN_HEIGHT / WIN_WIDTH);
}

void	vect_flat_rot(t_vect *v, double rot_step)
{
	double	vx;
	double	vz;
	double	new_x;
	double	new_z;

	vx = v->x;
	vz = v->z;
	new_x = vx * cos(rot_step) - vz * sin(rot_step);
	new_z = vz * cos(rot_step) + vx * sin(rot_step);
	v->x = new_x;
	v->z = new_z;
}
