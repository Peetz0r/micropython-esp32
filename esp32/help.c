/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * Development of the code in this file was sponsored by Microbric Pty Ltd
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2013-2016 Damien P. George
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <stdio.h>

#include "lib/utils/pyhelp.h"

STATIC const char *help_text =
"Welcome to MicroPython on the ESP32!\n"
"\n"
"For generic online docs please visit http://docs.micropython.org/\n"
"\n"
"For access to the hardware use the 'machine' module:\n"
"\n"
"import machine\n"
"pin12 = machine.Pin(12, machine.Pin.OUT)\n"
"pin12.value(1)\n"
"pin13 = machine.Pin(13, machine.Pin.IN, machine.Pin.PULL_UP)\n"
"print(pin13.value())\n"
"i2c = machine.I2C(scl=machine.Pin(21), sda=machine.Pin(22))\n"
"i2c.scan()\n"
"i2c.writeto(addr, b'1234')\n"
"i2c.readfrom(addr, 4)\n"
"\n"
"Control commands:\n"
"  CTRL-A        -- on a blank line, enter raw REPL mode\n"
"  CTRL-B        -- on a blank line, enter normal REPL mode\n"
"  CTRL-C        -- interrupt a running program\n"
"  CTRL-D        -- on a blank line, do a soft reset of the board\n"
"  CTRL-E        -- on a blank line, enter paste mode\n"
"\n"
"For further help on a specific object, type help(obj)\n"
;

STATIC mp_obj_t builtin_help(uint n_args, const mp_obj_t *args) {
    if (n_args == 0) {
        // print a general help message
        mp_printf(MP_PYTHON_PRINTER, "%s", help_text);

    } else {
        // try to print something sensible about the given object
        pyhelp_print_obj(args[0]);
    }

    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(mp_builtin_help_obj, 0, 1, builtin_help);
