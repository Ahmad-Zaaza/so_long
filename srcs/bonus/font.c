/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   font.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 00:18:24 by azaaza            #+#    #+#             */
/*   Updated: 2023/11/05 19:38:26 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	load_fonts(t_game *game)
{
	int		i;
	char	filename[22];

	i = 0;
	while (i < 10)
	{
		snprintf(filename, 22, "textures/fonts/%d.xpm", i);
		game->fonts[i] = xpm_to_image(&game, filename);
		i++;
	}
}

void	ft_put_font(t_game *game, int digit, int i)
{
	void	*font;

	font = game->fonts[digit];
	mlx_put_image_to_window(game->mlx, game->win, font, game->map.rows / 2 + 64
		- 12 * i, game->map.columns / 4);
}

void	destroy_fonts(t_game *game)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (game->fonts[i])
			mlx_destroy_image(game->mlx, game->fonts[i]);
		i++;
	}
}
void	draw_movements(t_game *game)
{
	int i;
	int digit;
	int moves;

	moves = game->player.moves;
	i = 0;
	while (i < 4)
	{
		digit = moves % 10;
		moves /= 10;
		ft_put_font(game, digit, i);
		i++;
	}
}