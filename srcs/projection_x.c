/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesnoye <ldesnoye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:26:41 by ldesnoye          #+#    #+#             */
/*   Updated: 2022/07/06 19:02:49 by ldesnoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubmain.h"

double	east_ray_x_proj(t_vect *ray, t_engine *engine, t_player *player, int n)
{
	double	t;
	double	float_z_coord;
	char	char_seen;

	t = (player->x - n) / ray->x;
	float_z_coord = player->z;
	char_seen = get_map_char(n, (int)floor(float_z_coord), engine);
	n++;
	while (char_seen != '1')
	{
		t = -(player->x - n) / ray->x;
		float_z_coord = player->z + ray->z * t;
		char_seen = get_map_char(n, (int)floor(float_z_coord), engine);
		n++;
	}
	return (t);
}

double	west_ray_x_proj(t_vect *ray, t_engine *engine, t_player *player, int n)
{
	double	t;
	double	float_z_coord;
	char	char_seen;

	t = (n - player->x) / ray->x;
	float_z_coord = player->z + ray->z * t;
	char_seen = get_map_char(n - 1, (int)floor(float_z_coord), engine);
	n--;
	while (char_seen != '1')
	{
		t = (n - player->x) / ray->x;
		float_z_coord = player->z + ray->z * t;
		char_seen = get_map_char(n - 1, (int)floor(float_z_coord), engine);
		n--;
	}
	return (t);
}

double	projection_x(t_vect *ray, t_engine *engine)
{
	t_player	*player;
	double		t;

	t = 1e30;
	player = engine->player;
	if (ray->x < 0)
		t = west_ray_x_proj(ray, engine, player, (int)floor(player->x));
	if (ray->x > 0)
		t = east_ray_x_proj(ray, engine, player, (int)floor(player->x));
	return (t);
}
