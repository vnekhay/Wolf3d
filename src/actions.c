/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:25:07 by vnekhay           #+#    #+#             */
/*   Updated: 2018/05/29 15:09:26 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		put_image(t_wolf *wolf)
{
	mlx_put_image_to_window(wolf->mlx, wolf->win, wolf->image->img, 0, 0);
	if (wolf->actions.awp == 1)
		mlx_put_image_to_window(wolf->mlx, wolf->win, wolf->gun[4].ptr, \
		WIN_WIDTH - wolf->gun[4].width, WIN_HEIGHT - wolf->gun[4].height);
	else if (wolf->actions.knife == 1)
		mlx_put_image_to_window(wolf->mlx, wolf->win, wolf->gun[5].ptr, \
		WIN_WIDTH - wolf->gun[5].width, WIN_HEIGHT - wolf->gun[5].height);
	else if (wolf->actions.ak47 == 1)
		mlx_put_image_to_window(wolf->mlx, wolf->win, wolf->gun[ANIM].ptr, \
		WIN_WIDTH - wolf->gun[ANIM].width, WIN_HEIGHT - wolf->gun[ANIM].height);
	else
		mlx_put_image_to_window(wolf->mlx, wolf->win, wolf->gun[ANIM].ptr, \
		WIN_WIDTH - wolf->gun[ANIM].width, WIN_HEIGHT - wolf->gun[ANIM].height);
	mlx_put_image_to_window(wolf->mlx, wolf->win, wolf->gun[3].ptr, \
	WIN_WIDTH / 2 - wolf->gun[3].width, WIN_HEIGHT / 2 - wolf->gun[3].height);
	wolf->old_time = (clock_t)wolf->time;
	wolf->time = clock();
	wolf->frame_time = (double)(wolf->time - wolf->old_time) / CLOCKS_PER_SEC;
	if (!wolf->actions.run)
		MS = wolf->frame_time * 1.2;
	else
		MS = wolf->frame_time * 2.4;
	RMS = wolf->frame_time * 70;
}

int			player_envs(t_map *map)
{
	map->dir_len = (WIN_WIDTH / 2) / tan((30) * (M_PI / 180));
	map->dir_vec.x = -1;
	map->dir_vec.y = 0;
	map->plane.x = 0;
	map->plane.y = 0.66;
	map->obstacles = 2;
	return (1);
}

void		run(t_wolf *wolf)
{
	MS = 0.06;
}

void		walk(t_wolf *wolf)
{
	MS = 0.03;
}

void		shoot(t_wolf *wolf)
{
	wolf->shoot_time += wolf->frame_time;
	if (wolf->shoot_time > 0 && wolf->shoot_time < 0.15)
		ANIM = 1;
	else
		ANIM = 2;
	if (wolf->shoot_time >= 0.3)
		wolf->shoot_time = 0;
}
