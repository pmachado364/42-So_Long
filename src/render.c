/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 11:06:43 by pmachado          #+#    #+#             */
/*   Updated: 2024/10/16 13:47:48 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	render_game_window(t_game *g);
void	render_world_map(t_game *g);

void	render(t_game *g)
{
	render_game_window(g);
	if (!g->view_portal)
		ft_end(5, g);
	render_world_map(g);
	mlx_hook(g->view_portal, KeyPress, KeyPressMask, &keys_actions, g);
	mlx_hook(g->view_portal, DestroyNotify, StructureNotifyMask, &ft_exit,
		g);
	mlx_loop(g->pixel_magic);
}

void	render_game_window(t_game *g)
{
	if (g->pixel_magic == NULL)
		ft_end(5, g);
	g->view_portal = mlx_new_window(g->pixel_magic,
			(g->world_map->map_size.x * 64),
			(g->world_map->map_size.y * 64), "so_long");
	if (g->view_portal == NULL)
		ft_end(5, g);
	g->art_asset.canvas = mlx_new_image(g->pixel_magic,
			g->world_map->map_size.x * 64,
			g->world_map->map_size.y * 64);
	g->art_asset.data_stream = mlx_get_data_addr(g->art_asset.canvas,
			&g->art_asset.pixel_intensity, &g->art_asset.row_length,
			&g->art_asset.byte_order);
}

void	render_world_map(t_game *g)
{
	g->render_pos.y = -1;
	while (++g->render_pos.y < g->world_map->map_size.y)
	{
		g->render_pos.x = -1;
		while (++g->render_pos.x < g->world_map->map_size.x)
		{
			render_corners(g, g->render_pos.x, g->render_pos.y);
			render_borders(g, g->render_pos.x, g->render_pos.y);
			render_tiles(g, g->render_pos.x, g->render_pos.y);
		}
	}
}
