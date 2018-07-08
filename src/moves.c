/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:27:34 by vnekhay           #+#    #+#             */
/*   Updated: 2018/05/29 14:29:15 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		move_f(t_wolf *wolf)
{
	if ((int)(POSX + VECX * MS) > 0 && (int)(POSX + VECX * MS) < MAPH - 1
		&& wolf->map->array[(int)(POSX + VECX * 0.5)][(int)POSY] == 0)
		POSX += VECX * MS;
	if ((int)(POSY + VECY * MS) > 0 && (int)(POSY + VECY * MS) < MAPH - 1
		&& wolf->map->array[(int)POSX][(int)(POSY + VECY * 0.5)] == 0)
		POSY += VECY * MS;
}

void		move_b(t_wolf *wolf)
{
	if ((int)(POSX + VECX * -0.5) > 0 && (int)(POSX + VECX * -MS) < MAPH - 1
		&& wolf->map->array[(int)(POSX + VECX * -0.5)][(int)POSY] == 0)
		POSX += VECX * -MS;
	if ((int)(POSY + VECY * -0.5) > 0 && (int)(POSY + VECY * -MS) < MAPH - 1
		&& wolf->map->array[(int)POSX][(int)(POSY + VECY * -0.5)] == 0)
		POSY += VECY * -MS;
}

void		move_l(t_wolf *wolf)
{
	t_point	left_dir;

	left_dir.x = VECX * cos(TORAD(90)) - VECY * sin(TORAD(90));
	left_dir.y = VECX * sin(TORAD(90)) + VECY * cos(TORAD(90));
	if ((int)(POSX + left_dir.x * MS) > 0 && (int)(POSX + \
	left_dir.x * MS) < MAPH - 1
		&& wolf->map->array[(int)(POSX + left_dir.x * 0.5)][(int)POSY] == 0)
		POSX += left_dir.x * MS;
	if ((int)(POSY + left_dir.y * MS) > 0 && (int)(POSY + \
	left_dir.y * MS) < MAPH - 1
		&& wolf->map->array[(int)POSX][(int)(POSY + left_dir.y * 0.5)] == 0)
		POSY += left_dir.y * MS;
}

void		move_r(t_wolf *wolf)
{
	t_point	right_dir;

	right_dir.x = VECX * cos(TORAD(-90)) - VECY * sin(TORAD(-90));
	right_dir.y = VECX * sin(TORAD(-90)) + VECY * cos(TORAD(-90));
	if ((int)(POSX + right_dir.x * MS) > 0 && (int)(POSX + \
	right_dir.x * MS) < MAPH - 1
		&& wolf->map->array[(int)(POSX + right_dir.x * 0.5)][(int)POSY] == 0)
		POSX += right_dir.x * MS;
	if ((int)(POSY + right_dir.y * MS) > 0 && (int)(POSY + \
	right_dir.y * MS) < MAPH - 1
		&& wolf->map->array[(int)POSX][(int)(POSY + right_dir.y * 0.5)] == 0)
		POSY += right_dir.y * MS;
}
