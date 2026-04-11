/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 12:52:28 by lsilva-x          #+#    #+#             */
/*   Updated: 2026/04/10 21:09:23 by lsilva-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "bsq.h"

int main(int argc ,char **argv)
{
	if (argc == 1)
	{
		if (!execute_bsq(stdin))
		{
			fprintf(stderr, "map error\n");
			return (1);
		}
	}
	else
	{
		for (int i = 1; i < argc; i++)
			if (!convert_file_to_pointer(argv[i]))
			{
				fprintf(stderr, "map error\n");
				return (1);
			}
	}
	return (0);
}