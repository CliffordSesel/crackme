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

#define FLAG        7623
#define FLAG_BASE   10

int main(int argc, char **argv)
{
	long int passcode;

	if (argc >= 2)
	{
		/* An argument was passed to the program. */
		passcode = strtol(argv[1], NULL, FLAG_BASE);
		if (passcode == FLAG)
		{
			puts("Password correct!");
			return EXIT_SUCCESS;
		}
	}

	puts("Password incorrect.");
	return EXIT_FAILURE;
}
