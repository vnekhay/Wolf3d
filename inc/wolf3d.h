/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:15:37 by vnekhay           #+#    #+#             */
/*   Updated: 2018/07/08 07:32:09 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include <time.h>

# define WIN_HEIGHT 720
# define WIN_WIDTH 1280
# define TORAD(x) ((x) * (M_PI / 180))
# define T0 (*wolf)->texture[0]
# define T0WAY "xpm_images/wall1.xpm"
# define T1 (*wolf)->texture[1]
# define T1WAY "xpm_images/wall2.xpm"
# define T2 (*wolf)->texture[2]
# define T2WAY "xpm_images/wall3.xpm"
# define T3 (*wolf)->texture[3]
# define T3WAY "xpm_images/wall4.xpm"
# define T4 (*wolf)->texture[4]
# define T4WAY "xpm_images/floor.xpm"
# define T5 (*wolf)->texture[5]
# define T5WAY "xpm_images/sky.xpm"
# define T6 (*wolf)->texture[6]
# define T6WAY "xpm_images/pashyna.xpm"
# define T7 (*wolf)->texture[7]
# define T7WAY "xpm_images/pashyna2.xpm"
# define G0 (*wolf)->gun[0]
# define G0WAY "xpm_images/gun_animation/Ak47.xpm"
# define G1 (*wolf)->gun[1]
# define G1WAY "xpm_images/gun_animation/Ak47_33.xpm"
# define G2 (*wolf)->gun[2]
# define G2WAY "xpm_images/gun_animation/Ak47_22.xpm"
# define G3 (*wolf)->gun[3]
# define G3WAY "xpm_images/gun_animation/21.xpm"
# define G4 (*wolf)->gun[4]
# define G4WAY "xpm_images/gun_animation/knife.xpm"
# define G5 (*wolf)->gun[5]
# define G5WAY "xpm_images/gun_animation/awp.xpm"
# define WTX wolf->tex_x
# define WTY wolf->tex_y
# define MAP wolf->map->array[wolf->map_x][wolf->map_y]
# define TNUM wolf->text_num
# define WTNUM wolf->texture
# define RMS wolf->map->rot_speed
# define MS wolf->map->move_speed
# define POSX wolf->map->player_pos.x
# define POSY wolf->map->player_pos.y
# define VECX wolf->map->dir_vec.x
# define VECY wolf->map->dir_vec.y
# define MAPH wolf->map->height
# define PLANEY wolf->map->plane.y
# define PLANEX wolf->map->plane.x
# define ANIM wolf->shoot_texture
# define MAPI map->line[map->i]

typedef struct			s_colour
{
	double				red;
	double				green;
	double				blue;
}						t_colour;

typedef struct			s_point
{
	double				x;
	double				y;
}						t_point;

typedef struct			s_image
{
	void				*img;
	char				*data;
	int					bpp;
	int					endian;
	int					height;
	int					width;
	int					sl;
}						t_image;

typedef struct			s_texture
{
	void				*ptr;
	char				*data;
	int					bpp;
	int					endian;
	int					height;
	int					width;
	int					sl;
}						t_texture;

typedef struct			s_map
{
	int					width;
	int					height;
	int					**array;
	t_point				player_pos;
	t_point				dir_vec;
	double				dir_len;
	double				rot_speed;
	double				move_speed;
	t_point				plane;
	int					obstacles;
	int					fd;
	char				*line;
	int					i;
	int					j;
	int					z;
}						t_map;

typedef struct			s_actions
{
	int					rotate_l;
	int					rotate_r;
	int					move_f;
	int					move_b;
	int					run;
	int					move_l;
	int					move_r;
	int					shoot;
	int					knife;
	int					awp;
	int					ak47;
}						t_actions;

typedef struct			s_wolf
{
	t_image				*image;
	t_map				*map;
	void				*mlx;
	t_actions			actions;
	void				*win;
	t_texture			texture[10];
	t_texture			gun[6];
	clock_t				time;
	clock_t				old_time;
	double				frame_time;
	double				shoot_time;
	int					shoot_texture;
	double				buffer[WIN_WIDTH];
	int					tex_x;
	int					tex_y;
	int					start;
	int					end;
	int					line;
	int					side;
	int					step_x;
	int					step_y;
	int					text_num;
	int					map_x;
	int					map_y;
	double				camera;
	double				wall_dist;
	int					hit;
	double				wall_x;
	int					x;
}						t_wolf;

int						key_release(int k, t_wolf *wolf);
int						key_press(int k, t_wolf *wolf);
void					key_press_additions(int k, t_wolf *wolf);
int						key_loop(t_wolf *wolf);
void					shoot(t_wolf *wolf);
void					walk(t_wolf *wolf);
void					run(t_wolf *wolf);
void					move_r(t_wolf *wolf);
void					move_l(t_wolf *wolf);
void					move_b(t_wolf *wolf);
void					move_f(t_wolf *wolf);
void					rotate_r(t_wolf *wolf);
void					rotate_l(t_wolf *wolf);
void					raycasting(t_wolf *wolf);
void					put_image(t_wolf *wolf);
void					raycasting_adds(t_point ray, t_point delta_dist, \
						t_wolf *wolf, t_point side_dist);
void					raycasting_adds2(t_point ray, t_point delta_dist, \
						t_wolf *wolf, t_point side_dist);
void					raycasting_adds3(t_point ray, t_point delta_dist, \
						t_wolf *wolf, t_point side_dist);
void					raycasting_adds4(t_point ray, t_wolf *wolf);
void					floor_additions(t_wolf *wolf, t_point ray, \
						t_point floor);
void					drawing_ceiling(t_wolf *wolf, t_colour color, \
						t_point floor);
void					drawing_floor(t_wolf *wolf, t_colour color, \
						t_point	floor);
void					compas(t_wolf *wolf, t_colour color, int x);
void					compas_additions(t_wolf *wolf, t_colour color, \
						int x, int y);
void					ft_putpixel(int x, int y, t_colour color, t_wolf *wolf);
void					init_wolf(t_wolf **wolf);
void					init_wolf_additions(t_wolf **wolf);
int						ft_create_image(t_wolf *wolf);
void					ft_clear_image(t_wolf *wolf);
int						map_reader(char *file, t_wolf *wolf, int j);
int						*map_filler(char *line, t_map *map, int *width);
int						lines_counter(char *file);
int						char_counter(char *file, int end, t_map *map);
int						player_envs(t_map *map);
int						escape(void);
int						done(char *message);

#endif
