/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kojokamo120@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:07:12 by kokamoto          #+#    #+#             */
/*   Updated: 2025/01/04 16:43:00 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_map_shape(t_game *game)
{
	int	y;
	int	x;
	int	width;

	y = 0;
	width = ft_strlen(game->map[0]);
	while (y < game->map_height)
	{
		x = 0;
		while (game->map[y][x])
			x++;
		if (x != width)
			return (0);
		y++;
	}
	game->map_width = width;
	return (1);
}

int validate_map_chars(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] != 'P' && game->map[y][x] != 'E'
				&& game->map[y][x] != 'C' && game->map[y][x] != '1'
				&& game->map[y][x] != '0')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	validate_map_surround(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (game->map[y][x])
		{
			if (y == 0 || y == game->map_height - 1 || x == 0
				|| x == game->map_width - 1)
			{
				if (game->map[y][x] != '1')
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	validate_map_element(t_game *game)
{
	int	y;
	int	x;
	int	player;
	int	exit;
	int	collectible;

	y = 0;
	player = 0;
	exit = 0;
	collectible = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'P')
				player++;
			if (game->map[y][x] == 'E')
				exit++;
			if (game->map[y][x] == 'C')
				collectible++;
			x++;
		}
		y++;
	}
	if (player != 1 || exit != 1 || collectible == 0)
		return (0);
	return (1);
}

void	validate_map(t_game *game)
{
	if (!validate_map_shape(game))
		exit_error("Invalid map shape", game);
	if (!validate_map_chars(game))
		exit_error("Invalid map characters", game);
	if (!validate_map_surround(game))
		exit_error("Invalid map surround", game);
	if (!validate_map_element(game))
		exit_error("Invalid map elements", game);
	validate_reachable(game);
}
