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
#include <string.h>

#define FLAG        "asecurepassword"
#define BUFFER_SIZE 256

int main(void)
{
	char buffer[BUFFER_SIZE];

	/* Prompt for password. */
	printf("%s", "Password: ");

	/*
	 * Read password from user input.
	 *
	 * This is the first challenge. To avoid making the control diagram
	 * more complex, error handling is omitted.
	 */
	fgets(buffer, BUFFER_SIZE, stdin);

	/*
	 * Validate password.
	 * strlen(buffer) - 1 to account for an expected newline.
	 */
	if (strncmp(buffer, FLAG, strlen(buffer) - 1) == 0) {
		puts("Password correct!\n");
		return EXIT_SUCCESS;
	}

	puts("Password incorrect.\n");
	return EXIT_FAILURE;
}
