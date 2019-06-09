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

/*
 * LICENSE_FILE is relative to the executable.
 * This is done to make it easier to port to other operating systems.
 */
#define LICENSE_FILE "license.txt"
#define LICENSE_KEY  6447

bool validate_license(void)
{
	FILE *license;
	int user_license_key;

	/* License key should be provided in the LICENSE_FILE. */
	license = fopen(LICENSE_FILE, "r");
	if (license == NULL)
	{
		goto failure;
	}

	/* License key is only an integer. */
	if (fscanf(license, "%d", &user_license_key) != 1)
	{
		goto ofile_failure;
	}

	fclose(license);
	return user_license_key == LICENSE_KEY;

ofile_failure:
	fclose(license);
failure:
	return false;
}

int main(void)
{
	if (validate_license())
	{
		puts("License valid!");
		return EXIT_SUCCESS;
	}

	puts("License invalid.");
	return EXIT_FAILURE;
}
