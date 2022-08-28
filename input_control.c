#include "so_long.h"

int extension_check(char **av)
{
	int i = 0;
	int j = 0;
	char *ext = ".ber";

	while (av[1][i])
		++i;
	i -= 4;
	while (av[1][i + j])
	{
		if (av[1][i + j] != ext[j])
			return (0);
		++j;
	}
	return (1);
}
