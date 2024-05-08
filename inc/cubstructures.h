/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubstructures.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:07:33 by ldesnoye          #+#    #+#             */
/*   Updated: 2022/06/23 20:10:33 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBSTRUCTURES_H
# define CUBSTRUCTURES_H

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_vect
{
	double	x;
	double	y;
	double	z;
}			t_vect;

// right_axis est maintenant un axe qui est a gauche du joueur
typedef struct s_player
{
	double	x;
	double	y;
	double	z;

	t_vect	*screen_origin;
	t_vect	*screen_rot_axis;
	t_vect	*angle;
	t_vect	*right_axis;

	int		fov;
	double	rot_step;
	double	mv_step;
}			t_player;

typedef struct s_textures
{
	char			*path_n;
	t_img			*n;
	int				n_height;
	int				n_width;
	char			*path_s;
	t_img			*s;
	int				s_height;
	int				s_width;
	char			*path_e;
	t_img			*e;
	int				e_height;
	int				e_width;
	char			*path_w;
	t_img			*w;
	int				w_height;
	int				w_width;

	char			*str_f;
	unsigned int	color_f;
	char			*str_c;
	unsigned int	color_c;

}					t_textures;

typedef struct s_engine
{
	void		*mlx;
	void		*win;

	t_img		*cur_frame;
	t_img		*buf_frame;

	t_player	*player;

	int			map_height;
	char		**map;

	t_textures	*textures;

}				t_engine;

#endif