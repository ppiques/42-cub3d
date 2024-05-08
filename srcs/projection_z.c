/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_z.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesnoye <ldesnoye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:27:28 by ldesnoye          #+#    #+#             */
/*   Updated: 2022/07/06 19:03:00 by ldesnoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubmain.h"

double	north_ray_z_proj(t_vect *ray, t_engine *engine, t_player *player, int n)
{
	double	t;
	double	float_x_coord;
	char	char_seen;

	t = (n - player->z) / ray->z;
	float_x_coord = player->x + ray->x * t;
	char_seen = get_map_char((int)floor(float_x_coord), n - 1, engine);
	n--;
	while (char_seen != '1')
	{
		t = (n - player->z) / ray->z;
		float_x_coord = player->x + ray->x * t;
		char_seen = get_map_char((int)floor(float_x_coord), n - 1, engine);
		n--;
	}
	return (t);
}

double	south_ray_z_proj(t_vect *ray, t_engine *engine, t_player *player, int n)
{
	double	t;
	double	float_x_coord;
	char	char_seen;

	t = (player->z - n) / ray->z;
	float_x_coord = player->x;
	char_seen = get_map_char((int)floor(float_x_coord), n, engine);
	n++;
	while (char_seen != '1')
	{
		t = (n - player->z) / ray->z;
		float_x_coord = player->x + ray->x * t;
		char_seen = get_map_char((int)floor(float_x_coord), n, engine);
		n++;
	}
	return (t);
}

double	projection_z(t_vect *ray, t_engine *engine)
{
	t_player	*player;
	double		t;

	t = 1e30;
	player = engine->player;
	if (ray->z < 0)
		t = north_ray_z_proj(ray, engine, player, (int)floor(player->z));
	if (ray->z > 0)
		t = south_ray_z_proj(ray, engine, player, (int)floor(player->z));
	return (t);
}
