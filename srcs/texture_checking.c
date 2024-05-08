/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_checking.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesnoye <ldesnoye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:50:33 by ldesnoye          #+#    #+#             */
/*   Updated: 2022/07/05 19:28:58 by ldesnoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubmain.h"

t_img	*open_texture(void *mlx, char *path, t_engine *engine, char *id)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	if (id[0] == 'N')
		open_texture_n(mlx, path, engine->textures, img);
	if (id[0] == 'S')
		open_texture_s(mlx, path, engine->textures, img);
	if (id[0] == 'E')
		open_texture_e(mlx, path, engine->textures, img);
	if (id[0] == 'W')
		open_texture_w(mlx, path, engine->textures, img);
	if (!img->img)
	{
		free(img);
		return (NULL);
	}
	img->addr = mlx_get_data_addr(img->img, &img->bpp,
			&img->line_length, &img->endian);
	return (img);
}

void	texture_checking(t_engine *engine)
{
	t_textures	*textures;

	textures = engine->textures;
	textures->n = open_texture(engine->mlx, textures->path_n, engine, "NO");
	if (!textures->n)
		perror_and_exit("NO texture", engine);
	textures->s = open_texture(engine->mlx, textures->path_s, engine, "SO");
	if (!textures->s)
		perror_and_exit("SO texture", engine);
	textures->e = open_texture(engine->mlx, textures->path_e, engine, "EA");
	if (!textures->e)
		perror_and_exit("EA texture", engine);
	textures->w = open_texture(engine->mlx, textures->path_w, engine, "WE");
	if (!textures->w)
		perror_and_exit("WE texture", engine);
	textures->color_c = color_parser(textures->str_c, engine, "C");
	textures->color_f = color_parser(textures->str_f, engine, "F");
}
