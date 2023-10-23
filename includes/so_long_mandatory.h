/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_mandatory.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 01:20:47 by azaaza            #+#    #+#             */
/*   Updated: 2023/10/24 01:38:23 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_MANDATORY_H
# define SO_LONG_MANDATORY_H

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
	int					alive;
	int					direction;
	void				*images[4];

}						t_player;

typedef struct s_tiles
{
	void				*collectible[11];
	void				*floor;
	void				*wall;
	void				*exit;
}						t_tiles;

typedef struct s_font
{
	void				*zero;
	void				*one;
	void				*two;
	void				*three;
	void				*four;
	void				*five;
	void				*six;
	void				*seven;
	void				*eight;
	void				*nine;
}						t_font;

typedef struct s_game
{
	void				*mlx;
	void				*win;
	t_map_queue			queue;
	t_map				map;
	t_player			player;
	double				frame;
	t_tiles				tiles;
	t_font				font;
}						t_game;

int						validate_args(int argc, char **argv, t_game *game);

// Color utils
int						create_trgb(int t, int r, int g, int b);
int						get_t(int trgb);
int						get_r(int trgb);
int						get_g(int trgb);
int						get_b(int trgb);

// queue

void					init_map_queue(t_map_queue *queue);
void					enqueue(t_map_queue *queue, char *line);
char					*dequeue(t_map_queue *queue);
int						is_empty(t_map_queue *queue);
int						queue_size(t_map_queue *queue);

// map
void					init_map(t_map *map);
void					parse_map_from_queue(t_game *game);
void					extract_exit_and_player_from_map(t_game *game);
int						check_exist_and_duplicates(t_game *game);
void					cleanup_map(t_game *game);

// map validation
int						validate_map(t_game *game);
int						check_if_rectangular(t_map map);
int						check_enclosed_by_walls(t_map map);

// player

void					init_player(t_game *game);
void					handle_move_player(int key, t_game *game);
void					draw_player(t_game *game);
void					move_player(t_game *game, int row, int col,
							int new_direction);
int						dfs(t_game *game, int *collected, int **visited,
							int row, int col);

// tiles
void					load_tiles(t_game *game);
void					draw_tiles(t_game *game);
void					draw_movements(t_game *game);
void					destroy_tiles(t_game *game);

// utils

int						count_characters(t_map *map, char c);
int						**create_visited_arr(t_game *game);
void					free_visited(int **visited, int size);
int						handle_destroy(t_game *game);

// font

void					destroy_fonts(t_game *game);
void					ft_put_font(t_game *game, int digit, int i);
void					load_fonts(t_game *game);

/**
DRAW UTILS
*/

void					*xpm_to_image(t_game **game, char *file);
#endif