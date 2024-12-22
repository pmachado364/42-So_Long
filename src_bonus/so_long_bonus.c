/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmachado <pmachado@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 10:17:02 by pmachado          #+#    #+#             */
/*   Updated: 2024/11/06 21:36:32 by pmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_game	*g;

	if (!ft_validate(argc, argv))
		exit(1);
	g = ft_forge(argv[1]);
	if (g != NULL)
		render(g);
	ft_exit(g);
	return (0);
}