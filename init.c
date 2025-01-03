/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kojokamo120@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:31:56 by kokamoto          #+#    #+#             */
/*   Updated: 2025/01/02 13:32:32 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	int	img_width;
	int	img_height;

	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT,
			"so_long");
	game->moves = 0;
	game->collectibles = 0;
	game->player_img = mlx_xpm_file_to_image(game->mlx, "player.xpm",
			&img_width, &img_height);
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "wall.xpm", &img_width,
			&img_height);
	game->collectible_img = mlx_xpm_file_to_image(game->mlx, "collectible.xpm",
			&img_width, &img_height);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, "exit.xpm", &img_width,
			&img_height);
	game->floor_img = mlx_xpm_file_to_image(game->mlx, "floor.xpm", &img_width,
			&img_height);
}
