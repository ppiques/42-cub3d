/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesnoye <ldesnoye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:20:24 by ldesnoye          #+#    #+#             */
/*   Updated: 2022/05/20 13:28:32 by ldesnoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubmain.h"

t_img	*open_frame(void *mlx, int width, int height)
{
	t_img	*frame;

	frame = malloc(sizeof(t_img));
	if (!frame)
		return (NULL);
	frame->img = mlx_new_image(mlx, width * 32, height * 32);
	if (!frame->img)
		return (NULL);
	frame->addr = mlx_get_data_addr(frame->img, &frame->bpp,
			&frame->line_length, &frame->endian);
	return (frame);
}

t_img	*open_sprite(void *mlx, char *path)
{
	t_img	*img;
	int		width;
	int		height;

	img = malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	img->img = mlx_xpm_file_to_image(mlx, path, &width, &height);
	if (!img->img)
	{
		free(img);
		return (NULL);
	}
	img->addr = mlx_get_data_addr(img->img, &img->bpp,
			&img->line_length, &img->endian);
	return (img);
}
