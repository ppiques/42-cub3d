/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubmain.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesnoye <ldesnoye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:06:08 by ldesnoye          #+#    #+#             */
/*   Updated: 2022/07/06 18:48:04 by ldesnoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBMAIN_H
# define CUBMAIN_H

# include "cubstructures.h"
# include "cubkeys.h"
# include "cubconsts.h"

# include "../mlx_linux/mlx.h"
# include "../libft/inc/libft.h"

# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

// arg_check.c
int				arg_check(int argc, char *str, t_engine *engine);

// color_parser.c
unsigned int	color_parser(char *str, t_engine *engine, char *id);

// create_structs.c
void			init_window(t_engine *engine);
t_vect			*new_vect(double x, double y, double z);
t_player		*new_player(void);
t_textures		*new_textures(void);
t_engine		*new_engine(void);

// frame_handler.c
int				render_buf_frame(t_engine *engine);
int				show_frame(t_engine *engine);

// free_structs.c
void			free_img(void *mlx, t_img *img);
void			free_player(t_player *player);
void			free_textures(t_textures *textures, void *mlx);
void			free_split(char **tab);
int				free_engine(t_engine *engine);

// get_next_line.c
int				get_next_line(int fd, char **line);

// get_texture_pixel.c
unsigned int	get_texture_pixel_n(double x, double y, t_textures *textures);
unsigned int	get_texture_pixel_s(double x, double y, t_textures *textures);
unsigned int	get_texture_pixel_e(double z, double y, t_textures *textures);
unsigned int	get_texture_pixel_w(double z, double y, t_textures *textures);

// init_player_pos.c
int				player_init_pos(t_engine *engine, int z, int x, char c);

// keypress.c
int				key_press(int keycode, t_engine *engine);

// map_checker.c
int				map_checker(char **map, t_engine *engine);

// map_checker_utils.c
int				is_spawn_point(char c);
int				is_valid_char(char c);
int				is_surrounded(int i, int j, char **map);

// map_parsing.c
int				count_lines(int fd);
int				map_reader(char *filename, t_engine *engine);

// open_textures.c

void			open_texture_n(void *mlx, char *p, t_textures *tx, t_img *img);
void			open_texture_s(void *mlx, char *p, t_textures *tx, t_img *img);
void			open_texture_e(void *mlx, char *p, t_textures *tx, t_img *img);
void			open_texture_w(void *mlx, char *p, t_textures *tx, t_img *img);

// path_finder.c
int				path_finder(char *line, t_textures *textures);

// projection.c
char			get_map_char(int x, int z, t_engine *engine);
unsigned int	projection(t_vect *ray, t_engine *engine);

// projection_x.c
double			projection_x(t_vect *ray, t_engine *engine);

// projection_z.c
double			projection_z(t_vect *ray, t_engine *engine);

// reverser.c
void			player_reverser(t_player *player);
void			map_reverser(t_engine *engine);
// rots.c
void			rot_left(t_player *player);
void			rot_right(t_player *player);
void			rot_up(t_player *player);
void			rot_down(t_player *player);

// steps.c
void			step_front(t_player *player, t_engine *engine);
void			step_back(t_player *player, t_engine *engine);
void			step_right(t_player *player, t_engine *engine);
void			step_left(t_player *player, t_engine *engine);

// test.c
void			my_mlx_pixel_put(t_img *data, int x, int y, int color);
void			perror_and_exit(char *s, t_engine *engine);
int				render_buf_frame(t_engine *engine);

// texture_checking.c
void			texture_checking(t_engine *engine);

// texture_parsing.c
char			*line_skip(int fd);
void			gnl_finish_fd(int fd);
int				texture_parsing(int fd, t_engine *engine);

// vect_ops.c
double			vect_norm(double x, double y, double z);
void			calc_origin(t_player *player);
void			vect_flat_rot(t_vect *v, double rot_step);

// vect_rot.c
void			vect_rot(t_vect *v, t_vect *u, double step);

// DEBUG
void			print_vect(t_vect *v);

#endif