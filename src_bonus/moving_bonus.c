/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:44:49 by pmachado          #+#    #+#             */
/*   Updated: 2024/10/18 19:23:52 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	keys_actions(int keysym, t_game *g)
{
	if (keysym == XK_w || keysym == XK_Up)
		move_up(g);
	if (keysym == XK_s || keysym == XK_Down)
		move_down(g);
	if (keysym == XK_a || keysym == XK_Left)
		move_left(g);
	if (keysym == XK_d || keysym == XK_Right)
		move_right(g);
	if (keysym == XK_Escape)
		ft_exit(g);
	return (0);
}

void	move_up(t_game *g)
{
	t_position	h_pos;

	h_pos = g->world_map->hero_position;
	if ((g->world_map->layout[h_pos.y - 1][h_pos.x] == 'E'
		&& g->gathered_loot != g->world_map->treasures)
		|| g->world_map->layout[h_pos.y - 1][h_pos.x] == '1')
		return ;
	if (g->world_map->layout[h_pos.y - 1][h_pos.x] == 'V')
		ft_end(10, g);
	up(g);
	g->footsteps++;
	render_footstep_count(g);
	win(g);
}

void	move_down(t_game *g)
{
	t_position	h_pos;

	h_pos = g->world_map->hero_position;
	if ((g->world_map->layout[h_pos.y + 1][h_pos.x] == 'E'
		&& g->gathered_loot != g->world_map->treasures)
		|| g->world_map->layout[h_pos.y + 1][h_pos.x] == '1')
		return ;
	if (g->world_map->layout[h_pos.y + 1][h_pos.x] == 'V')
		ft_end(10, g);
	down(g);
	g->footsteps++;
	render_footstep_count(g);
	win(g);
}

void	move_left(t_game *g)
{
	t_position	h_pos;

	h_pos = g->world_map->hero_position;
	if ((g->world_map->layout[h_pos.y][h_pos.x - 1] == 'E'
		&& g->gathered_loot != g->world_map->treasures)
		|| g->world_map->layout[h_pos.y][h_pos.x - 1] == '1')
		return ;
	if (g->world_map->layout[h_pos.y][h_pos.x - 1] == 'V')
		ft_end(10, g);
	left(g);
	g->footsteps++;
	render_footstep_count(g);
	win(g);
}

void	move_right(t_game *g)
{
	t_position	h_pos;

	h_pos = g->world_map->hero_position;
	if ((g->world_map->layout[h_pos.y][h_pos.x + 1] == 'E'
		&& g->gathered_loot != g->world_map->treasures)
		|| g->world_map->layout[h_pos.y][h_pos.x + 1] == '1')
		return ;
	if (g->world_map->layout[h_pos.y][h_pos.x + 1] == 'V')
		ft_end(10, g);
	right(g);
	g->footsteps++;
	render_footstep_count(g);
	win(g);
}
