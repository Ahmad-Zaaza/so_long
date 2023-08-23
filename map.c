/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 20:55:30 by azaaza            #+#    #+#             */
/*   Updated: 2023/08/23 21:35:46 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/include/ft_printf.h"
#include "libft/libft.h"
#include "so_long.h"

void init_map(t_map *map) {
  map->columns = 0;
  map->rows = 0;
  map->map = NULL;
  map->map_path = NULL;
}

void parse_map_from_queue(t_game *game) {
  char **map_data;
  int len;
  int i;

  i = 0;
  len = queue_size(&game->queue);
  ft_printf("row count: %d\n", len);
  map_data = (char **)malloc((len + 1) * sizeof(char *));
  if (!map_data) {
    ft_printf("Error:\n Cannot allocate memory for map\n");
    exit(1);
  }
  while (i < len) {
    map_data[i] = dequeue(&game->queue);
    i++;
  }
  map_data[i] = "\0";
  game->map.map = map_data;

  i = 0;
  while (i < len) {
    ft_printf("%s\n", game->map.map[i]);
    i++;
  }
}