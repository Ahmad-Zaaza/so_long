
#include "so_long.h"

void init_player(t_game *game) {
  int height;
  int width;
  game->player.alive = 1;
  game->player.collectibles = 0;
  game->player.moves = 0;
  game->player.direction = 3;

  game->player.images[0] = mlx_xpm_file_to_image(
      game->mlx, "./assets/player/left.xpm", &width, &height);
  game->player.images[1] = mlx_xpm_file_to_image(
      game->mlx, "./assets/player/top.xpm", &width, &height);
  game->player.images[2] = mlx_xpm_file_to_image(
      game->mlx, "./assets/player/right.xpm", &width, &height);
  game->player.images[3] = mlx_xpm_file_to_image(
      game->mlx, "./assets/player/bottom.xpm", &width, &height);
}

void draw_player(t_game *game) {

  mlx_put_image_to_window(
      game->mlx, game->win, game->player.images[game->player.direction],
      game->player.col * TILE_SIZE, game->player.row * TILE_SIZE);
}