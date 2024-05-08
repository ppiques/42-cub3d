/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 20:52:25 by ppiques           #+#    #+#             */
/*   Updated: 2022/06/29 13:47:16 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubmain.h"

void	open_texture_n(void *mlx, char *path, t_textures *textures, t_img *img)
{
	img->img = mlx_xpm_file_to_image(mlx, path, &textures->n_width,
			&textures->n_height);
}

void	open_texture_s(void *mlx, char *path, t_textures *textures, t_img *img)
{
	img->img = mlx_xpm_file_to_image(mlx, path, &textures->s_width,
			&textures->s_height);
}

void	open_texture_e(void *mlx, char *path, t_textures *textures, t_img *img)
{
	img->img = mlx_xpm_file_to_image(mlx, path, &textures->e_width,
			&textures->e_height);
}

void	open_texture_w(void *mlx, char *path, t_textures *textures, t_img *img)
{
	img->img = mlx_xpm_file_to_image(mlx, path, &textures->w_width,
			&textures->w_height);
}
