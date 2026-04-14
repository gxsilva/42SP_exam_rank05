#include "life.h"

int main(int argc, char **argv)
{
	if (argc != 4)
		return (1);
	else
	{
		t_game game;
		if (!init_game(&game, argv))
			return (1);
		if (!fill_board(&game))
			return (1);
		for (int i = 0; i < game.iterations; i++)
		{
			if (!life(&game))
				return (1);
		}
		print_game(&game);
		free_grid(&game);
	}
	return (0);
}