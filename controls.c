/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 02:17:56 by azaaza            #+#    #+#             */
/*   Updated: 2023/08/29 21:55:21 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/include/ft_printf.h"
#include "so_long.h"
#include <stdio.h>

void move_player(t_game *game, int row, int col, int new_direction) {
  if (game->map.map[row][col] == '1')
    return;
  if (game->map.map[row][col] == 'C') {
    game->map.map[row][col] = '0';
    game->player.collectables_gathered++;
  }

  game->player.row = row;
  game->player.col = col;
  game->player.moves++;
  game->player.direction = new_direction;
  ft_printf("Player moves:%d\n", game->player.moves);
}
