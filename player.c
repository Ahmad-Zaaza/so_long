
#include "so_long.h"

void init_player(t_game *game) {
  int height;
  int width;

  game->player.alive = 1;
  game->player.collectables_gathered = 0;
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

void handle_move_player(int key, t_game *game) {
  int p_col;
  int new_row;
  int p_row;
  int new_col;
  if (key == 13)
    move_player(game, game->player.row - 1, game->player.col, 1);
  else if (key == 0)
    move_player(game, game->player.row, game->player.col - 1, 0);
  else if (key == 1)
    move_player(game, game->player.row + 1, game->player.col, 3);
  else if (key == 2)
    move_player(game, game->player.row, game->player.col + 1, 2);
}
