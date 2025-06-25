/*
 * (C) 2013-2025 by Christian Hesse <mail@eworm.de>
 *
 * Based on ideas from Sleep Dummy Shell (SleepShell)
 * by Mario A. Valdez-Ramirez (http://www.mariovaldez.net/)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

#define _GNU_SOURCE

#include <inttypes.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "config.h"
#include "version.h"

void sig_callback(int signal) {
	printf("\nReceived signal '%s', quitting.\nBye!\n", strsignal(signal));

	exit(EXIT_SUCCESS);
}

int main(int argc, char **argv) {
	time_t now;
	uint8_t lines = BANNERCONST;
	char *ssh_connection, *ssh_client, *ssh_tty;
	char * string = BANNER;

	/* read environment variables */
	ssh_connection = getenv("SSH_CONNECTION");
	ssh_client = getenv("SSH_CLIENT");
	ssh_tty = getenv("SSH_TTY");

	/* register signal callbacks */
	struct sigaction act = { 0 };
	act.sa_handler = sig_callback;
	sigaction(SIGINT, &act, NULL);
	sigaction(SIGTERM, &act, NULL);

	/* clear the screen and set cursor to the top left
	 * see 'man 4 console_codes' for details */
	fputs("\033[2J\033[1;1H", stdout);
	fflush(NULL);

	/* print some info if available */
	if (ssh_connection != NULL && ssh_client != NULL) {
		printf("Connection: %s\nClient: %s\n", ssh_connection, ssh_client);
		if (ssh_tty != NULL)
			printf("Terminal: %s\n", ssh_tty);
	}

	/* print a character every SLEEPTIME seconds */
	while (1) {
		sleep(SLEEPTIME);
		putchar(*string);
		fflush(NULL);
		if (*string == 0) {
			if (lines-- > 0) {
				time(&now);
				string = ctime(&now);
			} else {
				string = BANNER;
				lines = BANNERCONST;
			}
		} else
			string++;
	}

	/* we should never get here.... */
	return EXIT_SUCCESS;
}

// vim: set syntax=c:
