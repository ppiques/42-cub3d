/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_structs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesnoye <ldesnoye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:52:22 by ldesnoye          #+#    #+#             */
/*   Updated: 2022/07/06 14:38:34 by ldesnoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubmain.h"

// Create engine->win.
void	init_window(t_engine *engine)
{
	t_img	*frame;

	engine->win = mlx_new_window(engine->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
	if (!engine->win)
		perror_and_exit(NULL, engine);
	engine->cur_frame = malloc(sizeof(t_img));
	if (!engine->cur_frame)
		perror_and_exit(NULL, engine);
	engine->cur_frame->img = mlx_new_image(engine->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!engine->cur_frame)
		perror_and_exit(NULL, engine);
	frame = engine->cur_frame;
	frame->addr = mlx_get_data_addr(frame->img, &frame->bpp,
			&frame->line_length, &frame->endian);
	engine->buf_frame = malloc(sizeof(t_img));
	if (!engine->buf_frame)
		perror_and_exit(NULL, engine);
	engine->buf_frame->img = mlx_new_image(engine->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!engine->buf_frame)
		perror_and_exit(NULL, engine);
	frame = engine->buf_frame;
	frame->addr = mlx_get_data_addr(frame->img, &frame->bpp,
			&frame->line_length, &frame->endian);
}

// Create a t_vect structure with the given coords.
t_vect	*new_vect(double x, double y, double z)
{
	t_vect	*v;

	v = malloc(sizeof(t_vect));
	if (!v)
		return (NULL);
	v->x = x;
	v->y = y;
	v->z = z;
	return (v);
}

// Create a t_player struct with the steps and fov initialized.
t_player	*new_player(void)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->screen_origin = NULL;
	player->screen_rot_axis = NULL;
	player->angle = NULL;
	player->right_axis = NULL;
	player->y = PLAYER_HEIGHT;
	player->fov = FOV;
	player->rot_step = M_PI * 2 / ROT_NUMBER;
	player->mv_step = MOVEMENT_STEP;
	return (player);
}

// Create a t_texture struct with all char* pointers set to NULL.
t_textures	*new_textures(void)
{
	t_textures	*textures;

	textures = malloc(sizeof(t_textures));
	if (!textures)
		return (NULL);
	textures->path_n = NULL;
	textures->n = NULL;
	textures->path_s = NULL;
	textures->s = NULL;
	textures->path_e = NULL;
	textures->e = NULL;
	textures->path_w = NULL;
	textures->w = NULL;
	textures->str_f = NULL;
	textures->str_c = NULL;
	return (textures);
}

// Create a t_engine struct with an empty t_player struct
// and an empty t_textures struct. All others field are set to NULL.
t_engine	*new_engine(void)
{
	t_engine	*engine;

	engine = malloc(sizeof(t_engine));
	if (!engine)
		return (NULL);
	engine->mlx = mlx_init();
	engine->win = NULL;
	engine->cur_frame = NULL;
	engine->buf_frame = NULL;
	engine->player = new_player();
	engine->map_height = 0;
	engine->map = NULL;
	engine->textures = new_textures();
	if (!engine->player || !engine->textures || !engine->mlx)
	{
		ft_putstr_fd("Error\nallocation error\n", 2);
		free_engine(engine);
	}
	return (engine);
}
