/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image_pixel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 01:32:56 by azaaza            #+#    #+#             */
/*   Updated: 2023/08/18 01:56:03 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void put_image_pixel(t_image_data *data, int x, int y, int color) {
  char *pixel_position;

  pixel_position =
      data->addr + (y * data->size_line) + (x * data->bits_per_pixel / 8);
  *(unsigned int *)pixel_position = color;
}