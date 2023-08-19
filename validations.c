/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 03:00:03 by azaaza            #+#    #+#             */
/*   Updated: 2023/08/19 03:07:54 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int validate_map_name(char *name) { return (1); }

int validate_args(int argc, char **argv, t_game *game) {
  if (argc != 2) {
    printf("Error\nInvalid number of arguments\n");
    return (0);
  }

  if (!validate_map_name(argv[2])) {
    return (0);
  }
  return (1);
}
