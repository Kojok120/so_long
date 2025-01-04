/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_reachable.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kojokamo120@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:23:15 by kokamoto          #+#    #+#             */
/*   Updated: 2025/01/04 17:19:00 by kokamoto         ###   ########.fr       */
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
		ft_printf("copy[%d]: %s\n", i, copy[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void flood_fill(char **map, int x, int y, int *collectibles, t_game *game)
{
    // 境界チェック
    if (y < 0 || x < 0 || y >= game->map_height || x >= game->map_width)
	{
		ft_printf("y: %d, x: %d, height: %d, width: %d\n", y, x, game->map_height, game->map_width);
        return;
	}

    // 壁または既に訪れたマスの場合は返る
    if (map[y][x] == '1' || map[y][x] == 'F')
        return;

    // コレクタブルをカウント
    if (map[y][x] == 'C')
        (*collectibles)--;

    // 訪れたマスを'F'でマーク
    map[y][x] = 'F';

    // 上下左右を再帰的にチェック
    flood_fill(map, x, y - 1, collectibles, game);    // 上
    flood_fill(map, x, y + 1, collectibles, game);    // 下
    flood_fill(map, x - 1, y, collectibles, game);    // 左
    flood_fill(map, x + 1, y, collectibles, game);    // 右
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

//マップのCとEが到達可能かどうかをチェック
void	validate_reachable(t_game *game)
{
	char	**copy;
	int		collectibles;
	int		y;
	int		x;

	copy = copy_map(game->map, game->map_height);
	if (!copy)
		exit_error("Allocation error while validating", game);
	ft_printf("copy_map: %p\n", copy);
	collectibles = game->collectibles;
	printf("player_x: %d, player_y: %d\n", game->player_x, game->player_y);
	flood_fill(copy, game->player_x, game->player_y, &collectibles, game);
	ft_printf("flood_fill done\n");
	y = 0;
	// //floodfillが終わったあとのマップの中身をみたい
	// while (copy[y])
	// {
	// 	ft_printf("copy[%d]: %s\n", y, copy[y]);
	// 	y++;
	// }
	// y = 0;

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
