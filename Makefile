# nullshell - do nothing but print asterisks, can be used for login shell

PREFIX	:= /usr
CC	:= gcc
MD	:= markdown
INSTALL	:= install
RM	:= rm
CFLAGS	+= -O2 -Wall -Werror

all: nullshell README.html

nullshell: nullshell.c
	$(CC) $(CFLAGS) $(LDFLAGS) nullshell.c -o nullshell

README.html: README.md
	$(MD) README.md > README.html

install: install-bin install-doc

install-bin: nullshell
	$(INSTALL) -D -m0755 nullshell $(DESTDIR)$(PREFIX)/bin/nullshell

install-doc: README.html
	$(INSTALL) -D -m0755 README.md $(DESTDIR)$(PREFIX)/share/doc/nullshell/README.md
	$(INSTALL) -D -m0755 README.html $(DESTDIR)$(PREFIX)/share/doc/nullshell/README.html

clean:
	$(RM) -f README.html nullshell
