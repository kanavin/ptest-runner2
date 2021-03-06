/**
 * Copyright (c) 2016 Intel Corporation
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * AUTHORS
 * 	Aníbal Limón <anibal.limon@intel.com>
 */

#ifndef PTEST_RUNNER_UTILS_H
#define PTEST_RUNNER_UTILS_H

#include "ptest_list.h"

#define PRINT_PTESTS_NOT_FOUND "No ptests found.\n"
#define PRINT_PTESTS_NOT_FOUND_DIR "Warning: ptests not found in, %s.\n"
#define PRINT_PTESTS_AVAILABLE "Available ptests:\n"

#define CHECK_ALLOCATION(p, size, exit_on_null) \
	check_allocation1(p, size, __FILE__, __LINE__, exit_on_null)

struct ptest_options {
	char **dirs;
	int dirs_no;
	int padding1;
	char **exclude;
	int list;
	unsigned int timeout;
	char **ptests;
	char *xml_filename;
};


extern void check_allocation1(void *, size_t, char *, int, int);
extern struct ptest_list *get_available_ptests(const char *);
extern int print_ptests(struct ptest_list *, FILE *);
extern struct ptest_list *filter_ptests(struct ptest_list *, char **, int);
extern int run_ptests(struct ptest_list *, const struct ptest_options,
		const char *, FILE *, FILE *);

extern FILE *xml_create(int, char *);
extern void xml_add_case(FILE *, int, const char *, int, int);
extern void xml_finish(FILE *);

void set_opts_dir(char * od);

#endif
