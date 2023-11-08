/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 01:14:07 by azaaza            #+#    #+#             */
/*   Updated: 2023/11/06 01:12:57 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	load_tiles(t_game *game)
{
	game->enemy.image = xpm_to_image(&game, "textures/world/enemy.xpm");
	game->tiles.wall = xpm_to_image(&game, "textures/world/rock.xpm");
	game->tiles.floor = xpm_to_image(&game, "textures/world/floor.xpm");
	game->tiles.exit = xpm_to_image(&game, "textures/world/exit.xpm");
	load_fonts(game);
	load_coin(game);
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
	if (game->tiles.floor)
		mlx_destroy_image(game->mlx, game->tiles.floor);
	if (game->tiles.exit)
		mlx_destroy_image(game->mlx, game->tiles.exit);
	if (game->tiles.wall)
		mlx_destroy_image(game->mlx, game->tiles.wall);
	if (game->enemy.image)
		mlx_destroy_image(game->mlx, game->enemy.image);
	destroy_fonts(game);
	destroy_coins(game);
}

void	init_images(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
		game->player.images[i++] = NULL;
	game->tiles.wall = NULL;
	i = 0;
	while (i < 14)
		game->tiles.collectible[i++] = NULL;
	i = 0;
	while (i < 10)
		game->fonts[i++] = NULL;
	game->tiles.floor = NULL;
	game->tiles.exit = NULL;
}
