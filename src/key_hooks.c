/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:19:39 by vnekhay           #+#    #+#             */
/*   Updated: 2018/05/29 15:11:35 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			key_loop(t_wolf *wolf)
{
	if (wolf->actions.move_f)
		move_f(wolf);
	if (wolf->actions.rotate_l)
		rotate_l(wolf);
	if (wolf->actions.rotate_r)
		rotate_r(wolf);
	if (wolf->actions.move_b)
		move_b(wolf);
	if (wolf->actions.run)
		run(wolf);
	if (!wolf->actions.run)
		walk(wolf);
	if (wolf->actions.move_l)
		move_l(wolf);
	if (wolf->actions.move_r)
		move_r(wolf);
	if (wolf->actions.shoot)
		shoot(wolf);
	ft_clear_image(wolf);
	raycasting(wolf);
	return (0);
}

void		key_press_additions(int k, t_wolf *wolf)
{
	if (k == 18)
	{
		wolf->actions.ak47 = 1;
		wolf->actions.awp = 0;
		wolf->actions.knife = 0;
	}
	else if (k == 19)
	{
		wolf->actions.ak47 = 0;
		wolf->actions.awp = 1;
		wolf->actions.knife = 0;
	}
	else if (k == 20)
	{
		wolf->actions.ak47 = 0;
		wolf->actions.awp = 0;
		wolf->actions.knife = 1;
	}
}

int			key_press(int k, t_wolf *wolf)
{
	if (k == 13)
		wolf->actions.move_f = 1;
	else if (k == 1)
		wolf->actions.move_b = 1;
	else if (k == 123)
		wolf->actions.rotate_l = 1;
	else if (k == 124)
		wolf->actions.rotate_r = 1;
	else if (k == 53)
		escape();
	else if (k == 257)
		wolf->actions.run = 1;
	else if (k == 0)
		wolf->actions.move_l = 1;
	else if (k == 2)
		wolf->actions.move_r = 1;
	else if (k == 49)
		wolf->actions.shoot = 1;
	else if (k == 46)
		system("pkill afplay");
	else if (k == 8)
		system("afplay -v 1 -t 1.5 ~/Music/Ak_47.mp3&");
	key_press_additions(k, wolf);
	return (0);
}

int			key_release(int k, t_wolf *wolf)
{
	if (k == 13)
		wolf->actions.move_f = 0;
	if (k == 1)
		wolf->actions.move_b = 0;
	if (k == 123)
		wolf->actions.rotate_l = 0;
	if (k == 124)
		wolf->actions.rotate_r = 0;
	if (k == 257)
		wolf->actions.run = 0;
	if (k == 0)
		wolf->actions.move_l = 0;
	if (k == 2)
		wolf->actions.move_r = 0;
	if (k == 49)
	{
		wolf->actions.shoot = 0;
		wolf->shoot_time = 0;
		ANIM = 0;
	}
	return (0);
}
