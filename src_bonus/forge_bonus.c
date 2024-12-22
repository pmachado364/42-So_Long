/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forge_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:27:13 by pmachado          #+#    #+#             */
/*   Updated: 2024/10/18 12:14:15 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	forge_game(t_game *g);
void	forge_img(t_game *g);
void	forge_map(t_game *g, char *file);

t_game	*ft_forge(char *file)
{
	t_game	*g;

	g = malloc(sizeof(t_game));
	if (!g)
		ft_end(3, g);
	forge_game(g);
	forge_map(g, file);
	forge_img(g);
	return (g);
}

void	forge_game(t_game *g)
{
	g->world_map = NULL;
	g->gathered_loot = 0;
	g->footsteps = 0;
	g->render_pos.x = -1;
	g->render_pos.y = -1;
}

void	forge_map(t_game *g, char *file)
{
	create_map(g, file);
	parse_map(g);
}

void	forge_img(t_game *g)
{
	g->pixel_magic = mlx_init();
	if (!g->pixel_magic)
		ft_end(5, g);
	g->view_portal = NULL;
	g->art_asset.canvas = NULL;
	g->art_asset.data_stream = NULL;
	g->art_asset.pixel_intensity = 0;
	g->art_asset.row_length = 0;
	g->art_asset.byte_order = 0;
	g->grid_tile.y = 64;
	g->grid_tile.x = 64;
}
