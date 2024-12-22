/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 08:36:45 by pmachado          #+#    #+#             */
/*   Updated: 2024/10/18 19:22:53 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	put_tile(t_game *g, char *tile, int x, int y)
{
	if (g->art_asset.canvas)
	{
		mlx_destroy_image(g->pixel_magic, g->art_asset.canvas);
		g->art_asset.canvas = NULL;
	}
	g->art_asset.canvas = mlx_xpm_file_to_image(g->pixel_magic, tile,
			&g->grid_tile.x, &g->grid_tile.y);
	if (!g->art_asset.canvas)
		ft_end(5, g);
	mlx_put_image_to_window(g->pixel_magic, g->view_portal,
		g->art_asset.canvas, x, y);
}

void	render_corners(t_game *g, int x, int y)
{
	if (y == 0 && x == 0)
		put_tile(g, "./textures/Borders/GRASS_CORNER_LEFT_UP.xpm",
			x * 64, y * 64);
	else if (y == 0 && x == g->world_map->map_size.x - 1)
		put_tile(g, "./textures/Borders/GRASS_CORNER_RIGHT_UP.xpm",
			x * 64, y * 64);
	else if (y == g->world_map->map_size.y - 1 && x == 0)
		put_tile(g, "./textures/Borders/GRASS_CORNER_LEFT_DOWN.xpm",
			x * 64, y * 64);
	else if (y == g->world_map->map_size.y - 1
		&& x == g->world_map->map_size.x - 1)
		put_tile(g, "./textures/Borders/GRASS_CORNER_RIGHT_DOWN.xpm",
			x * 64, y * 64);
}

void	render_borders(t_game *g, int x, int y)
{
	if (y == 0 && x > 0 && x < g->world_map->map_size.x - 1)
		put_tile(g, "./textures/Borders/GRASS_BORDER_TOP.xpm",
			x * 64, y * 64);
	else if (y > 0 && y < g->world_map->map_size.y - 1 && x == 0)
		put_tile(g, "./textures/Borders/GRASS_BORDER_LEFT.xpm",
			x * 64, y * 64);
	else if (y > 0 && y < g->world_map->map_size.y - 1
		&& x == g->world_map->map_size.x - 1)
		put_tile(g, "./textures/Borders/GRASS_BORDER_RIGHT.xpm",
			x * 64, y * 64);
	else if (y == g->world_map->map_size.y - 1 && x > 0
		&& x < g->world_map->map_size.x - 1)
		put_tile(g, "./textures/Borders/GRASS_BORDER_BOTTOM.xpm",
			x * 64, y * 64);
}

void	render_tiles(t_game *g, int x, int y)
{
	char	tile;

	tile = g->world_map->layout[y][x];
	if (tile == '1' && y > 0 && y < g->world_map->map_size.y - 1
		&& x > 0 && x < g->world_map->map_size.x - 1)
		put_tile(g, "./textures/Floor/log.xpm", x * 64, y * 64);
	else if (tile == '0')
		put_tile(g, "./textures/Floor/GRASS.xpm", x * 64, y * 64);
	else if (tile == 'P')
		put_tile(g, "./textures/Character/FRONT.xpm", x * 64, y * 64);
	else if (tile == 'E')
		put_tile(g, "./textures/Exit/BLOCKED_EXIT.xpm", x * 64, y * 64);
	else if (tile == 'C')
		put_tile(g, "./textures/Collectibles/EGG_NEST.xpm", x * 64, y * 64);
	else if (tile == 'V')
		put_tile(g, "./textures/Character/Enemy.xpm", x * 64, y * 64);
}
