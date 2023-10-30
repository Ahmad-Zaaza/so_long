
#include "../../includes/so_long_mandatory.h"

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
