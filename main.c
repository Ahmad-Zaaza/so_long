/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:31:40 by azaaza            #+#    #+#             */
/*   Updated: 2023/08/18 02:18:08 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "so_long.h"

void draw_triangle(t_image_data *data, int size, int color) {
  int x, y;

  for (y = 0; y < size; y++) {
    for (x = 0; x < size - y; x++) {
      put_image_pixel(data, x + (size - y) / 2, y, color);
    }
  }
}

int main() {
  void *mlx;
  void *win;
  t_image_data img;

  mlx = mlx_init();
  win = mlx_new_window(mlx, 1920, 1080, "Hello world");
  img.img = mlx_new_image(mlx, 1920, 1080);

  img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.size_line,
                               &img.endian);
  // draw_square(&img, 250, 0x00FF00);
  draw_triangle(&img, 250, 0x00FF00);

  mlx_put_image_to_window(mlx, win, img.img, 200, 200);
  mlx_loop(mlx);
  return (0);
}
