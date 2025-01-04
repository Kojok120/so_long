/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kojokamo120@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:16:45 by kokamoto          #+#    #+#             */
/*   Updated: 2025/01/04 12:53:26 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_up(t_game *game)
{
	int	i;

	if (game->map)
	{
		i = 0;
		while (game->map[i])
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
	}
	if (game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->player_img)
		mlx_destroy_image(game->mlx, game->player_img);
	if (game->wall_img)
		mlx_destroy_image(game->mlx, game->wall_img);
	if (game->collectible_img)
		mlx_destroy_image(game->mlx, game->collectible_img);
	if (game->exit_img)
		mlx_destroy_image(game->mlx, game->exit_img);
	if (game->floor_img)
		mlx_destroy_image(game->mlx, game->floor_img);
}

void	exit_error(char *message, t_game *game)
{
	ft_printf("Error: %e\n", message);
	clean_up(game);
	exit(1);
}

int	exit_game(t_game *game)
{
	clean_up(game);
	exit(0);
	return (0);
}
