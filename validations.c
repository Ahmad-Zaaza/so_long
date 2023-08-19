/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 03:00:03 by azaaza            #+#    #+#             */
/*   Updated: 2023/08/20 02:43:31 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int validate_map_name(char *name) {
  int len;

  len = ft_strlen(name);

  if (ft_strcmp(name + len - 4, ".ber") != 0) {
    ft_printf("Error\nInvalid map name\n");
    return (0);
  }
  return (1);
}

int parse_map(char *name, t_game *game) {
  int fd;
  char *line;

  init_map_queue(&game->queue);

  fd = open(name, O_RDONLY);
  if (fd < 0) {
    ft_printf("Error\n Cannot open map or invalid map name\n");
    return (0);
  }
  line = get_next_line(fd);
  while (line) {
  }
}

int validate_args(int argc, char **argv, t_game *game) {
  if (argc != 2) {
    ft_printf("Error\nInvalid number of arguments\n");
    return (0);
  }
  // validate map name
  if (!validate_map_name(argv[2]) || !parse_map(argv[2], game)) {
    return (0);
  }
  return (1);
}
