/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesnoye <ldesnoye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:48:01 by ldesnoye          #+#    #+#             */
/*   Updated: 2022/07/06 16:41:19 by ldesnoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubmain.h"

void	player_reverser(t_player *player)
{
	player->angle->z = -(player->angle->z);
	player->right_axis->x = -(player->right_axis->x);
}

void	map_reverser(t_engine *engine)
{
	int			i;
	char		*swap;
	int			height;

	i = 0;
	height = engine->map_height;
	while (i < height / 2)
	{
		swap = engine->map[i];
		engine->map[i] = engine->map[height - i - 1];
		engine->map[height - i - 1] = swap;
		i++;
	}
}
