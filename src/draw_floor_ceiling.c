/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_ceiling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:22:54 by vnekhay           #+#    #+#             */
/*   Updated: 2018/05/29 15:22:28 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			lines_counter(char *file)
{
	int		j;
	int		i;
	int		fd;
	char	*line;

	j = 0;
	i = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
		return (-1);
	close(fd);
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		i++;
		j++;
		free(line);
	}
	if (i != 0)
		free(line);
	close(fd);
	return (j - 1);
}

void		drawing_floor(t_wolf *wolf, t_colour color, t_point floor)
{
	int		start_floor;
	double	curr_dist;
	t_point	curr_floor;

	start_floor = wolf->end;
	while (start_floor < WIN_HEIGHT)
	{
		curr_dist = (double)WIN_HEIGHT / (2 * (double)start_floor - \
			(double)WIN_HEIGHT);
		curr_floor.x = curr_dist / wolf->wall_dist * floor.x + (1 - \
			(curr_dist / wolf->wall_dist)) * POSX;
		curr_floor.y = curr_dist / wolf->wall_dist * floor.y + (1 - \
			(curr_dist / wolf->wall_dist)) * POSY;
		WTX = (int)(curr_floor.x * WTNUM[3].width) % WTNUM[3].width;
		WTY = (int)(curr_floor.y * WTNUM[3].height) % WTNUM[3].height;
		color.blue = WTNUM[3].data[WTX * WTNUM[3].bpp + WTY * WTNUM[3].sl];
		color.green = WTNUM[3].data[WTX * WTNUM[3].bpp + WTY * \
			WTNUM[3].sl + 1];
		color.red = WTNUM[3].data[WTX * WTNUM[3].bpp + WTY * \
			WTNUM[3].sl + 2];
		ft_putpixel(wolf->x, start_floor, color, wolf);
		start_floor++;
	}
}

void		drawing_ceiling(t_wolf *wolf, t_colour color, t_point floor)
{
	int		start_ceiling;
	double	curr_dist;
	t_point	curr_floor;

	start_ceiling = wolf->start - 1;
	while (start_ceiling > 0)
	{
		curr_dist = (double)-WIN_HEIGHT / (2 * (double)start_ceiling - \
			(double)WIN_HEIGHT);
		curr_floor.x = curr_dist / wolf->wall_dist * floor.x + (1 - \
			(curr_dist / wolf->wall_dist)) * POSX;
		curr_floor.y = curr_dist / wolf->wall_dist * floor.y + (1 - \
			(curr_dist / wolf->wall_dist)) * POSY;
		WTX = (int)(curr_floor.x * WTNUM[5].width) % WTNUM[5].width;
		WTY = (int)(curr_floor.y * WTNUM[5].height) % WTNUM[5].height;
		color.blue = WTNUM[5].data[WTX * WTNUM[5].bpp + WTY * WTNUM[5].sl];
		color.green = WTNUM[5].data[WTX * WTNUM[5].bpp + WTY * \
			WTNUM[5].sl + 1];
		color.red = WTNUM[5].data[WTX * WTNUM[5].bpp + WTY * \
			WTNUM[5].sl + 2];
		ft_putpixel(wolf->x, start_ceiling, color, wolf);
		start_ceiling--;
	}
}

void		floor_additions(t_wolf *wolf, t_point ray, t_point floor)
{
	t_colour	color;

	color = (t_colour){0, 0, 0};
	if (wolf->side == 0 && ray.x > 0)
	{
		floor.x = wolf->map_x;
		floor.y = wolf->map_y + wolf->wall_x;
	}
	else if (wolf->side == 0 && ray.x < 0)
	{
		floor.x = wolf->map_x + 1;
		floor.y = wolf->map_y + wolf->wall_x;
	}
	else if (wolf->side == 1 && ray.y > 0)
	{
		floor.x = wolf->map_x + wolf->wall_x;
		floor.y = wolf->map_y;
	}
	else
	{
		floor.x = wolf->map_x + wolf->wall_x;
		floor.y = wolf->map_y + 1;
	}
	drawing_floor(wolf, color, floor);
	drawing_ceiling(wolf, color, floor);
}
