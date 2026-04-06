/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 17:04:45 by lsilva-x          #+#    #+#             */
/*   Updated: 2026/04/06 17:56:59 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "life.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	if (argc != 4)
		return (1);
	t_game game;

	if (!init_game(&game, argv))
		return (1);
	fill_board(&game);
	for (int i = 0; i < game.iteractions; i++)
	{
		if (!run_game(&game))
		{
			free_board(&game);
			return (1);
		}
	}
	print_board(&game);
	return (0);
}