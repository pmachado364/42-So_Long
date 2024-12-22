/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:06:35 by pmachado          #+#    #+#             */
/*   Updated: 2024/10/18 15:22:32 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	up(t_game *g)
{
	t_position	h_pos;

	h_pos = g->world_map->hero_position;
	put_tile(g, "./textures/Floor/GRASS.xpm", h_pos.x * 64, h_pos.y * 64);
	if (g->footsteps % 2 == 0)
		put_tile(g, "./textures/Character/BACK_LEFT.xpm",
			h_pos.x * 64, (h_pos.y - 1) * 64);
	else
		put_tile(g, "./textures/Character/BACK_RIGHT.xpm",
			h_pos.x * 64, (h_pos.y - 1) * 64);
	g->world_map->hero_position.y = h_pos.y - 1;
}

void	down(t_game *g)
{
	t_position	h_pos;

	h_pos = g->world_map->hero_position;
	put_tile(g, "./textures/Floor/GRASS.xpm", h_pos.x * 64, h_pos.y * 64);
	if (g->footsteps % 2 == 0)
		put_tile(g, "./textures/Character/FRONT_LEFT.xpm",
			h_pos.x * 64, (h_pos.y + 1) * 64);
	else
		put_tile(g, "./textures/Character/FRONT_RIGHT.xpm",
			h_pos.x * 64, (h_pos.y + 1) * 64);
	g->world_map->hero_position.y = h_pos.y + 1;
}

void	left(t_game *g)
{
	t_position	h_pos;

	h_pos = g->world_map->hero_position;
	put_tile(g, "./textures/Floor/GRASS.xpm", h_pos.x * 64, h_pos.y * 64);
	if (g->footsteps % 2 == 0)
		put_tile(g, "./textures/Character/LEFT_LEFT.xpm",
			(h_pos.x - 1) * 64, h_pos.y * 64);
	else
		put_tile(g, "./textures/Character/LEFT_RIGHT.xpm",
			(h_pos.x - 1) * 64, h_pos.y * 64);
	g->world_map->hero_position.x = h_pos.x - 1;
}

void	right(t_game *g)
{
	t_position	h_pos;

	h_pos = g->world_map->hero_position;
	put_tile(g, "./textures/Floor/GRASS.xpm", h_pos.x * 64, h_pos.y * 64);
	if (g->footsteps % 2 == 0)
		put_tile(g, "./textures/Character/RIGHT_LEFT.xpm",
			(h_pos.x + 1) * 64, h_pos.y * 64);
	else
		put_tile(g, "./textures/Character/RIGHT_RIGHT.xpm",
			(h_pos.x + 1) * 64, h_pos.y * 64);
	g->world_map->hero_position.x = h_pos.x + 1;
}

void	win(t_game *g)
{
	t_position	h_pos;

	h_pos = g->world_map->hero_position;
	if (g->world_map->layout[h_pos.y][h_pos.x] == 'C')
	{
		g->gathered_loot++;
		g->world_map->layout[h_pos.y][h_pos.x] = '0';
	}
	if (g->gathered_loot == g->world_map->treasures)
	{
		put_tile(g, "./textures/Exit/EXIT.xpm",
			g->world_map->escape_hatch.x * g->grid_tile.x,
			g->world_map->escape_hatch.y * g->grid_tile.y);
	}
	if (g->world_map->layout[h_pos.y][h_pos.x] == 'E'
		&& g->gathered_loot != g->world_map->treasures)
		return ;
	if (g->world_map->layout[h_pos.y][h_pos.x] == 'E'
		&& g->gathered_loot == g->world_map->treasures)
	{
		ft_printf("Victory!\n");
		ft_exit(g);
	}
}
