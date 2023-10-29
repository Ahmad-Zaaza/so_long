/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 01:14:07 by azaaza            #+#    #+#             */
/*   Updated: 2023/10/28 17:49:17 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include <stdio.h>

void	load_tiles(t_game *game)
{
	game->tiles.wall = xpm_to_image(&game, "textures/world/rock.xpm");
	game->tiles.collectible[0] = xpm_to_image(&game,
			"textures/world/coin/coin0.xpm");
	game->tiles.collectible[1] = xpm_to_image(&game,
			"textures/world/coin/coin1.xpm");
	game->tiles.collectible[2] = xpm_to_image(&game,
			"textures/world/coin/coin2.xpm");
	game->tiles.collectible[3] = xpm_to_image(&game,
			"textures/world/coin/coin3.xpm");
	game->tiles.collectible[4] = xpm_to_image(&game,
			"textures/world/coin/coin4.xpm");
	game->tiles.collectible[5] = xpm_to_image(&game,
			"textures/world/coin/coin5.xpm");
	game->tiles.collectible[6] = xpm_to_image(&game,
			"textures/world/coin/coin6.xpm");
	game->tiles.collectible[7] = xpm_to_image(&game,
			"textures/world/coin/coin7.xpm");
	game->tiles.collectible[8] = xpm_to_image(&game,
			"textures/world/coin/coin8.xpm");
	game->tiles.collectible[9] = xpm_to_image(&game,
			"textures/world/coin/coin9.xpm");
	game->tiles.collectible[10] = xpm_to_image(&game,
			"textures/world/coin/coin10.xpm");
	game->tiles.floor = xpm_to_image(&game, "textures/world/floor.xpm");
}

void	destroy_tiles(t_game *game)
{
	mlx_destroy_image(game->mlx, game->tiles.floor);
	mlx_destroy_image(game->mlx, game->tiles.wall);
	mlx_destroy_image(game->mlx, game->tiles.collectible[0]);
	mlx_destroy_image(game->mlx, game->player.images[0]);
	mlx_destroy_image(game->mlx, game->player.images[1]);
	mlx_destroy_image(game->mlx, game->player.images[2]);
	mlx_destroy_image(game->mlx, game->player.images[3]);
}
