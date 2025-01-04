/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kojokamo120@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:16:45 by kokamoto          #+#    #+#             */
/*   Updated: 2025/01/04 19:29:25 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	safe_destroy_image(void *mlx_ptr, void **img_ptr)
{
	if (mlx_ptr && *img_ptr)
	{
		mlx_destroy_image(mlx_ptr, *img_ptr);
		*img_ptr = NULL;
	}
}

void free_map(char **map)
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

void	clean_up(t_game *game)
{
	if (game->map)
	{
		free_map(game->map);
		game->map = NULL;
	}
	if (game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	safe_destroy_image(game->mlx, (void **)&game->player_img);
	safe_destroy_image(game->mlx, (void **)&game->wall_img);
	safe_destroy_image(game->mlx, (void **)&game->collectible_img);
	safe_destroy_image(game->mlx, (void **)&game->exit_img);
	safe_destroy_image(game->mlx, (void **)&game->floor_img);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
}

void	exit_error(char *message, t_game *game)
{
	ft_printf("%e%e\n", "Error\n", message);
	clean_up(game);
	exit(1);
}

int	exit_game(t_game *game)
{
	clean_up(game);
	exit(0);
	return (0);
}
