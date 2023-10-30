
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
	game->player.collectables_gathered = 0;
	game->player.moves = 0;
	game->player.direction = 3;
	game->player.images[0] = xpm_to_image(&game, "textures/player/left.xpm");
	game->player.images[1] = xpm_to_image(&game, "textures/player/top.xpm");
	game->player.images[2] = xpm_to_image(&game, "textures/player/right.xpm");
	game->player.images[3] = xpm_to_image(&game, "textures/player/bottom.xpm");
}
