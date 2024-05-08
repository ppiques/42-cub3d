/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 20:23:17 by ldesnoye          #+#    #+#             */
/*   Updated: 2022/06/29 13:54:06 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubmain.h"

int	player_init_north(t_engine *engine, t_player *player)
{
	player->angle = new_vect(0, 0, -1);
	player->screen_origin = new_vect(0, 0, -1);
	player->right_axis = new_vect(-1, 0, 0);
	player->screen_rot_axis = new_vect(1, 0, 0);
	if (!player->angle || !player->right_axis)
		perror_and_exit(NULL, engine);
	if (!player->screen_origin || !player->screen_rot_axis)
		perror_and_exit(NULL, engine);
	return (0);
}

int	player_init_south(t_engine *engine, t_player *player)
{
	player->angle = new_vect(0, 0, 1);
	player->screen_origin = new_vect(0, 0, 1);
	player->right_axis = new_vect(1, 0, 0);
	player->screen_rot_axis = new_vect(-1, 0, 0);
	if (!player->angle || !player->right_axis)
		perror_and_exit(NULL, engine);
	if (!player->screen_origin || !player->screen_rot_axis)
		perror_and_exit(NULL, engine);
	return (0);
}

int	player_init_east(t_engine *engine, t_player *player)
{
	player->angle = new_vect(1, 0, 0);
	player->screen_origin = new_vect(1, 0, 0);
	player->right_axis = new_vect(0, 0, -1);
	player->screen_rot_axis = new_vect(0, 0, 1);
	if (!player->angle || !player->right_axis)
		perror_and_exit(NULL, engine);
	if (!player->screen_origin || !player->screen_rot_axis)
		perror_and_exit(NULL, engine);
	return (0);
}

int	player_init_west(t_engine *engine, t_player *player)
{
	player->angle = new_vect(-1, 0, 0);
	player->screen_origin = new_vect(-1, 0, 0);
	player->right_axis = new_vect(0, 0, 1);
	player->screen_rot_axis = new_vect(0, 0, -1);
	if (!player->angle || !player->right_axis)
		perror_and_exit(NULL, engine);
	if (!player->screen_origin || !player->screen_rot_axis)
		perror_and_exit(NULL, engine);
	return (0);
}

int	player_init_pos(t_engine *engine, int z, int x, char c)
{
	t_player	*player;

	player = engine->player;
	player->x = (double)x + 0.5;
	player->z = (double)z + 0.5;
	if (c == 'N')
		player_init_north(engine, player);
	if (c == 'S')
		player_init_south(engine, player);
	if (c == 'E')
		player_init_east(engine, player);
	if (c == 'W')
		player_init_west(engine, player);
	return (0);
}
