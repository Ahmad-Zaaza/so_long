/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 01:14:07 by azaaza            #+#    #+#             */
/*   Updated: 2023/11/01 00:02:22 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	load_tiles(t_game *game)
{
	game->enemy.image = xpm_to_image(&game, "textures/world/enemy.xpm");
	game->tiles.wall = xpm_to_image(&game, "textures/world/rock.xpm");
	game->tiles.floor = xpm_to_image(&game, "textures/world/floor.xpm");
	load_fonts(game);
	load_coin(game);
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
	mlx_destroy_image(game->mlx, game->enemy.image);
	destroy_fonts(game);
	destroy_coins(game);
}
