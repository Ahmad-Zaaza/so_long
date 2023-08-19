/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 01:20:47 by azaaza            #+#    #+#             */
/*   Updated: 2023/08/19 03:07:54 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_image_data {
  void *img;
  char *addr;
  int endian;
  int bits_per_pixel;
  int size_line;

} t_image_data;

typedef struct s_map {
  char *map_path;
  int rows;
  int columns;
} t_map;

typedef struct s_game {
  void *mlx;
  void *win;
  t_map map;
} t_game;

int validate_args(int argc, char **argv, t_game *game);

void put_image_pixel(t_image_data *data, int x, int y, int color);
void draw_square(t_image_data *data, int size, int color);

// Color utils
int create_trgb(int t, int r, int g, int b);
int get_t(int trgb);
int get_r(int trgb);
int get_g(int trgb);
int get_b(int trgb);

// utils

int ft_strcmp(char *s1, char *s2);

#endif