/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kojokamo120@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:37:23 by kokamoto          #+#    #+#             */
/*   Updated: 2025/01/04 16:39:16 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600
# define TILE_SIZE 32

# define KEY_A 0x61
# define KEY_W 0x77
# define KEY_D 0x64
# define KEY_S 0x73
# define KEY_ESC 0xff1b

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		exit_x;
	int		exit_y;
	int		moves;
	void	*player_img;
	void	*wall_img;
	void	*collectible_img;
	void	*exit_img;
	void	*floor_img;
}			t_game;

void		validate_map(t_game *game);
void		validate_reachable(t_game *game);
int			read_map(t_game *game, char *filename);
void		draw_map(t_game *game);
int			handle_keys(int keycode, t_game *game);
void		init_game(t_game *game);
void		clean_up(t_game *game);
void		exit_error(char *message, t_game *game);
int			exit_game(t_game *game);

#endif
