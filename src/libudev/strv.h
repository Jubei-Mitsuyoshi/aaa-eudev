/*-*- Mode: C; c-basic-offset: 8; indent-tabs-mode: nil -*-*/

#pragma once

/***
  This file is part of systemd.

  Copyright 2010 Lennart Poettering

  systemd is free software; you can redistribute it and/or modify it
  under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation; either version 2.1 of the License, or
  (at your option) any later version.

  systemd is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with systemd; If not, see <http://www.gnu.org/licenses/>.
***/

#include <stdarg.h>
#include <stdbool.h>

#include "macro.h"

void strv_free(char **l);
static inline void strv_freep(char ***l) {
        strv_free(*l);
}

#define _cleanup_strv_free_ _cleanup_(strv_freep)

char **strv_copy(char * const *l);
unsigned strv_length(char * const *l) _pure_;

int strv_extend(char ***l, const char *value);
int strv_push(char ***l, char *value);

char **strv_remove(char **l, const char *s);
char **strv_uniq(char **l);

char **strv_new(const char *x, ...) _sentinel_;
char **strv_new_ap(const char *x, va_list ap);

static inline bool strv_isempty(char * const *l) {
        return !l || !*l;
}

#define STRV_FOREACH(s, l)                      \
        for ((s) = (l); (s) && *(s); (s)++)
