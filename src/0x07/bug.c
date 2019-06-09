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

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ACCESS_CODE_LEN 6
#define BUFFER_SIZE     120
#define PASSCODE_BASE   10
#define MODULO_CONST    13

int main(void)
{
	bool no_access;
	long int passcode;

	char buffer[BUFFER_SIZE];

	no_access = false;

	/* Prompt for access code. */
	printf("%s", "Access code: ");
	if (fgets(buffer, BUFFER_SIZE, stdin) == NULL)
	{
		goto failure;
	}

	/* ACCESS_CODE_LEN + 1 for newline. */
	if (strlen(buffer) != ACCESS_CODE_LEN + 1)
	{
		goto failure;
	}

	/*
	 * Convert input string to integer.
	 * Errors are not dangerous and thus ignored.
	 */
	passcode = strtol(buffer, NULL, PASSCODE_BASE);
	for (int i = 1; i < passcode; i++)
	{
		passcode += (passcode % i);
		if (passcode % MODULO_CONST == 0)
		{
			no_access = true;
			break;
		}
	}

	if (!no_access)
	{
		puts("Access granted.");
		return EXIT_SUCCESS;
	}

failure:
	puts("Access denied.");
	return EXIT_FAILURE;
}
