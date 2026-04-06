/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 17:02:05 by lsilva-x          #+#    #+#             */
/*   Updated: 2026/04/06 17:40:21 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIFE_H
#define LIFE_H

typedef struct s_game
{
	int width;
	int heigth;
	int iteractions;

	char dead;
	char live;

	int x;
	int y;
	int draw;
	int **board;
} t_game;

int init_game(t_game *game, char **argv);
void fill_board(t_game *game);
void print_board(t_game *game);
void free_board(t_game *game);
int run_game(t_game *game);

#endif