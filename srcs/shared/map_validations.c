/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 20:20:45 by azaaza            #+#    #+#             */
/*   Updated: 2023/09/16 13:40:01 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/so_long.h"


static int is_walls(char *str) {
  int i;

  i = 0;
  while (str[i]) {
    if (str[i] != '1')
      return (0);
    i++;
  }
  return (1);
}

int check_if_rectangular(t_map map) {
  int first_row_len;
  int row;

  first_row_len = ft_strlen(map.map[0]);
  row = 1;
  while (row < map.rows) {
    if (ft_strlen(map.map[row]) != first_row_len) {
      ft_printf("Error\nMap is not rectangular\n");
      return (0);
    }
    row++;
  }
  return (1);
}

int check_enclosed_by_walls(t_map map) {
  int row;

  row = 0;
  if (!is_walls(map.map[0]) || !is_walls(map.map[map.rows - 1])) {
    ft_printf("Error\nMap is not enclosed by walls\n");
    return (0);
  }
  while (row < map.rows) {
    if (map.map[row][0] != '1' || map.map[row][map.columns - 1] != '1') {
      ft_printf("Error\nMap is not enclosed by walls\n");
      return (0);
    }
    row++;
  }
  return (1);
}

static int has_valid_paths(t_game *game) {
  int **visited;
  int collected;
  int row;
  int col;

  visited = create_visited_arr(game);
  if (!visited)
    return (0);
  row = 0;
  col = 0;
  collected = 0;

  while (row < game->map.rows) {
    while (col < game->map.columns) {
      visited[row][col] = 0;
      col++;
    }
    row++;
  }
  if (dfs(game, &collected, visited, game->player.row, game->player.col)) {
    free_visited(visited, game->map.rows);
    return (1);
  }
  free_visited(visited, game->map.rows);
  ft_printf("Error\nMap has no valid paths\n");
  return (0);
}

int validate_map(t_game *game) {
  if (!check_if_rectangular(game->map) || !check_enclosed_by_walls(game->map) ||
      !has_valid_paths(game)) {
    return (0);
  }
  return (1);
}
