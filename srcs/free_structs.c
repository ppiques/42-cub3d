/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesnoye <ldesnoye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:17:13 by ldesnoye          #+#    #+#             */
/*   Updated: 2022/07/06 15:12:43 by ldesnoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubmain.h"

// Free cleanly t_img pointer.
void	free_img(void *mlx, t_img *img)
{
	if (img)
		mlx_destroy_image(mlx, img->img);
	free(img);
}

// Free cleanly t_player pointer.
void	free_player(t_player *player)
{
	if (player)
	{
		free(player->screen_origin);
		free(player->screen_rot_axis);
		free(player->angle);
		free(player->right_axis);
	}
	free(player);
}

// Free cleanly t_textures pointer.
void	free_textures(t_textures *textures, void *mlx)
{
	if (textures)
	{
		free(textures->path_n);
		free_img(mlx, textures->n);
		free(textures->path_s);
		free_img(mlx, textures->s);
		free(textures->path_e);
		free_img(mlx, textures->e);
		free(textures->path_w);
		free_img(mlx, textures->w);
		free(textures->str_f);
		free(textures->str_c);
	}
	free(textures);
}

// Free NULL-terminated char**.
void	free_split(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
	}
	free(tab);
}

// Free cleanly t_engine pointer.
int	free_engine(t_engine *engine)
{
	free_player(engine->player);
	free_split(engine->map);
	free_textures(engine->textures, engine->mlx);
	if (engine->mlx && engine->cur_frame)
		mlx_destroy_image(engine->mlx, engine->cur_frame->img);
	free(engine->cur_frame);
	if (engine->mlx && engine->buf_frame)
		mlx_destroy_image(engine->mlx, engine->buf_frame->img);
	free(engine->buf_frame);
	if (engine->mlx && engine->win)
		mlx_destroy_window(engine->mlx, engine->win);
	if (engine->mlx)
		mlx_destroy_display(engine->mlx);
	free(engine->mlx);
	free(engine);
	exit(0);
}
