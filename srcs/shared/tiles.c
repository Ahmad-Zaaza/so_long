/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 01:14:07 by azaaza            #+#    #+#             */
/*   Updated: 2023/10/31 00:26:47 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_mandatory.h"

void	load_tiles(t_game *game)
{
	game->tiles.wall = xpm_to_image(&game, "textures/world/rock.xpm");
	game->tiles.collectible = xpm_to_image(&game,
			"textures/world/coin/coin.xpm");
	game->tiles.floor = xpm_to_image(&game, "textures/world/floor.xpm");
}

void	destroy_tiles(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(game->mlx, game->player.images[i]);
		i++;
	}
	mlx_destroy_image(game->mlx, game->tiles.floor);
	mlx_destroy_image(game->mlx, game->tiles.wall);
}
