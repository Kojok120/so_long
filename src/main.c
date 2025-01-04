/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kojokamo120@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:30:29 by kokamoto          #+#    #+#             */
/*   Updated: 2025/01/04 15:36:12 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int count_collectibles(t_game *game)
{
	int	y;
	int	x;
	int	count;

	y = 0;
	count = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Usage: %s <map_file>\n", argv[0]);
		return (1);
	}
	init_game(&game);
	if (!read_map(&game, argv[1]))
		exit_error("Error reading map", &game);
	game.collectibles = count_collectibles(&game);
	ft_printf("draw map\n"); //デバッグ用
	draw_map(&game);
	ft_printf("mlx key hook\n"); //デバッグ用
	mlx_key_hook(game.win, handle_keys, &game);
	ft_printf("mlx hook\n"); //デバッグ用
	mlx_hook(game.win, 17, 0L, exit_game, &game);
	ft_printf("mlx loop\n"); //デバッグ用
	mlx_loop(game.mlx);
	return (0);
}
