/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   font.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 00:18:24 by azaaza            #+#    #+#             */
/*   Updated: 2023/10/31 00:04:22 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	load_fonts(t_game *game)
{
	int		size;
	int		i;
	char	filename[21];

	i = 0;
	while (i < 10)
	{
		sprintf(filename, "textures/fonts/%d.xpm", i);
		game->fonts[i] = xpm_to_image(&game, filename);
		i++;
	}
}

void	ft_put_font(t_game *game, int digit, int i)
{
	void	*font;

	font = game->fonts[i];
	mlx_put_image_to_window(game->mlx, game->win, font, game->map.rows / 2 + 64
		- 12 * i, game->map.columns / 4);
}

void	destroy_fonts(t_game *game)
{
	int	i;

	i = 0;
	while (i < 10)
		mlx_destroy_image(game->mlx, game->fonts[i]);
}
