/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_pixel.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesnoye <ldesnoye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 21:09:04 by ppiques           #+#    #+#             */
/*   Updated: 2022/07/06 14:32:43 by ldesnoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubmain.h"

unsigned int	my_mlx_pixel_get(t_img *img, int x, int y)
{
	char			*pixel;
	unsigned int	color;

	pixel = img->addr + (y * img->line_length + x * (img->bpp / 8));
	color = *(unsigned int *)pixel;
	return (color);
}

unsigned int	get_texture_pixel_n(double x, double y, t_textures *textures)
{
	double	x_f;
	double	y_f;
	double	japlm;
	int		width;
	int		height;

	width = textures->n_width;
	height = textures->n_height;
	x_f = 1 - modf(x, &japlm);
	y_f = modf(y, &japlm);
	return (my_mlx_pixel_get(textures->n, width * x_f, height * y_f));
}

unsigned int	get_texture_pixel_s(double x, double y, t_textures *textures)
{
	double	x_f;
	double	y_f;
	double	japlm;
	int		width;
	int		height;

	width = textures->s_width;
	height = textures->s_height;
	x_f = modf(x, &japlm);
	y_f = modf(y, &japlm);
	return (my_mlx_pixel_get(textures->s, width * x_f, height * y_f));
}

unsigned int	get_texture_pixel_e(double z, double y, t_textures *textures)
{
	double	z_f;
	double	y_f;
	double	japlm;
	int		width;
	int		height;

	width = textures->e_width;
	height = textures->e_height;
	z_f = modf(z, &japlm);
	y_f = modf(y, &japlm);
	return (my_mlx_pixel_get(textures->e, width * z_f, height * y_f));
}

unsigned int	get_texture_pixel_w(double z, double y, t_textures *textures)
{
	double	z_f;
	double	y_f;
	double	japlm;
	int		width;
	int		height;

	width = textures->w_width;
	height = textures->w_height;
	z_f = 1 - modf(z, &japlm);
	y_f = modf(y, &japlm);
	return (my_mlx_pixel_get(textures->w, width * z_f, height * y_f));
}
