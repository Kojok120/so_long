/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kojokamo120@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:30:21 by kokamoto          #+#    #+#             */
/*   Updated: 2025/01/04 18:28:17 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_map_height(char *filename)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

static char	**allocate_map(t_game *game, int height)
{
	game->map_height = height;
	game->map = malloc(sizeof(char *) * (height + 1));
	return (game->map);
}

int	read_map(t_game *game, char *filename)
{
	int		height;
	int		fd;
	char	*line;
	char	*temp;

	height = get_map_height(filename);
	fd = open(filename, O_RDONLY);
	if (height == 0 || !allocate_map(game, height) || fd < 0)
		return (0);
	height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp = ft_strchr(line, '\n');
		if (temp)
			*temp = '\0';
		game->map[height] = ft_strdup(line);
		free(line);
		height++;
	}
	game->map[height] = NULL;
	close(fd);
	return (1);
}
