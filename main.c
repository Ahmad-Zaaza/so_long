/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:31:40 by azaaza            #+#    #+#             */
/*   Updated: 2023/08/18 01:56:06 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main() {
  void *mlx;
  // void *win;
  t_image_data img;

  mlx = mlx_init();
  // win = mlx_new_window(mlx, 1920, 1080, "Hello world");
  img.img = mlx_new_image(mlx, 1920, 1080);

  img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.size_line,
                               &img.endian);

  // mlx_loop(mlx);
  return (0);
}