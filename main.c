/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:31:40 by azaaza            #+#    #+#             */
/*   Updated: 2023/08/19 01:47:59 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "so_long.h"
#include <stdio.h>

// key codes:
// 53: esc
// 123: left arrow
// 124: right arrow
// 125: down arrow
// 126: up arrow
// 13: w
// 0: a
// 1: s
// 2: d

/**
 key codes:
 53: esc;
 123: left arrow;
 124: right arrow;
 125: down arrow;
 126: up arrow;
 13: w;
 0: a;
 1: s;
 2: d;

*/
int key_hook(int key_code, t_game *game) {
  printf("key: %d\n", key_code);
  if (key_code == 53)
    exit(0);
  return (0);
}
void setup_key_listeners(t_game *game) {
  mlx_key_hook(game->win, key_hook, game);
}

int main() {

  int color;
  t_game game;
  t_image_data img;

  game.mlx = mlx_init();
  game.win = mlx_new_window(game.mlx, 1920, 1080, "Hello world");
  img.img = mlx_new_image(game.mlx, 1920, 1080);

  img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.size_line,
                               &img.endian);
  color = create_trgb(1, 255, 255, 255);
  printf("%d\n", get_b(color));
  draw_square(&img, 250, color);
  setup_key_listeners(&game);
  mlx_put_image_to_window(game.mlx, game.win, img.img, 200, 200);
  mlx_loop(game.mlx);
  return (0);
}
