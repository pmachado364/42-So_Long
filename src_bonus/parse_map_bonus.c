/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:11:38 by pmachado          #+#    #+#             */
/*   Updated: 2024/10/18 15:16:44 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static bool	parse_borders(char **layout, t_position border);
static bool	parse_player_and_exit(char **layout, t_position map);
static bool	parse_entities(t_game *g);
static bool	parse_path(t_game *g);

void	parse_map(t_game *g)
{
	g->world_map->treasures = 0;
	g->gathered_loot = 0;
	if (g->world_map->map_size.x == 0 || g->world_map->map_size.y == 0)
		ft_end(6, g);
	if (!parse_borders(g->world_map->layout, g->world_map->map_size))
		ft_end(8, g);
	if (!parse_player_and_exit(g->world_map->layout, g->world_map->map_size))
		ft_end(8, g);
	if (!parse_entities(g))
		ft_end(8, g);
	if (!parse_path(g))
		ft_end(9, g);
	g->gathered_loot = 0;
}

static bool	parse_borders(char **layout, t_position border)
{
	if (!parse_horizontal_borders(layout, border.x, 0)
		|| !parse_horizontal_borders(layout, border.x, border.y - 1))
		return (false);
	if (!parse_vertical_borders(layout, border.y, 0)
		|| !parse_vertical_borders(layout, border.y, border.x - 1))
		return (false);
	return (true);
}

static bool	parse_player_and_exit(char **layout, t_position map)
{
	int	col;
	int	row;
	int	exit;
	int	player;

	exit = 0;
	player = 0;
	row = 1;
	while (row < map.y)
	{
		col = 1;
		while (layout[row][col])
		{
			if (layout[row][col] == 'E')
				exit++;
			else if (layout[row][col] == 'P')
				player++;
			col++;
		}
		row++;
	}
	if (exit == 1 && player == 1)
		return (true);
	else
		return (false);
}

static bool	parse_entities(t_game *g)
{
	t_position	pos;

	pos.y = 1;
	while (pos.y < g->world_map->map_size.y)
	{
		pos.x = 1;
		while (g->world_map->layout[pos.y][pos.x])
		{
			if (g->world_map->layout[pos.y][pos.x] == 'E')
				g->world_map->escape_hatch = pos;
			else if (g->world_map->layout[pos.y][pos.x] == 'P')
				g->world_map->hero_position = pos;
			else if (g->world_map->layout[pos.y][pos.x] == 'C')
				g->world_map->treasures++;
			else if (g->world_map->layout[pos.y][pos.x] == 'V')
				g->world_map->enemies++;
			else if (!ft_strchr("01", g->world_map->layout[pos.y][pos.x]))
				return (false);
			pos.x++;
		}
		pos.y++;
	}
	return (true);
}

static bool	parse_path(t_game *g)
{
	char	**map_copy;
	int		y;
	int		x;

	map_copy = duplicate_map(g);
	flood_fill(map_copy, g, g->world_map->hero_position.x,
		g->world_map->hero_position.y);
	y = 0;
	while (y < g->world_map->map_size.y)
	{
		x = 0;
		while (x < g->world_map->map_size.x)
		{
			if (map_copy[y][x] == 'C' || map_copy[y][x] == 'E')
			{
				free_array(map_copy, g->world_map->map_size.y);
				ft_end(3, g);
			}
			x++;
		}
		y++;
	}
	free_array(map_copy, g->world_map->map_size.y);
	return (true);
}
