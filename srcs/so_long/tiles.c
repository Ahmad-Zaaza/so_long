/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 01:14:07 by azaaza            #+#    #+#             */
/*   Updated: 2023/11/05 15:47:46 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_mandatory.h"

void	load_tiles(t_game *game)
{
	game->tiles.wall = xpm_to_image(&game, "textures/world/rock.xpm");
	game->tiles.collectible = xpm_to_image(&game,
											"textures/world/coin/coin.xpm");
	game->tiles.floor = xpm_to_image(&game, "textures/world/floor.xpm");
	game->tiles.exit = xpm_to_image(&game, "textures/world/exit.xpm");
}

void	destroy_tiles(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->player.images[i])
			mlx_destroy_image(game->mlx, game->player.images[i]);
		i++;
	}
	if (game->tiles.collectible)
		mlx_destroy_image(game->mlx, game->tiles.collectible);
	if (game->tiles.floor)
		mlx_destroy_image(game->mlx, game->tiles.floor);
	if (game->tiles.exit)
		mlx_destroy_image(game->mlx, game->tiles.exit);
	if (game->tiles.wall)
		mlx_destroy_image(game->mlx, game->tiles.wall);
}

void	init_images(t_game *game)
{
	int i;

	i = 0;
	while (i < 4)
		game->player.images[i++] = NULL;
	game->tiles.wall = NULL;
	game->tiles.collectible = NULL;
	game->tiles.floor = NULL;
	game->tiles.exit = NULL;
}