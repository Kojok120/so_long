/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kojokamo120@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:30:29 by kokamoto          #+#    #+#             */
/*   Updated: 2025/01/04 18:03:27 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void find_elements(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < (int)ft_strlen(game->map[y]))
		{
			if (game->map[y][x] == 'C')
				game->collectibles++;
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
			}
			if (game->map[y][x] == 'E')
			{
				game->exit_x = x;
				game->exit_y = y;
			}
			x++;
		}
		y++;
	}
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
	find_elements(&game);
	ft_printf("validate map\n"); //デバッグ用
	validate_map(&game);
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
