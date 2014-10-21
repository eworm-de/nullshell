/*
 * (C) 2013-2014 by Christian Hesse <mail@eworm.de>
 *
 * This software may be used and distributed according to the terms
 * of the GNU General Public License, incorporated herein by reference.
 *
 * Based on ideas from Sleep Dummy Shell (SleepShell)
 * by Mario A. Valdez-Ramirez (http://www.mariovaldez.net/)
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
	uint8_t start;
	char *ssh_connection, *ssh_client, *ssh_tty;
	char * string = BANNER;

	/* get the start time and calculate modulo */
	time(&now);
	start = (now / 30) % 30;

	/* read environment variables */
	ssh_connection = getenv("SSH_CONNECTION");
	ssh_client = getenv("SSH_CLIENT");
	ssh_tty = getenv("SSH_TTY");

	/* register signal callbacks */
	signal(SIGTERM, sig_callback);
	signal(SIGINT, sig_callback);

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

	/* print an character every SLEEPTIME seconds */
	while (1) {
		sleep(SLEEPTIME);
		putchar(*string);
		fflush(NULL);
		if (*string == 0) {
			time(&now);
			if ((now / 30) % 30 != start)
				string = ctime(&now);
			else
				string = BANNER;
		} else
			string++;
	}

	/* we should never get here.... */
	return EXIT_SUCCESS;
}

// vim: set syntax=c:
