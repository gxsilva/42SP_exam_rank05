#include "life.h"
int main(int argc, char **argv)
{
	if (argc != 4)
		return (1);
	t_game game;
	if (!init_game(&game,argv))
		return (1);
	fill_board(&game);
	for (int x = 0; x < game.iteractions; x++)
	{
		if (!run_game(&game))
			return (free_board(game.board, game.height), 1);
	}
	print_board(&game);
	free_board (game.board, game.height);
	return (0);
}