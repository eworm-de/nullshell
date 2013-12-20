PREFIX	:= /usr
CC	:= gcc
INSTALL	:= install
RM	:= rm
CFLAGS	+= -O2 -Wall -Werror

nullshell: nullshell.c
	$(CC) $(CFLAGS) $(LDFLAGS) nullshell.c -o nullshell

install: nullshell
	$(INSTALL) nullshell $(DESTDIR)$(PREFIX)/bin/nullshell

clean:
	$(RM) -f nullshell
