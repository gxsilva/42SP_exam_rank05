/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 21:25:24 by lsilva-x          #+#    #+#             */
/*   Updated: 2026/04/01 22:34:18 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIFE_H
#define LIFE_H

#include <stdlib.h>
#include <stdio.h>

#include <unistd.h> //STDIN_FILENO

typedef struct s_game
{
	int height;
	int width;

	int iteraction;

	int draw;

	int x;
	int y;

	char alive;
	char dead;
	
	char **board;
} t_game;

void	free_board(t_game *game);
int		init_game(t_game *game, const char **argv);
void	fill_board(t_game *game);
int		count_neighbors(t_game *game, int y, int x);
int		run_game(t_game *game);
void	print_board(t_game *game);

#endif