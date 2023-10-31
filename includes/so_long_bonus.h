/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:39:05 by azaaza            #+#    #+#             */
/*   Updated: 2023/11/01 00:22:32 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define KEY_PRESS 2
# define DESTROY_NOTIFY 17

# ifndef TILE_SIZE
#  define TILE_SIZE 32
# endif

# include "../ft_printf/include/ft_printf.h"
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

typedef struct s_map_exit
{
	int					col;
	int					row;
}						t_map_exit;

typedef struct s_map
{
	char				**map;
	int					rows;
	int					columns;
	t_map_exit			map_exit;
	int					collectibles;
}						t_map;

typedef struct s_map_node
{
	char				*line;
	struct s_map_node	*next;
}						t_map_node;

typedef struct s_map_queue
{
	t_map_node			*first;
	t_map_node			*last;
}						t_map_queue;

typedef struct s_player
{
	int					col;
	int					row;
	int					moves;
	int					collectables_gathered;
	int					direction;
	void				*images[4];
}						t_player;

typedef struct s_tiles
{
	void				*collectible[14];
	void				*floor;
	void				*wall;
	void				*exit;
}						t_tiles;
typedef struct s_enemy
{
	void				*image;
}						t_enemy;

typedef struct s_game
{
	void				*mlx;
	void				*win;
	t_map_queue			queue;
	t_map				map;
	t_player			player;
	t_enemy				enemy;
	t_tiles				tiles;
	void				*fonts[10];
}						t_game;

void					validate_args(int argc, char **argv, t_game *game);
int						is_valid_char(char c);

// queue

// map
void					init_map(t_map *map);
void					parse_map_from_queue(t_game *game);
void					extract_exit_and_player_from_map(t_game *game);
int						check_exist_and_duplicates(t_game *game);
void					cleanup_map(t_game *game);

// map validation
void					validate_map(t_game *game);
int						check_if_rectangular(t_map map);
int						check_enclosed_by_walls(t_map map);

// player

void					init_player(t_game *game);
void					handle_move_player(int key, t_game *game);
void					draw_floor(t_game *game, int row, int col);
void					move_player(t_game *game, int row, int col,
							int new_direction);
int						dfs(t_game *game, int *collected, int **visited,
							int row, int col);

// tiles
void					load_tiles(t_game *game);
void					load_coin(t_game *game);
void					draw(t_game *game);
void					draw_movements(t_game *game);
void					draw_coin(t_game *game, int row, int col);
void					destroy_tiles(t_game *game);

// utils

int						count_characters(t_map *map, char c);
int						**create_visited_arr(t_game *game);
void					free_visited(int **visited, int size);
int						handle_destroy(t_game *game);

// font

void					destroy_fonts(t_game *game);
void					destroy_coins(t_game *game);
void					ft_put_font(t_game *game, int digit, int i);
void					load_fonts(t_game *game);

/**
DRAW UTILS
*/

void					*xpm_to_image(t_game **game, char *file);

/* ERROR*/

void					print_error(char *message);
#endif