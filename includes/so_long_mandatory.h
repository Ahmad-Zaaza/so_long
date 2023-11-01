/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_mandatory.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 01:20:47 by azaaza            #+#    #+#             */
/*   Updated: 2023/11/02 00:19:02 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_MANDATORY_H
# define SO_LONG_MANDATORY_H

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
# include <stdlib.h>

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
	void				*collectible;
	void				*floor;
	void				*wall;
	void				*exit;
}						t_tiles;

typedef struct s_game
{
	void				*mlx;
	void				*win;
	t_map_queue			queue;
	t_map				map;
	t_player			player;
	t_tiles				tiles;
}						t_game;

void					validate_args(int argc, char **argv, t_game *game);
int						is_valid_char(char c);

// queue

void					init_map_queue(t_map_queue *queue);
void					enqueue(t_map_queue *queue, char *line);
char					*dequeue(t_map_queue *queue);
int						is_empty(t_map_queue *queue);
int						queue_size(t_map_queue *queue);
void					cleanup_queue(t_map_queue *queue);

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
void					draw_player(t_game *game);
void					handle_tiles_draw(t_game *game, int row, int col);
void					move_player(t_game *game, int row, int col,
							int new_direction);
int						dfs(t_game *game, int *collected, int **visited,
							int row, int col);

// tiles
void					load_tiles(t_game *game);
void					draw(t_game *game);
void					draw_floor(t_game *game, int row, int col);
void					destroy_tiles(t_game *game);

// utils

int						count_characters(t_map *map, char c);
int						**create_visited_arr(t_game *game);
void					free_visited(int **visited, int size);
int						handle_destroy(t_game *game);

/**
DRAW UTILS
*/

void					*xpm_to_image(t_game **game, char *file);

/* ERROR*/

void					print_error(char *message);
#endif