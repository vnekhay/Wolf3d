/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:24:06 by vnekhay           #+#    #+#             */
/*   Updated: 2018/05/29 15:11:18 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			done(char *message)
{
	ft_putendl(message);
	return (0);
}

int			escape(void)
{
	system("pkill afplay");
	exit(0);
}

void		ft_putpixel(int x, int y, t_colour color, t_wolf *wolf)
{
	int		i;

	i = x * wolf->image->bpp + y * wolf->image->sl;
	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT &&
		i <= WIN_HEIGHT * wolf->image->sl + WIN_WIDTH * 4)
	{
		wolf->image->data[i] = (char)color.blue;
		wolf->image->data[i + 1] = (char)color.green;
		wolf->image->data[i + 2] = (char)color.red;
	}
}

void		compas_additions(t_wolf *wolf, t_colour color, int x, int y)
{
	if (wolf->side == 0 && wolf->step_x == -1)
	{
		while (y < wolf->end)
		{
			color = (t_colour){.red = 255, .green = 255, .blue = 0};
			ft_putpixel(x, y, color, wolf);
			y++;
		}
	}
	if (wolf->side == 0 && wolf->step_x == 1)
	{
		while (y < wolf->end)
		{
			color = (t_colour){.red = 255, .green = 69, .blue = 0};
			ft_putpixel(x, y, color, wolf);
			y++;
		}
	}
}

void		compas(t_wolf *wolf, t_colour color, int x)
{
	int y;

	y = wolf->start;
	if (wolf->side == 1 && wolf->step_y == -1)
	{
		while (y < wolf->end)
		{
			color = (t_colour){.red = 32, .green = 178, .blue = 170};
			ft_putpixel(x, y, color, wolf);
			y++;
		}
	}
	if (wolf->side == 1 && wolf->step_y == 1)
	{
		while (y < wolf->end)
		{
			color = (t_colour){.red = 220, .green = 20, .blue = 60};
			ft_putpixel(x, y, color, wolf);
			y++;
		}
	}
	compas_additions(wolf, color, x, y);
}
