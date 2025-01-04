/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kojokamo120@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:30:29 by kokamoto          #+#    #+#             */
/*   Updated: 2025/01/04 19:18:09 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_elements(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	game->collectibles = 0;
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

int	check_file_extension(char *filename)
{
	char	*ext;

	ext = ft_strrchr(filename, '.');
	if (!ext || ft_strncmp(ext, ".ber", 5) != 0)
	{
		ft_printf("%e\n", "Error\nFile must have .ber extension");
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("%e %e %e", "Error\nUsage:", argv[0], "<map_file>\n");
		return (1);
	}
	if (!check_file_extension(argv[1]))
		return (1);
	init_game(&game);
	if (!read_map(&game, argv[1]))
		exit_error("Error reading map", &game);
	find_elements(&game);
	validate_map(&game);
	init_window(&game);
	draw_map(&game);
	mlx_key_hook(game.win, handle_keys, &game);
	mlx_hook(game.win, 17, 0L, exit_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
