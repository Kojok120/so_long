/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kojokamo120@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:30:03 by kokamoto          #+#    #+#             */
/*   Updated: 2025/01/04 17:02:04 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_tile(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->floor_img, x
		* TILE_SIZE, y * TILE_SIZE);
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall_img, x
			* TILE_SIZE, y * TILE_SIZE);
	if (game->map[y][x] == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->player_img, x
			* TILE_SIZE, y * TILE_SIZE);
	}
	if (game->map[y][x] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->collectible_img, x
			* TILE_SIZE, y * TILE_SIZE);
	}
	if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->exit_img, x
			* TILE_SIZE, y * TILE_SIZE);
}

void	draw_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			// ft_printf("draw tile %d %d\n", x, y); //デバッグ用
			draw_tile(game, x, y);
			x++;
		}
		y++;
	}
}
