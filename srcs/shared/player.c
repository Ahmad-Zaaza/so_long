
#include "../../includes/so_long.h"

/**
  Populating the player object.

  We already set up the player position x,y when parsing the map.
  Here we keep track of player information, such as moves count, is alive,
	swallowed
  loot, and the current facing direction.

  I used the a,w,d,s buttons clockwise convention to specify the direction.
  where :
  - 0 is a (left)
  - 1 is w (top)
  - 2 is d (right)
  - 3 is s (bottom)

  Also we load and save the player assets in an array. in which we use with the direction index
  to render the correct posture of the player.
*/
void	init_player(t_game *game)
{
	int	height;
	int	width;

	game->player.alive = 1;
	game->player.collectables_gathered = 0;
	game->player.moves = 0;
	game->player.direction = 3;
	game->player.images[0] = mlx_xpm_file_to_image(game->mlx,
			"textures/player/left.xpm", &width, &height);
	game->player.images[1] = mlx_xpm_file_to_image(game->mlx,
			"textures/player/top.xpm", &width, &height);
	game->player.images[2] = mlx_xpm_file_to_image(game->mlx,
			"textures/player/right.xpm", &width, &height);
	game->player.images[3] = mlx_xpm_file_to_image(game->mlx,
			"textures/player/bottom.xpm", &width, &height);
}

/**
  Render player

  We use this function inside the mlx frame loop.

  We access the images array using the current direction and pass it to mlx to render.
*/
void	draw_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->player.images[game->player.direction], game->player.col
		* TILE_SIZE, (game->player.row + 1) * TILE_SIZE);
}

/**
Move player:

We call this function as a handler for the key listener of movement keys
*/
void	handle_move_player(int key, t_game *game)
{
	int	p_col;
	int	new_row;
	int	p_row;
	int	new_col;

	if (key == 13)
		move_player(game, game->player.row - 1, game->player.col, 1);
	else if (key == 0)
		move_player(game, game->player.row, game->player.col - 1, 0);
	else if (key == 1)
		move_player(game, game->player.row + 1, game->player.col, 3);
	else if (key == 2)
		move_player(game, game->player.row, game->player.col + 1, 2);
}
