/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:31:40 by azaaza            #+#    #+#             */
/*   Updated: 2023/08/20 01:58:18 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
  ft_printf("key: %d\n", key_code);
  if (key_code == 53)
    exit(0);
  return (0);
}
void setup_key_listeners(t_game *game) {
  mlx_key_hook(game->win, key_hook, game);
}

int render_next_frame(void *params) { ft_printf("rendering next frame\n"); }

int main(int argc, char **argv) {

  t_game game;

  // args and map validation
  if (validate_args(argc, argv, &game)) {

    game.mlx = mlx_init();
    game.win = mlx_new_window(game.mlx, 200, 200, "Hello world");

    setup_key_listeners(&game);

    mlx_loop_hook(game.mlx, render_next_frame, NULL);
    mlx_loop(game.mlx);
  }
  return (0);
}
