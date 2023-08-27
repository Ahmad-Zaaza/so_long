/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaaza <azaaza@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 01:20:47 by azaaza            #+#    #+#             */
/*   Updated: 2023/08/27 12:47:32 by azaaza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "./ft_printf/include/ft_printf.h"
#include "./get_next_line/get_next_line.h"
#include "./libft/libft.h"
#include "./mlx/mlx.h"
#include <fcntl.h>
#include <stdlib.h>

#ifndef TILE_SIZE
#define TILE_SIZE 32
#endif

typedef struct s_image_data {
  void *img;
  char *addr;
  int endian;
  int bits_per_pixel;
  int size_line;

} t_image_data;

typedef struct s_map_exit {
  int col;
  int row;
} t_map_exit;

typedef struct s_map {
  char *map_path;
  char **map;
  int rows;
  int columns;
  t_map_exit map_exit;
  int collectibles;
} t_map;

typedef struct s_map_node {
  char *line;
  struct s_map_node *next;
} t_map_node;

typedef struct s_map_queue {
  t_map_node *first;
  t_map_node *last;
} t_map_queue;

typedef struct s_player {
  int col;
  int row;
  int moves;
  int collectibles;
  int alive;
  int direction;
  void *images[4];

} t_player;

typedef struct s_tiles {
  void *collectible;
  void *floor;
  void *wall;
  void *exit;
} t_tiles;

typedef struct s_game {
  void *mlx;
  void *win;
  t_map_queue queue;
  t_map map;
  t_player player;
  t_tiles tiles;
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

// queue

void init_map_queue(t_map_queue *queue);
void enqueue(t_map_queue *queue, char *line);
char *dequeue(t_map_queue *queue);
int is_empty(t_map_queue *queue);
int queue_size(t_map_queue *queue);

// map
void init_map(t_map *map);
void parse_map_from_queue(t_game *game);
void extract_exit_and_player_from_map(t_game *game);
int check_exist_and_duplicates(t_game *game);
// void					count_collectibles(t_game *game);

// map validation
int validate_map(t_game *game);
int check_if_rectangular(t_map map);
int check_enclosed_by_walls(t_map map);

// player

void init_player(t_game *game);

// tiles

void load_and_draw_tiles(t_game *game);

#endif