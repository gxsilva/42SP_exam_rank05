/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 12:08:19 by lsilva-x          #+#    #+#             */
/*   Updated: 2026/04/07 12:28:53 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "life.h"


int main(int argc, char **argv)
{
	if (argc != 4)
		return (1);
	t_game game;
	if (!init_game(&game, argv))
		return (1);
	fill_board(&game);
	for (int x = 0; x < game.iteractions; x++)
		if (!run_game(&game))
			return (free_board(&game), 1);
	print_board(&game);
	return (0);
}