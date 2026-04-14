#include <stdio.h>

#include "bsq.h"

int main(int argc, char **argv)
{
	if (argc < 2)
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
		{
			if (!fileToPtr(argv[i]))
			{
				fprintf(stderr, "map error\n");
				return (1);
			}
			fprintf(stdout, "%c", '\n');
		}
	}
	return (0);
}