/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 02:16:06 by azaaza            #+#    #+#             */
/*   Updated: 2023/08/18 02:16:31 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void draw_square(t_image_data *data, int size, int color) {
  int x;
  int y;

  x = 0;
  y = 0;

  while (y < size) {
    while (x < size) {
      put_image_pixel(data, x, y, color);
      x++;
    }
    x = 0;
    y++;
  }
}