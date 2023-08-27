/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 02:17:56 by azaaza            #+#    #+#             */
/*   Updated: 2023/08/27 16:21:51 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

static void move_player_up(t_game *game) {
  printf("move player up\n");
  int p_col;
  int new_row;
  p_col = game->player.col;
  new_row = game->player.row - 1;
  if (game->map.map[new_row][p_col] != '1') {
    game->player.row = new_row;
    game->player.moves++;
    game->player.direction = 1;
  }
}
static void move_player_down(t_game *game) {
  printf("move player down\n");
  int p_col;
  int new_row;
  p_col = game->player.col;
  new_row = game->player.row + 1;
  if (game->map.map[new_row][p_col] != '1') {
    game->player.row = new_row;
    game->player.moves++;
    game->player.direction = 3;
  }
}
static void move_player_right(t_game *game) {
  printf("move player right\n");
  int p_row;
  int new_col;
  p_row = game->player.row;
  new_col = game->player.col + 1;
  if (game->map.map[p_row][new_col] != '1') {
    game->player.col = new_col;
    game->player.moves++;
    game->player.direction = 2;
  }
}
static void move_player_left(t_game *game) {
  printf("move player left\n");
  int p_row;
  int new_col;
  p_row = game->player.row;
  new_col = game->player.col - 1;
  if (game->map.map[p_row][new_col] != '1') {
    game->player.col = new_col;
    game->player.moves++;
    game->player.direction = 0;
  }
}

void handle_move_player(int key, t_game *game) {
  if (key == 13)
    move_player_up(game);
  else if (key == 0)
    move_player_left(game);
  else if (key == 1)
    move_player_down(game);
  else if (key == 2)
    move_player_right(game);
}
