/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <blefebvr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:08:11 by blefebvr          #+#    #+#             */
/*   Updated: 2022/11/22 16:11:05 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_errors(t_data *game)
{
	if (game->map)
	{
		if (check_size(game) == 0 || game->y < 4)
			ft_printf("Map of Invalid Size\n");
		else if (!(check_walls_y(game)) || !(check_walls_y(game)))
			ft_printf("Invalid map contour\n");
		else if (!(check_data(game)))
			ft_printf("Invalid Data\n");
	if (ft_strstr(av[1], ".ber") == NULL)
	{
		ft_printf("Invalid File\n");
		free(game);
		return 0;
	}
	if (fd < 0)
		printf("FD incorrect\n");
		
		return (0);
	}
}