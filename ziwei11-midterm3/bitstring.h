#ifndef _BITSTRING_H_
// WARNING: This file might have a bug or two. Feel free to modify it.
// HINT: In my solution I didn't bother changing anything in this file.
//       But your solution might need to change this.
#include <inttypes.h>

#define BIT(x,y) (x & (0x1L << y))
// bitString takes in a string buffer for writing, a value whos bits
// will be encoded into the buffer string as characters and the bits,
// the number of bits we care to convert to a string
// char * buffer must be at least 129 chars preallocated or at least bits+1 characters
void bitString(char * buffer, uint64_t value, const unsigned int bits) {
    for (unsigned int i = 0 ; i < bits; i++) {
        buffer[bits-1-i] = (BIT(value,i))?'1':'0';
    }
    buffer[bits] = '\0';
}
#endif
