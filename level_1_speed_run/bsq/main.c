/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 21:04:59 by lsilva-x          #+#    #+#             */
/*   Updated: 2026/04/10 23:00:30 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "bsq.h"

int main(int argc, char **argv)
{
	//read from stdin
	if (argc == 1)
	{
		if (!bsq_execute(stdin))
		{
			fprintf(stderr, "map error\n");
			return (1);
		}
	}
	else
	{
		for (int i = 1; i < argc; i++)
		{
			if (!file_to_ptr(argv[i]))
			{
				fprintf(stderr, "map error\n");
				return (1);
			}
			fprintf(stdout, "%c", '\n');
		}
	}
	return (0);
}