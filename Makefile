# nullshell - do nothing but print asterisks, can be used for login shell

PREFIX	:= /usr

# commands
CC	:= gcc
CP	:= cp
INSTALL	:= install
MD	:= markdown
RM	:= rm

# flags
CFLAGS	+= -std=c11 -O2 -fPIC -Wall -Werror
LDFLAGS	+= -Wl,-z,now -Wl,-z,relro -pie

# this is just a fallback in case you do not use git but downloaded
# a release tarball...
VERSION := 0.0.6

all: nullshell README.html

nullshell: nullshell.c config.h version.h
	$(CC) $(CFLAGS) $(LDFLAGS) -o nullshell nullshell.c

version.h: $(wildcard .git/HEAD .git/index .git/refs/tags/*) Makefile
	echo "#ifndef VERSION" > $@
	echo "#define VERSION \"$(shell git describe --tags --long 2>/dev/null || echo ${VERSION})\"" >> $@
	echo "#endif" >> $@

config.h:
	$(CP) config.def.h config.h

README.html: README.md
	$(MD) README.md > README.html

install: install-bin install-doc

install-bin: nullshell
	$(INSTALL) -D -m0755 nullshell $(DESTDIR)$(PREFIX)/bin/nullshell

install-doc: README.html
	$(INSTALL) -D -m0755 README.md $(DESTDIR)$(PREFIX)/share/doc/nullshell/README.md
	$(INSTALL) -D -m0755 README.html $(DESTDIR)$(PREFIX)/share/doc/nullshell/README.html

clean:
	$(RM) -f README.html nullshell version.h

distclean:
	$(RM) -f README.html nullshell version.h config.h

release:
	git archive --format=tar.xz --prefix=nullshell-$(VERSION)/ $(VERSION) > nullshell-$(VERSION).tar.xz
	gpg -ab nullshell-$(VERSION).tar.xz
