/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:39:49 by pmachado          #+#    #+#             */
/*   Updated: 2024/11/06 22:12:23 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

bool	parse_horizontal_borders(char **layout, int width, int row)
{
	if (width == 0)
		return (true);
	if (layout[row][width - 1] != '1')
		return (false);
	return (parse_horizontal_borders(layout, width - 1, row));
}

bool	parse_vertical_borders(char **layout, int height, int col)
{
	if (height == 0)
		return (true);
	if (layout[height - 1][col] != '1')
		return (false);
	return (parse_vertical_borders(layout, height - 1, col));
}

void	flood_fill(char **map, t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->world_map->map_size.x
		|| y >= game->world_map->map_size.y)
		return ;
	if (map[y][x] == 'F' || map[y][x] == '1')
		return ;
	if (map[y][x] == 'C')
	{
		map[y][x] = 'F';
		game->gathered_loot++;
	}
	if (map[y][x] == 'V')
		map[y][x] = 'F';
	if (map[y][x] == 'E' && game->gathered_loot != game->world_map->treasures)
	{
		map[y][x] = 'F';
		return ;
	}
	map[y][x] = 'F';
	flood_fill(map, game, x + 1, y);
	flood_fill(map, game, x - 1, y);
	flood_fill(map, game, x, y + 1);
	flood_fill(map, game, x, y - 1);
}

char	**duplicate_map(t_game *g)
{
	char	**map_copy;
	int		y;

	map_copy = malloc(sizeof(char *) * g->world_map->map_size.y);
	if (!map_copy)
		ft_end(3, g);
	y = -1;
	while (++y < g->world_map->map_size.y)
		map_copy[y] = ft_strdup(g->world_map->layout[y]);
	return (map_copy);
}
