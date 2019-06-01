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

#define FLAG        1337
#define FLAG_BASE   10
#define BUFFER_SIZE 256

int main(void)
{
	long int passcode;
	char buffer[BUFFER_SIZE];

	/* Prompt for password. */
	printf("%s", "Password: ");

	/* Read password from user input. */
	if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
		goto failure;
	}

	/*
	 * Convert input string to integer.
	 * Errors are caught when the comparison to FLAG is made.
	 */
	passcode = strtol(buffer, NULL, FLAG_BASE);
	if (passcode == FLAG) {
		puts("Password correct!\n");
		return EXIT_SUCCESS;
	}

failure:
	puts("Password incorrect.\n");
	return EXIT_FAILURE;
}
