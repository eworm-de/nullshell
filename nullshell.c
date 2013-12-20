/*
 * (C) 2013 by Christian Hesse <mail@eworm.de>
 *
 * This software may be used and distributed according to the terms
 * of the GNU General Public License, incorporated herein by reference.
 *
 * Based on ideas from Sleep Dummy Shell (SleepShell)
 * by Mario A. Valdez-Ramirez (http://www.mariovaldez.net/)
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SLEEPTIME 10

int main(int argc, char **argv) {
	char *ssh_connection, *ssh_client, *ssh_tty;

	/* read environment variables */
	ssh_connection = getenv("SSH_CONNECTION");
	ssh_client = getenv("SSH_CLIENT");
	ssh_tty = getenv("SSH_TTY");

	/* clear the screen */
	fputs("\033[2J\033[1;1H", stdout);
	fflush(NULL);

	/* print some info if available */
	if (ssh_connection != NULL && ssh_client != NULL) {
		printf("Connection: %s\nClient: %s\n", ssh_connection, ssh_client);
		if (ssh_tty != NULL)
			printf("Terminal: %s\n", ssh_tty);
	}

	/* print an asterisk every SLEEPTIME seconds */
	while (1) {
		sleep(SLEEPTIME);
		putchar('*');
		fflush(NULL);
	}

	/* we should never get here.... */
	return EXIT_SUCCESS;
}

// vim: set syntax=c: