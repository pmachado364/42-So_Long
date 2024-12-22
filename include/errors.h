/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:16:43 by pmachado          #+#    #+#             */
/*   Updated: 2024/10/15 18:45:40 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include "../include/so_long.h"

# define ERROR_NBR_ARGS "Error: Invalid number of arguments\n"
# define ERROR_INVALID_EXTENSION "Error: Invalid file extension\n"
# define ERROR_MALLOC "Error: Memory allocation failed\n"
# define ERROR_FD "Error: Invalid fd\n"
# define ERROR_MLX_INIT "Error: MLX initialization failure\n"
# define ERROR_MAP_PROCESSING "Error processing map\n"
# define ERROR_MAP_RECT "Error: Map is not rectangular\n"
# define ERROR_MAP_INVALID "Error: Invalid map\n"
# define ERROR_MAP_PATH "Error: Path is invalid\n"

#endif