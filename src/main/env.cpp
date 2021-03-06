/*
 * Copyright (C) 2020 Linux Studio Plugins Project <https://lsp-plug.in/>
 *           (C) 2020 Vladimir Sadovnikov <sadko4u@gmail.com>
 *
 * This file is part of lsp-test-fw
 * Created on: 22 мар. 2020 г.
 *
 * lsp-test-fw is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * lsp-test-fw is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with lsp-test-fw. If not, see <https://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdarg.h>

#include <lsp-plug.in/test-fw/env.h>

namespace lsp
{
    namespace test
    {
        Environment::Environment()
        {
            __verbose       = false;
            __executable    = NULL;
            __tempdir       = NULL;
            __resources     = NULL;
            __stdout        = NULL;
            __stderr        = NULL;
        }

        Environment::~Environment()
        {
            __verbose       = false;
            __executable    = NULL;
            __tempdir       = NULL;
            __resources     = NULL;
            __stdout        = NULL;
            __stderr        = NULL;
        }

        void Environment::configure(config_t *cfg)
        {
            __verbose       = cfg->verbose;
            __executable    = cfg->executable;
            __tempdir       = cfg->tempdir;
            __resources     = cfg->resource;
            __stdout        = cfg->std_out;
            __stderr        = cfg->std_err;
        }

        int Environment::printf(const char *fmt, ...)
        {
            if ((!__verbose) || (__stdout == NULL))
                return 0;

            va_list vl;
            va_start(vl, fmt);
            int res = ::vfprintf(__stdout, fmt, vl);
            va_end(vl);
            ::fflush(__stdout);
            return res;
        }

        int Environment::eprintf(const char *fmt, ...)
        {
            if (__stderr == NULL)
                return 0;

            va_list vl;
            va_start(vl, fmt);
            int res = ::vfprintf(__stderr, fmt, vl);
            va_end(vl);
            ::fflush(__stderr);
            return res;
        }
    }
}


