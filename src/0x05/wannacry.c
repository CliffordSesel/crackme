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

#include <curl/curl.h>

#define DOMAIN "https://re.jtalowell.com"

struct curl_response
{
	char *buffer;
	size_t len;
};

static size_t curl_mem_write_callback(void *src, size_t size, size_t nmemb,
		void *data)
{
	size_t raw_size;
	struct curl_response *response;

	raw_size = size * nmemb;
	response = (struct curl_response *) data;

	response->buffer = realloc(response->buffer,
			response->len + raw_size + 1);

	if (response->buffer == NULL)
	{
		return 0;
	}

	memcpy(&(response->buffer[response->len]), src, raw_size);
	response->len += raw_size;
	response->buffer[response->len] = '\0';

	return raw_size;
}

static bool is_killswitch_alive(void)
{
	bool alive;

	CURL *handle;
	CURLcode result;

	struct curl_response response;

	alive = false;

	response.buffer = NULL;
	response.len = 0;

	curl_global_init(CURL_GLOBAL_ALL);
	handle = curl_easy_init();

	curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, curl_mem_write_callback);
	curl_easy_setopt(handle, CURLOPT_WRITEDATA, (void *) &response);
	curl_easy_setopt(handle, CURLOPT_URL, DOMAIN);
	curl_easy_setopt(handle, CURLOPT_FOLLOWLOCATION, 1L);

	/* Fetch the kill switch domain from a known domain. */
	result = curl_easy_perform(handle);
	if (result != CURLE_OK)
	{
		goto error;
	}

	/* Check whether or not the kill switch domain exists. */
	curl_easy_setopt(handle, CURLOPT_URL, &response.buffer);
	result = curl_easy_perform(handle);
	if (result != CURLE_OK)
	{
		goto error;
	}

	alive = true;

error:
	if (response.buffer != NULL)
	{
		free(response.buffer);
		response.len = 0;
	}

	return alive;
}

int main(void)
{
	if (is_killswitch_alive()) {
		puts("Malware disabled!");
		return EXIT_SUCCESS;
	}

	puts("Malware enabled.");
	return EXIT_FAILURE;
}
