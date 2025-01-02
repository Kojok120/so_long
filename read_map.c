/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokamoto <kojokamo120@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:30:21 by kokamoto          #+#    #+#             */
/*   Updated: 2025/01/02 13:30:23 by kokamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int get_map_height(char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd < 0) return 0;

    int height = 0;
    char *line = get_next_line(fd);
    while (line) {
        height++;
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    return height;
}

static char **allocate_map(t_game *game, int height) {
    game->map_height = height;
    game->map = malloc(sizeof(char *) * (height + 1));
    return game->map;
}

int read_map(t_game *game, char *filename) {
    int height = get_map_height(filename);
    if (height == 0 || !allocate_map(game, height))
        return 0;

    int fd = open(filename, O_RDONLY);
    if (fd < 0) return 0;

    char *line;
    char *temp;
    height = 0;

    while ((line = get_next_line(fd))) {
        if ((temp = strchr(line, '\n')))
            *temp = '\0';
        game->map[height] = strdup(line);
        if (height == 0)
            game->map_width = strlen(line);
        free(line);
        height++;
    }
    game->map[height] = NULL;
    close(fd);
    return 1;
}
