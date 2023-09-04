/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:58:50 by azaaza            #+#    #+#             */
/*   Updated: 2023/09/05 00:59:15 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int count_characters(t_map *map, char c) {
  int count;
  int i;
  int j;

  i = 0;
  count = 0;
  while (i < map->rows) {
    j = 0;
    while (map->map[i][j]) {
      if (map->map[i][j] == c)
        count++;
      j++;
    }
    i++;
  }
  return (count);
}

int **create_visited_arr(t_game *game) {
  int **visited;
  visited = (int **)malloc(sizeof(int *) * game->map.rows);
  if (!visited)
    return (NULL);
  int i;
  i = 0;

  while (i < game->map.rows) {
    visited[i] = (int *)malloc(game->map.columns * sizeof(int));
    if (!visited[i]) {
      free(visited);
      return (NULL);
    }
    i++;
  }
  return (visited);
}

void free_visited(int **visited, int size) {
  int i;
  i = 0;
  while (i < size) {
    free(visited[i]);
    i++;
  };
  free(visited);
}