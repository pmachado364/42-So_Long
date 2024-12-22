/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forge_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:37:01 by pmachado          #+#    #+#             */
/*   Updated: 2024/11/04 14:14:41 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	process_map_line(t_game *g, char *line, int row);
static void	init_map(t_game *g, char *file);
static int	count_rows(char *file);

void	create_map(t_game *g, char *file)
{
	char	*line;
	int		fd;
	int		i;

	init_map(g, file);
	i = -1;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_end(4, g);
	while (i++ < g->world_map->map_size.y)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		process_map_line(g, line, i);
		free(line);
	}
	g->world_map->layout[i] = NULL;
	if (g->world_map->map_size.x == g->world_map->map_size.y)
		ft_end(7, g);
	close(fd);
}

static void	process_map_line(t_game *g, char *line, int row)
{
	g->world_map->layout[row] = ft_strtrim(line, "\n");
	if (!g->world_map->layout[row])
		ft_end(6, g);
	if (row == 0)
		g->world_map->map_size.x = (int)ft_strlen(g->world_map->layout[row]);
	else if ((int)ft_strlen(g->world_map->layout[row])
		!= g->world_map->map_size.x)
		ft_end(7, g);
}

static void	init_map(t_game *g, char *file)
{
	g->world_map = malloc(sizeof(t_map));
	if (!g->world_map)
		ft_end(3, g);
	g->world_map->map_size.y = count_rows(file);
	g->world_map->layout = (char **)ft_calloc
		(g->world_map->map_size.y + 1, sizeof(char *));
	if (!g->world_map->layout)
		ft_end(3, g);
	g->world_map->enemies = 0;
}

static int	count_rows(char *file)
{
	int		i;
	int		fd;
	char	*tmp;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_end(4, NULL);
	tmp = get_next_line(fd);
	while (tmp)
	{
		i++;
		free(tmp);
		tmp = get_next_line(fd);
	}
	close(fd);
	return (i);
}
