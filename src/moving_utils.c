/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:06:35 by pmachado          #+#    #+#             */
/*   Updated: 2024/10/18 10:13:08 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	up(t_game *g)
{
	t_position	h_pos;

	h_pos = g->world_map->hero_position;
	put_tile(g, "./textures/Floor/GRASS.xpm", h_pos.x * 64, h_pos.y * 64);
	put_tile(g, "./textures/Character/FRONT.xpm",
		h_pos.x * 64, (h_pos.y - 1) * 64);
	g->world_map->hero_position.y = h_pos.y - 1;
}

void	down(t_game *g)
{
	t_position	h_pos;

	h_pos = g->world_map->hero_position;
	put_tile(g, "./textures/Floor/GRASS.xpm", h_pos.x * 64, h_pos.y * 64);
	put_tile(g, "./textures/Character/FRONT.xpm",
		h_pos.x * 64, (h_pos.y + 1) * 64);
	g->world_map->hero_position.y = h_pos.y + 1;
}

void	left(t_game *g)
{
	t_position	h_pos;

	h_pos = g->world_map->hero_position;
	put_tile(g, "./textures/Floor/GRASS.xpm", h_pos.x * 64, h_pos.y * 64);
	put_tile(g, "./textures/Character/FRONT.xpm",
		(h_pos.x - 1) * 64, h_pos.y * 64);
	g->world_map->hero_position.x = h_pos.x - 1;
}

void	right(t_game *g)
{
	t_position	h_pos;

	h_pos = g->world_map->hero_position;
	put_tile(g, "./textures/Floor/GRASS.xpm", h_pos.x * 64, h_pos.y * 64);
	put_tile(g, "./textures/Character/FRONT.xpm",
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
