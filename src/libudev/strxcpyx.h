/*-*- Mode: C; c-basic-offset: 8; indent-tabs-mode: nil -*-*/

#pragma once

/***
  This file is part of eudev from systemd.

  Copyright 2013 Kay Sievers

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

size_t strpcpy(char **dest, size_t size, const char *src);
size_t strpcpyf(char **dest, size_t size, const char *src, ...) __attribute__((format(printf, 3, 4)));
size_t strpcpyl(char **dest, size_t size, const char *src, ...) __attribute__((sentinel));
size_t strscpy(char *dest, size_t size, const char *src);
size_t strscpyl(char *dest, size_t size, const char *src, ...) __attribute__((sentinel));
