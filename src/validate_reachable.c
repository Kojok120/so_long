/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_reachable.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kojokamo120@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:23:15 by kokamoto          #+#    #+#             */
/*   Updated: 2025/01/04 18:39:43 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**copy_map(char **map, int height)
{
	char	**copy;
	int		i;

	copy = (char **)malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	flood_fill(char **map, int x, int y, t_game *game)
{
	int	collectibles;

	collectibles = game->collectibles;
	if (y < 0 || x < 0 || y >= game->map_height || x >= game->map_width)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	if (map[y][x] == 'C')
		collectibles--;
	map[y][x] = 'F';
	flood_fill(map, x, y - 1, game);
	flood_fill(map, x, y + 1, game);
	flood_fill(map, x - 1, y, game);
	flood_fill(map, x + 1, y, game);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	validate_reachable(t_game *game)
{
	char	**copy;
	int		y;
	int		x;

	copy = copy_map(game->map, game->map_height);
	if (!copy)
		exit_error("Allocation error while validating", game);
	flood_fill(copy, game->player_x, game->player_y, game);
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (copy[y][x] == 'C' || copy[y][x] == 'E')
				exit_error("Map is not reachable", game);
			x++;
		}
		y++;
	}
	free_map(copy);
	return ;
}
