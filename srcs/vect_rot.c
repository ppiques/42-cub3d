/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_rot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesnoye <ldesnoye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:21:31 by ldesnoye          #+#    #+#             */
/*   Updated: 2022/05/24 16:22:27 by ldesnoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubmain.h"

static double	rot_scalar(t_vect *v, double x, double y, double z)
{
	return (v->x * x + v->y * y + v->z * z);
}

static double	rot_newx(t_vect *v, t_vect *u, double step)
{
	double	x1;
	double	x2;
	double	x3;
	double	c;
	double	s;

	c = cos(step);
	s = sin(step);
	x1 = u->x * u->x * (1 - c) + c;
	x2 = -u->z * s;
	x3 = u->x * u->z * (1 - c);
	return (rot_scalar(v, x1, x2, x3));
}

static double	rot_newy(t_vect *v, t_vect *u, double step)
{
	double	y1;
	double	y2;
	double	y3;
	double	c;
	double	s;

	c = cos(step);
	s = sin(step);
	y1 = u->z * s;
	y2 = c;
	y3 = -u->x * s;
	return (rot_scalar(v, y1, y2, y3));
}

static double	rot_newz(t_vect *v, t_vect *u, double step)
{
	double	z1;
	double	z2;
	double	z3;
	double	c;
	double	s;

	c = cos(step);
	s = sin(step);
	z1 = u->x * u->z * (1 - c);
	z2 = u->x * s;
	z3 = u->z * u->z * (1 - c) + c;
	return (rot_scalar(v, z1, z2, z3));
}

void	vect_rot(t_vect *v, t_vect *u, double step)
{
	double	new_x;
	double	new_y;
	double	new_z;

	new_x = rot_newx(v, u, step);
	new_y = rot_newy(v, u, step);
	new_z = rot_newz(v, u, step);
	v->x = new_x;
	v->y = new_y;
	v->z = new_z;
}
