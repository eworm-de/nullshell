nullshell
=========

**do nothing but print asterisks, can be used for login shell**

This is a minimal program that does nothing but print asteriks every now
and then. It is intended to be used for login shell with accounts
accessible via secure shell that are used for secure tunneling but
should not allow to execute commands.

Requirements
------------

To compile and run `nullshell` you need:

* nothing (this is plain C)
* [markdown](http://daringfireball.net/projects/markdown/) (HTML documentation)

Additionally it is expected to have `make` and a C compiler around to
successfully compile.

Build and install
-----------------

Building and installing is very easy. Just run:

> make

followed by:

> make install

This will place an executable at `/usr/bin/nullshell`.

Usage
-----

To create a new user `user` with `nullshell` as login shell just run:

> useradd -s /usr/bin/nullshell user

Or to make `nullshell` the login shell for an existing user `user`:

> usermod -s /usr/bin/nullshell user

Make sure `/usr/bin/nullshell` is listed in `/etc/shells` if your system
expects this.
