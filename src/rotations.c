/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:26:35 by vnekhay           #+#    #+#             */
/*   Updated: 2018/05/29 15:27:43 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		rotate_l(t_wolf *wolf)
{
	double	old_dir;
	double	old_plane;

	old_dir = VECX;
	old_plane = PLANEX;
	VECX = VECX * cos(TORAD(RMS)) - VECY * sin(TORAD(RMS));
	VECY = old_dir * sin(TORAD(RMS)) + VECY * cos(TORAD(RMS));
	PLANEX = PLANEX * cos(TORAD(RMS)) - PLANEY * sin(TORAD(RMS));
	PLANEY = old_plane * sin(TORAD(RMS)) + PLANEY * cos(TORAD(RMS));
}

void		rotate_r(t_wolf *wolf)
{
	double	old_dir;
	double	old_plane;

	old_dir = VECX;
	old_plane = PLANEX;
	VECX = VECX * cos(TORAD(-RMS)) - VECY * sin(TORAD(-RMS));
	VECY = old_dir * sin(TORAD(-RMS)) + VECY * cos(TORAD(-RMS));
	PLANEX = PLANEX * cos(TORAD(-RMS)) - PLANEY * sin(TORAD(-RMS));
	PLANEY = old_plane * sin(TORAD(-RMS)) + PLANEY * cos(TORAD(-RMS));
}
