/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   font.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 00:18:24 by azaaza            #+#    #+#             */
/*   Updated: 2023/08/30 00:51:55 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void draw_movements(t_game *game) {
  int i;
  int digit;
  int moves;

  moves = game->player.moves;
  i = 0;
  while (i < 4) {
    digit = moves % 10;
    moves /= 10;
    ft_put_font(game, digit, i);
    i++;
  }
}

void load_fonts(t_game *game) {
  int size;
  game->font.zero =
      mlx_xpm_file_to_image(game->mlx, "assets/fonts/0.xpm", &size, &size);
  game->font.one =
      mlx_xpm_file_to_image(game->mlx, "assets/fonts/1.xpm", &size, &size);
  game->font.two =
      mlx_xpm_file_to_image(game->mlx, "assets/fonts/2.xpm", &size, &size);
  game->font.three =
      mlx_xpm_file_to_image(game->mlx, "assets/fonts/3.xpm", &size, &size);
  game->font.four =
      mlx_xpm_file_to_image(game->mlx, "assets/fonts/4.xpm", &size, &size);
  game->font.five =
      mlx_xpm_file_to_image(game->mlx, "assets/fonts/5.xpm", &size, &size);
  game->font.six =
      mlx_xpm_file_to_image(game->mlx, "assets/fonts/6.xpm", &size, &size);
  game->font.seven =
      mlx_xpm_file_to_image(game->mlx, "assets/fonts/7.xpm", &size, &size);
  game->font.eight =
      mlx_xpm_file_to_image(game->mlx, "assets/fonts/8.xpm", &size, &size);
  game->font.nine =
      mlx_xpm_file_to_image(game->mlx, "assets/fonts/9.xpm", &size, &size);
}

void ft_put_font(t_game *game, int digit, int i) {
  void *font;

  font = NULL;
  if (digit == 0)
    font = game->font.zero;
  if (digit == 1)
    font = game->font.one;
  if (digit == 2)
    font = game->font.two;
  if (digit == 3)
    font = game->font.three;
  if (digit == 4)
    font = game->font.four;
  if (digit == 5)
    font = game->font.five;
  if (digit == 6)
    font = game->font.six;
  if (digit == 7)
    font = game->font.seven;
  if (digit == 8)
    font = game->font.eight;
  if (digit == 9)
    font = game->font.nine;
  mlx_put_image_to_window(game->mlx, game->win, font,
                          game->map.rows / 2 + 64 - 12 * i,
                          game->map.columns / 4);
}

void destroy_fonts(t_game *game) {
  mlx_destroy_image(game->mlx, game->tiles.grass);
  mlx_destroy_image(game->mlx, game->tiles.bush);
  mlx_destroy_image(game->mlx, game->tiles.dirt);
  mlx_destroy_image(game->mlx, game->tiles.vertical_fence);
  mlx_destroy_image(game->mlx, game->tiles.horizontal_fence);
  mlx_destroy_image(game->mlx, game->player.images[0]);
  mlx_destroy_image(game->mlx, game->player.images[1]);
  mlx_destroy_image(game->mlx, game->player.images[2]);
  mlx_destroy_image(game->mlx, game->player.images[3]);
}