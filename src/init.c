/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kojokamo120@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:31:56 by kokamoto          #+#    #+#             */
/*   Updated: 2025/01/04 19:44:10 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	int	img_width;
	int	img_height;

	game->mlx = mlx_init();
	game->map = NULL;
	game->win = NULL;
	game->moves = 0;
	game->collectibles = 0;
	game->player_img = mlx_xpm_file_to_image(game->mlx, "images-xpm/player.xpm",
			&img_width, &img_height);
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "images-xpm/wall.xpm",
			&img_width, &img_height);
	game->collectible_img = mlx_xpm_file_to_image(game->mlx,
			"images-xpm/collectible.xpm", &img_width, &img_height);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, "images-xpm/exit.xpm",
			&img_width, &img_height);
	game->floor_img = mlx_xpm_file_to_image(game->mlx, "images-xpm/floor.xpm",
			&img_width, &img_height);
}

void	init_window(t_game *game)
{
	game->win = mlx_new_window(game->mlx, game->map_width * TILE_SIZE,
			game->map_height * TILE_SIZE, "so_long kokamoto");
}
