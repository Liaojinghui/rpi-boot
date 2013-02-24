/* Copyright (C) 2013 by John Cronin <jncronin@tysos.org>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <stdint.h>
#include "util.h"

// Support for unaligned data access

uint32_t read_word(uint8_t *buf, int offset)
{
	uint32_t b0 = buf[offset + 0] & 0xff;
	uint32_t b1 = buf[offset + 1] & 0xff;
	uint32_t b2 = buf[offset + 2] & 0xff;
	uint32_t b3 = buf[offset + 3] & 0xff;

	return b0 | (b1 << 8) | (b2 << 16) | (b3 << 24);
}

uint16_t read_halfword(uint8_t *buf, int offset)
{
	uint16_t b0 = buf[offset + 0] & 0xff;
	uint16_t b1 = buf[offset + 1] & 0xff;

	return b0 | (b1 << 8);
}

uint8_t read_byte(uint8_t *buf, int offset)
{
	return buf[offset];
}

