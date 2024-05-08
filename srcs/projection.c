/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesnoye <ldesnoye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 00:40:36 by ldesnoye          #+#    #+#             */
/*   Updated: 2022/07/06 17:27:16 by ldesnoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubmain.h"

char	get_map_char(int x, int z, t_engine *engine)
{
	char	char_seen;

	if (z < 0 || z >= engine->map_height)
		char_seen = '1';
	else if (x < 0 || x >= (int)ft_strlen(engine->map[z]))
		char_seen = '1';
	else
		char_seen = engine->map[z][x];
	if (char_seen != '0')
		char_seen = '1';
	return (char_seen);
}

unsigned int	wall_proj(t_vect *ray, t_engine *engine, double t_x, double t_z)
{
	double	calc_x;
	double	calc_y;
	double	calc_z;

	if (t_x > t_z)
	{
		calc_x = ray->x * t_z + engine->player->x;
		calc_y = 1 - (ray->y * t_z + engine->player->y);
		if (ray->z >= 0)
			return (get_texture_pixel_s(calc_x, calc_y, engine->textures));
		else
			return (get_texture_pixel_n(calc_x, calc_y, engine->textures));
	}
	else
	{
		calc_z = ray->z * t_x + engine->player->z;
		calc_y = 1 - (ray->y * t_x + engine->player->y);
		if (ray->x >= 0)
			return (get_texture_pixel_w(calc_z, calc_y, engine->textures));
		else
			return (get_texture_pixel_e(calc_z, calc_y, engine->textures));
	}
}

unsigned int	ceil_proj(t_vect *ray, t_engine *engine, double t_y)
{
	double	osef;

	if (CEIL_GRID)
	{
		if (modf(ray->x * t_y + engine->player->x, &osef) < GRID_WIDTH)
			return (0);
		if (modf(ray->x * t_y + engine->player->x, &osef) > 1 - GRID_WIDTH)
			return (0);
		if (modf(ray->z * t_y + engine->player->z, &osef) < GRID_WIDTH)
			return (0);
		if (modf(ray->z * t_y + engine->player->z, &osef) > 1 - GRID_WIDTH)
			return (0);
	}
	return (engine->textures->color_c);
}

unsigned int	floor_proj(t_vect *ray, t_engine *engine, double t_y)
{
	double	osef;

	if (FLOOR_GRID)
	{
		if (modf(ray->x * t_y + engine->player->x, &osef) < GRID_WIDTH)
			return (0);
		if (modf(ray->x * t_y + engine->player->x, &osef) > 1 - GRID_WIDTH)
			return (0);
		if (modf(ray->z * t_y + engine->player->z, &osef) < GRID_WIDTH)
			return (0);
		if (modf(ray->z * t_y + engine->player->z, &osef) > 1 - GRID_WIDTH)
			return (0);
	}
	return (engine->textures->color_f);
}

unsigned int	projection(t_vect *ray, t_engine *engine)
{
	double	t_x;
	double	t_y;
	double	t_z;

	t_x = projection_x(ray, engine);
	t_z = projection_z(ray, engine);
	if (ray->y > 0)
	{
		t_y = (1 - engine->player->y) / ray->y;
		if (t_y < t_z && t_y < t_x && t_y > 0)
			return (ceil_proj(ray, engine, t_y));
	}
	if (ray->y < 0)
	{
		t_y = -engine->player->y / ray->y;
		if (t_y < t_z && t_y < t_x && t_y > 0)
			return (floor_proj(ray, engine, t_y));
	}
	return (wall_proj(ray, engine, t_x, t_z));
}
