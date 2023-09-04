/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 22:16:53 by azaaza            #+#    #+#             */
/*   Updated: 2023/09/05 01:00:23 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int is_valid_path(t_map *map, int **visited, int row, int col) {
  if (map->map[row][col] == '1' || visited[row][col] == 1) {
    return (0);
  }
  return (1);
}

int dfs(t_game *game, int *collected, int **visited, int row, int col) {
  int moves[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  visited[row][col] = 1;
  int i;
  int new_row;
  int new_col;
  if (game->map.map[row][col] == 'C') {
    *collected += 1;
  }
  if (*collected == game->map.collectibles && game->map.map[row][col] == 'E') {
    return (1);
  }
  i = 0;
  while (i < 4) {
    new_row = row + moves[i][0];
    new_col = col + moves[i][1];
    if (is_valid_path(&game->map, visited, new_row, new_col)) {
      if (dfs(game, collected, visited, new_row, new_col)) {
        return (1);
      }
    }
    i++;
  }
  return (0);
}