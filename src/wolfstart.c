/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolfstart.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnekhay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:15:58 by vnekhay           #+#    #+#             */
/*   Updated: 2018/05/29 16:27:20 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_clear_image(t_wolf *wolf)
{
	int		i;

	i = ((wolf->image->width - 1) * wolf->image->bpp + \
	(wolf->image->height - 1) * wolf->image->sl);
	ft_bzero(wolf->image->data, (size_t)i);
}

int			ft_create_image(t_wolf *wolf)
{
	wolf->image->img = mlx_new_image(wolf->mlx, WIN_WIDTH, WIN_HEIGHT);
	wolf->image->data = mlx_get_data_addr(wolf->image->img, \
	&wolf->image->bpp, &wolf->image->sl, &wolf->image->endian);
	wolf->image->bpp /= 8;
	wolf->image->width = WIN_WIDTH;
	wolf->image->height = WIN_HEIGHT;
	return (0);
}

void		init_wolf_additions(t_wolf **wolf)
{
	T5.bpp /= 8;
	T6.ptr = mlx_xpm_file_to_image((*wolf)->mlx, T6WAY, &T6.width, &T6.height);
	T6.data = mlx_get_data_addr(T6.ptr, &T6.bpp, &T6.sl, &T6.endian);
	T6.bpp /= 8;
	T7.ptr = mlx_xpm_file_to_image((*wolf)->mlx, T7WAY, &T7.width, &T7.height);
	T7.data = mlx_get_data_addr(T7.ptr, &T7.bpp, &T7.sl, &T7.endian);
	T7.bpp /= 8;
	G0.ptr = mlx_xpm_file_to_image((*wolf)->mlx, G0WAY, &G0.width, &G0.height);
	G0.data = mlx_get_data_addr(G0.ptr, &G0.bpp, &G0.sl, &G0.endian);
	G0.bpp /= 8;
	G1.ptr = mlx_xpm_file_to_image((*wolf)->mlx, G1WAY, &G1.width, &G1.height);
	G1.data = mlx_get_data_addr(G1.ptr, &G1.bpp, &G1.sl, &G1.endian);
	G1.bpp /= 8;
	G2.ptr = mlx_xpm_file_to_image((*wolf)->mlx, G2WAY, &G2.width, &G2.height);
	G2.data = mlx_get_data_addr(G2.ptr, &G2.bpp, &G2.sl, &G2.endian);
	G2.bpp /= 8;
	G3.ptr = mlx_xpm_file_to_image((*wolf)->mlx, G3WAY, &G3.width, &G3.height);
	G3.data = mlx_get_data_addr(G3.ptr, &G3.bpp, &G3.sl, &G3.endian);
	G3.bpp /= 8;
	G4.ptr = mlx_xpm_file_to_image((*wolf)->mlx, G4WAY, &G4.width, &G4.height);
	G4.data = mlx_get_data_addr(G4.ptr, &G4.bpp, &G4.sl, &G4.endian);
	G4.bpp /= 8;
	G5.ptr = mlx_xpm_file_to_image((*wolf)->mlx, G5WAY, &G5.width, &G5.height);
	G5.data = mlx_get_data_addr(G5.ptr, &G5.bpp, &G5.sl, &G5.endian);
	G5.bpp /= 8;
}

void		init_wolf(t_wolf **wolf)
{
	(*wolf)->mlx = mlx_init();
	(*wolf)->win = mlx_new_window((*wolf)->mlx, WIN_WIDTH, WIN_HEIGHT, "Wolfk");
	(*wolf)->actions = (t_actions){0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	(*wolf)->time = 0;
	(*wolf)->old_time = 0;
	(*wolf)->shoot_texture = 0;
	T0.ptr = mlx_xpm_file_to_image((*wolf)->mlx, T0WAY, &T0.width, &T0.height);
	T0.data = mlx_get_data_addr(T0.ptr, &T0.bpp, &T0.sl, &T0.endian);
	T0.bpp /= 8;
	T1.ptr = mlx_xpm_file_to_image((*wolf)->mlx, T1WAY, &T1.width, &T1.height);
	T1.data = mlx_get_data_addr(T1.ptr, &T1.bpp, &T1.sl, &T1.endian);
	T1.bpp /= 8;
	T2.ptr = mlx_xpm_file_to_image((*wolf)->mlx, T2WAY, &T2.width, &T2.height);
	T2.data = mlx_get_data_addr(T2.ptr, &T2.bpp, &T2.sl, &T2.endian);
	T2.bpp /= 8;
	T3.ptr = mlx_xpm_file_to_image((*wolf)->mlx, T3WAY, &T3.width, &T3.height);
	T3.data = mlx_get_data_addr(T3.ptr, &T3.bpp, &T3.sl, &T3.endian);
	T3.bpp /= 8;
	T4.ptr = mlx_xpm_file_to_image((*wolf)->mlx, T4WAY, &T4.width, &T4.height);
	T4.data = mlx_get_data_addr(T4.ptr, &T4.bpp, &T4.sl, &T4.endian);
	T4.bpp /= 8;
	T5.ptr = mlx_xpm_file_to_image((*wolf)->mlx, T5WAY, &T5.width, &T5.height);
	T5.data = mlx_get_data_addr(T5.ptr, &T5.bpp, &T5.sl, &T5.endian);
	init_wolf_additions(wolf);
	ft_create_image(*wolf);
}

int			main(int argc, char **argv)
{
	t_wolf *wolf;

	if (argc != 2)
		return (done("Choose the map --> ./maps/"));
	if (!(wolf = (t_wolf *)malloc(sizeof(t_wolf))))
		return (done("Unable to init"));
	if (!(map_reader(argv[1], wolf, 0)))
		return (done("Map isn't valid"));
	system("afplay -v 0.1 ~/Music/OKLETSGO.mp3&");
	system("afplay -v 0.1 ~/Music/twisted-transistor.mp3&");
	if (!(wolf->image = (t_image *)malloc(sizeof(t_image))))
		return (0);
	init_wolf(&wolf);
	raycasting(wolf);
	mlx_hook(wolf->win, 2, 0, key_press, wolf);
	mlx_hook(wolf->win, 3, 0, key_release, wolf);
	mlx_hook(wolf->win, 17, 1L << 17, escape, wolf);
	mlx_loop_hook(wolf->mlx, key_loop, wolf);
	mlx_loop(wolf->mlx);
	return (0);
}
