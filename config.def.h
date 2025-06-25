/*
 * (C) 2013-2025 by Christian Hesse <mail@eworm.de>
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

#ifndef _CONFIG_H
#define _CONFIG_H

/* this is the time to sleep between printing characters */
#define SLEEPTIME	1

/* this is the number of line between banner appears */
#define	BANNERCONST	20

/* some text to be printed */
#define URL	"https://nullshell.eworm.de/"
#define BANNER	"Do-nothing-loop by nullshell " VERSION ",\n" \
	"compiled on " __DATE__ " " __TIME__ ".\n" \
	"Visit homepage: " URL "\n"

#endif /* _CONFIG_H */

// vim: set syntax=c:
