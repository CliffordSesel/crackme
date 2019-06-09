/*
 * Copyright (c) 2019 Jasper Lowell
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>

#define PASSCODE      1857631170
#define PASSCODE_BASE 10

int main(int argc, char **argv)
{
	long int seed;

	if (argc >= 2)
	{
		seed = strtol(argv[1], NULL, PASSCODE_BASE);
		if (seed < 0)
		{
			goto failure;
		}

		/*
		 * RNG is deliberately vulnerable.
		 *
		 * This challenge is considered slightly more involved
		 * because it involves some crypto knowledge.
		 */
		srand(seed);
		if (rand() == PASSCODE)
		{
			puts("Access granted.");
			return EXIT_SUCCESS;
		}

	}

failure:
	puts("Access denied.");
	return EXIT_FAILURE;
}
