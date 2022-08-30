#include "so_long.h"

void update_foe(t_game *game)
{
	int i;

	i = 0;
	while (i < game->map.foe_num)
	{
		if (game->foe[i].point_a == game->foe[i].point_b)
			return ;
		if (game->foe[i].face)
		{
			if (game->foe[i].pos_x >= game->foe->point_b)
				game->foe[i].face = 0;
			else
				game->foe[i].pos_x += 4;
		}
		else
		{
			if (game->foe[i].pos_x <= game->foe[i].point_a)
				game->foe[i].face = 1;
			else
				game->foe[i].pos_x -= 4;
		}
		++i;
	}
}