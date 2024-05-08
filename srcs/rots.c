/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rots.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesnoye <ldesnoye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:57:08 by ldesnoye          #+#    #+#             */
/*   Updated: 2022/07/06 17:17:32 by ldesnoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubmain.h"

void	rot_left(t_player *player)
{
	vect_flat_rot(player->angle, player->rot_step);
	vect_flat_rot(player->right_axis, player->rot_step);
}

void	rot_right(t_player *player)
{
	vect_flat_rot(player->angle, -player->rot_step);
	vect_flat_rot(player->right_axis, -player->rot_step);
}

void	rot_up(t_player *player)
{
	int	x_sign;
	int	z_sign;

	x_sign = 2 * (player->angle->x >= 0) - 1;
	z_sign = 2 * (player->angle->z >= 0) - 1;
	vect_rot(player->angle, player->right_axis, -player->rot_step);
	if (player->angle->x * x_sign < 0)
		vect_rot(player->angle, player->right_axis, player->rot_step);
	if (player->angle->z * z_sign < 0)
		vect_rot(player->angle, player->right_axis, player->rot_step);
}

void	rot_down(t_player *player)
{
	int	x_sign;
	int	z_sign;

	x_sign = 2 * (player->angle->x >= 0) - 1;
	z_sign = 2 * (player->angle->z >= 0) - 1;
	vect_rot(player->angle, player->right_axis, player->rot_step);
	if (player->angle->x * x_sign < 0)
		vect_rot(player->angle, player->right_axis, -player->rot_step);
	if (player->angle->z * z_sign < 0)
		vect_rot(player->angle, player->right_axis, -player->rot_step);
}
