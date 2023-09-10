/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 01:14:07 by azaaza            #+#    #+#             */
/*   Updated: 2023/09/10 01:39:18 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "so_long.h"

void draw_wall(t_game *game, int row, int col) {
  mlx_put_image_to_window(game->mlx, game->win, game->tiles.wall,
                          col * TILE_SIZE, row * TILE_SIZE);
  //   if (row == 0 || row == game->map.rows - 1) {
  //     mlx_put_image_to_window(game->mlx, game->win,
  //     game->tiles.vertical_fence,
  //                             col * TILE_SIZE, row * TILE_SIZE);
  //   } else if (col == 0 || col == game->map.columns - 1) {
  //     mlx_put_image_to_window(game->mlx, game->win,
  //     game->tiles.horizontal_fence,
  //                             col * TILE_SIZE, row * TILE_SIZE);
  //   } else {
  //     mlx_put_image_to_window(game->mlx, game->win, game->tiles.bush,
  //                             col * TILE_SIZE, row * TILE_SIZE);
  //   }
}

void draw_tiles(t_game *game) {
  int col;
  int row;

  row = 0;
  while (row < game->map.rows) {
    col = 0;
    while (col < game->map.columns) {
      if (game->map.map[row][col] == '1') {
        draw_wall(game, row, col);
      } else if (game->map.map[row][col] == 'C') {
        mlx_put_image_to_window(game->mlx, game->win, game->tiles.floor,
                                col * TILE_SIZE, row * TILE_SIZE);
        mlx_put_image_to_window(game->mlx, game->win, game->tiles.collectible,
                                col * TILE_SIZE, row * TILE_SIZE);
      } else if (game->map.map[row][col] == '0' ||
                 game->map.map[row][col] == 'P') {
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

  game->tiles.wall = mlx_xpm_file_to_image(game->mlx, "./assets/world/rock.xpm",
                                           &width, &height);
  game->tiles.collectible = mlx_xpm_file_to_image(
      game->mlx, "./assets/world/coin/coin.xpm", &width, &height);
  game->tiles.floor = mlx_xpm_file_to_image(
      game->mlx, "./assets/world/floor.xpm", &width, &height);
}

void destroy_tiles(t_game *game) {
  mlx_destroy_image(game->mlx, game->tiles.floor);
  mlx_destroy_image(game->mlx, game->tiles.wall);
  mlx_destroy_image(game->mlx, game->tiles.collectible);
  mlx_destroy_image(game->mlx, game->player.images[0]);
  mlx_destroy_image(game->mlx, game->player.images[1]);
  mlx_destroy_image(game->mlx, game->player.images[2]);
  mlx_destroy_image(game->mlx, game->player.images[3]);
}