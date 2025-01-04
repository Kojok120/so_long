/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kojokamo120@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:47:43 by kokamoto          #+#    #+#             */
/*   Updated: 2025/01/04 12:52:01 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update_player_position(t_game *game, int new_x, int new_y)
{
	game->map[game->player_y][game->player_x] = '0';
	game->player_x = new_x;
	game->player_y = new_y;
	game->map[new_y][new_x] = 'P';
	game->moves++;
	mlx_clear_window(game->mlx, game->win);
	draw_map(game);
	printf("Moves: %d\n", game->moves);
}

static void	handle_collectible(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'C')
	{
		game->collectibles--;
		game->map[y][x] = '0';
	}
	if (game->map[y][x] == 'E' && game->collectibles == 0)
	{
		printf("Congratulations! You won in %d moves!\n", game->moves + 1);
		exit_game(game);
	}
}

static void	update_position(int keycode, int *x, int *y)
{
	if (keycode == KEY_A)
		(*x)--;
	if (keycode == KEY_D)
		(*x)++;
	if (keycode == KEY_W)
		(*y)--;
	if (keycode == KEY_S)
		(*y)++;
}

int	handle_keys(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x;
	new_y = game->player_y;
	if (keycode == KEY_ESC)
		exit_game(game);
	update_position(keycode, &new_x, &new_y);
	if (game->map[new_y][new_x] != '1')
	{
		handle_collectible(game, new_x, new_y);
		update_player_position(game, new_x, new_y);
	}
	return (0);
}
