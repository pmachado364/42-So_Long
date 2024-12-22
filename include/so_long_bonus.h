/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:26:31 by pmachado          #+#    #+#             */
/*   Updated: 2024/10/18 14:32:03 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <fcntl.h>
# include <stdio.h>
# include "../lib/Libft/libft.h"
# include "../include/errors_bonus.h"
# include "../lib/minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>

typedef struct s_position
{
	int			x;
	int			y;
}	t_position;

typedef struct s_map
{
	char		**layout;// 2D map layout
	int			treasures;// Total number of collectibles
	int			enemies;//enemies
	t_position	map_size;// Map width and height
	t_position	escape_hatch;// Exit position on the map
	t_position	hero_position;// Player's current position
}	t_map;

typedef struct s_img
{
	void		*canvas;// Pointer to the image buffer (MLX)
	char		*data_stream;// Pointer to image data stream
	int			pixel_intensity;// Bits per pixel (BPP)
	int			row_length;// Length of one row of pixels
	int			byte_order;// Endianness of pixel data
}	t_img;

typedef struct s_game
{
	t_map		*world_map;// Pointer to map struct
	int			gathered_loot;// Number of collected treasures
	int			footsteps;// Player's move count
	void		*pixel_magic;// Pointer to MLX instance
	void		*view_portal;// Pointer to window instance (MLX)
	t_position	render_pos;// Current position
	t_position	grid_tile;// Size of the grid tile (typically 64x64 pixels)
	t_img		art_asset;// Image asset struct
}	t_game;

//********FUNCTIONS********//

//	parsing arguments:
bool	ft_validate(int argc, char **argv);

//	spawn_game:
t_game	*ft_forge(char *file);
void	forge_game(t_game *g);
void	forge_map(t_game *g, char *file);
void	forge_img(t_game *g);

//	map:
void	create_map(t_game *g, char *file);
void	parse_map(t_game *g);

//	map_aux:
bool	parse_horizontal_borders(char **layout, int width, int row);
bool	parse_vertical_borders(char **layout, int height, int col);
void	flood_fill(char **map, t_game *game, int x, int y);
char	**duplicate_map(t_game *g);

//	error:
void	ft_end(int nbr, t_game *g);
void	free_all(t_game *g);
void	free_map(t_map *world_map);
void	free_array(char **array, int row);
int		ft_exit(t_game *g);

//	render:
void	render(t_game *g);
void	render_game_window(t_game *g);
void	render_world_map(t_game *g);
void	render_footstep_count(t_game *g);
void	render_corners(t_game *g, int x, int y);
void	render_borders(t_game *g, int x, int y);
void	render_tiles(t_game *g, int x, int y);
void	put_tile(t_game *g, char *tile, int x, int y);

//	movement:
int		keys_actions(int keysym, t_game *g);
void	move_up(t_game *g);
void	move_down(t_game *g);
void	move_left(t_game *g);
void	move_right(t_game *g);
void	up(t_game *g);
void	down(t_game *g);
void	left(t_game *g);
void	right(t_game *g);

void	win(t_game *g);

#endif