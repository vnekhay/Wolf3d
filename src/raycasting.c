/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:20:52 by vnekhay           #+#    #+#             */
/*   Updated: 2018/05/29 16:33:52 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		raycasting_adds4(t_point ray, t_wolf *wolf)
{
	wolf->line = (int)(WIN_HEIGHT / wolf->wall_dist);
	wolf->start = -(wolf->line) / 2 + WIN_HEIGHT / 2;
	if (wolf->start < 0)
		wolf->start = 0;
	wolf->end = wolf->line / 2 + WIN_HEIGHT / 2;
	if (wolf->end > WIN_HEIGHT)
		wolf->end = WIN_HEIGHT - 1;
	TNUM = wolf->map->array[wolf->map_x][wolf->map_y] - 1;
	if (wolf->side == 0)
		wolf->wall_x = POSY + wolf->wall_dist * ray.y;
	else
		wolf->wall_x = POSX + wolf->wall_dist * ray.x;
	wolf->wall_x -= (int)wolf->wall_x;
	WTX = (int)(wolf->wall_x * (double)WTNUM[TNUM].width);
	if (wolf->side == 0 && ray.x > 0)
		WTX = WTNUM[TNUM].width - WTX;
	if (wolf->side == 1 && ray.y < 0)
		WTX = WTNUM[TNUM].width - WTX;
}

void		raycasting_adds3(t_point ray, t_point delta_dist, \
t_wolf *wolf, t_point side_dist)
{
	while (wolf->hit == 0)
	{
		if (side_dist.x < side_dist.y)
		{
			side_dist.x += delta_dist.x;
			wolf->map_x += wolf->step_x;
			wolf->side = 0;
		}
		else
		{
			side_dist.y += delta_dist.y;
			wolf->map_y += wolf->step_y;
			wolf->side = 1;
		}
		if (MAP == 1 || MAP == 2 || MAP == 3 || MAP == 4 || MAP == 5 ||
			MAP == 6 || MAP == 7 || MAP == 8 || MAP == 9)
			wolf->hit = 1;
	}
	if (wolf->side == 0)
		wolf->wall_dist = ((double)wolf->map_x - POSX + \
			(double)(1 - wolf->step_x) / 2) / ray.x;
	else
		wolf->wall_dist = ((double)wolf->map_y - POSY + \
			(double)(1 - wolf->step_y) / 2) / ray.y;
	raycasting_adds4(ray, wolf);
}

void		raycasting_adds2(t_point ray, t_point delta_dist, \
t_wolf *wolf, t_point side_dist)
{
	if (ray.x < 0)
	{
		wolf->step_x = -1;
		side_dist.x = (POSX - wolf->map_x) * delta_dist.x;
	}
	else
	{
		wolf->step_x = 1;
		side_dist.x = ((double)wolf->map_x + 1.0 - POSX) * delta_dist.x;
	}
	if (ray.y < 0)
	{
		wolf->step_y = -1;
		side_dist.y = (POSY - (double)wolf->map_y) * delta_dist.y;
	}
	else
	{
		wolf->step_y = 1;
		side_dist.y = ((double)wolf->map_y + 1.0 - POSY) * delta_dist.y;
	}
	wolf->hit = 0;
	raycasting_adds3(ray, delta_dist, wolf, side_dist);
}

void		raycasting_adds(t_point ray, t_point delta_dist, \
t_wolf *wolf, t_point side_dist)
{
	int			y;
	t_colour	color;

	raycasting_adds2(ray, delta_dist, wolf, side_dist);
	y = wolf->start;
	if (TNUM == 0 || TNUM == 1 || TNUM == 2 || TNUM == 3 || TNUM == 4 ||
		TNUM == 5 || TNUM == 6 || TNUM == 7)
	{
		while (y < wolf->end)
		{
			WTY = (y - WIN_HEIGHT / 2 + wolf->line / 2) * \
				WTNUM[TNUM].width / wolf->line;
			color.blue = WTNUM[TNUM].data[WTX * WTNUM[TNUM].bpp + WTY * \
				WTNUM[TNUM].sl];
			color.green = WTNUM[TNUM].data[WTX * WTNUM[TNUM].bpp + WTY * \
				WTNUM[TNUM].sl + 1];
			color.red = WTNUM[TNUM].data[WTX * WTNUM[TNUM].bpp + WTY * \
				WTNUM[TNUM].sl + 2];
			ft_putpixel(wolf->x, y, color, wolf);
			y++;
		}
	}
	if (TNUM == 8)
		compas(wolf, color, wolf->x);
	wolf->buffer[wolf->x] = wolf->wall_dist;
}

void		raycasting(t_wolf *wolf)
{
	t_point	ray;
	t_point	side_dist;
	t_point	delta_dist;
	t_point	floor;

	side_dist = (t_point){0, 0};
	floor = (t_point){0, 0};
	wolf->x = 0;
	while (wolf->x <= WIN_WIDTH)
	{
		wolf->camera = 2 * wolf->x / (double)WIN_WIDTH - 1;
		ray.x = VECX + PLANEX * wolf->camera;
		ray.y = VECY + PLANEY * wolf->camera;
		wolf->map_x = (int)POSX;
		wolf->map_y = (int)POSY;
		delta_dist.x = fabs(1 / ray.x);
		delta_dist.y = fabs(1 / ray.y);
		raycasting_adds(ray, delta_dist, wolf, side_dist);
		floor_additions(wolf, ray, floor);
		wolf->x++;
	}
	put_image(wolf);
}
