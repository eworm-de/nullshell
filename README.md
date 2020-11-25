nullshell
=========

**do nothing but print keep alive characters, can be used for login shell**

This is a minimal program that does nothing but print some characters
(namely version information and time&date string) every now
and then. It is intended to be used for login shell with accounts
accessible via secure shell that are used for secure tunneling but
should not allow to execute commands.

Requirements
------------

To compile and run `nullshell` you need:

* nothing (this is plain C)
* [markdown](https://daringfireball.net/projects/markdown/) (HTML documentation)

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

License and warranty
--------------------

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
[GNU General Public License](COPYING.md) for more details.

### Upstream

URL:
[GitHub.com](https://github.com/eworm-de/nullshell#nullshell)

Mirror:
[eworm.de](https://git.eworm.de/cgit.cgi/nullshell/)
[GitLab.com](https://gitlab.com/eworm-de/nullshell#nullshell)
