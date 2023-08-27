/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 01:14:07 by azaaza            #+#    #+#             */
/*   Updated: 2023/08/27 14:02:45 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "so_long.h"

void draw_tiles(t_game *game) {

  int col;
  int row;

  row = 0;

  while (row < game->map.rows) {
    col = 0;
    while (col < game->map.columns) {
      if (game->map.map[row][col] == '1') {
        mlx_put_image_to_window(game->mlx, game->win, game->tiles.wall,
                                col * TILE_SIZE, row * TILE_SIZE);
      } else if (game->map.map[row][col] == '0') {
        mlx_put_image_to_window(game->mlx, game->win, game->tiles.floor,
                                col * TILE_SIZE, row * TILE_SIZE);
      }
      col++;
    }
    row++;
  }
}

void load_tiles(t_game *game) {

  int width;
  int height;

  game->tiles.wall = mlx_xpm_file_to_image(game->mlx, "./assets/world/tree.xpm",
                                           &width, &height);
  game->tiles.floor = mlx_xpm_file_to_image(
      game->mlx, "./assets/world/grass.xpm", &width, &height);
}