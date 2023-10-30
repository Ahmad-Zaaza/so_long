/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 00:11:27 by ahmadzaaza        #+#    #+#             */
/*   Updated: 2023/10/31 00:21:56 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	load_coin(t_game *game)
{
	int		i;
	char	filename[30];

	i = 0;
	while (i < 14)
	{
		sprintf(filename, "textures/world/coin/coin%d.xpm", i);
		game->tiles.collectible[i] = xpm_to_image(&game, filename);
		i++;
	}
}

static void	draw_coin(t_game *game, int row, int col)
{
	clock_t	c;

	c = clock();
	draw_floor(game, row + 1, col);
	mlx_put_image_to_window(game->mlx, game->win, game->tiles.collectible[(c
			/ 100000) % 11], col * TILE_SIZE, (row + 1) * TILE_SIZE);
}

void	destroy_coins(t_game *game)
{
	int	i;

	i = 0;
	while (i < 14)
	{
		mlx_destroy_image(game->mlx, game->tiles.collectible[i]);
		i++;
	}
}
