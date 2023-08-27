/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 01:14:07 by azaaza            #+#    #+#             */
/*   Updated: 2023/08/27 12:51:06 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "so_long.h"

static void draw_tile(t_game *game, int row, int col) {

  if (game->map.map[row][col] == '1') {
    mlx_put_image_to_window(game->mlx, game->win, game->tiles.wall,
                            col * TILE_SIZE, row * TILE_SIZE);
  } else if (game->map.map[row][col] == '0') {
    mlx_put_image_to_window(game->mlx, game->win, game->tiles.floor,
                            col * TILE_SIZE, row * TILE_SIZE);

  } else if (game->map.map[row][col] == 'P') {
    mlx_put_image_to_window(game->mlx, game->win, game->tiles.floor,
                            col * TILE_SIZE, row * TILE_SIZE);
    mlx_put_image_to_window(
        game->mlx, game->win, game->player.images[game->player.direction],
        game->player.col * TILE_SIZE, game->player.row * TILE_SIZE);
  }
}

void load_and_draw_tiles(t_game *game) {

  int width;
  int height;
  int col;
  int row;
  game->tiles.wall = mlx_xpm_file_to_image(game->mlx, "./assets/world/tree.xpm",
                                           &width, &height);
  game->tiles.floor = mlx_xpm_file_to_image(
      game->mlx, "./assets/world/grass.xpm", &width, &height);
  row = 0;
  while (row < game->map.rows) {
    col = 0;
    while (col < game->map.columns) {
      draw_tile(game, row, col);
      col++;
    }
    row++;
  }
}
