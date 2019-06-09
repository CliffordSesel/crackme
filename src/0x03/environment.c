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

#define FLAG        6841
#define FLAG_BASE   10

int main(void)
{
	char *variable;
	long int passcode;

	variable = getenv("FLAG");
	if (variable == NULL)
	{
		goto failure;
	}

	passcode = strtol(variable, NULL, FLAG_BASE);
	if (passcode == FLAG)
	{
		puts("Password correct!");
		return EXIT_SUCCESS;
	}

failure:
	puts("Password incorrect.");
	return EXIT_FAILURE;
}
