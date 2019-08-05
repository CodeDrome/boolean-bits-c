
#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
#include<math.h>

//--------------------------------------------------------
// STRUCT bits
//--------------------------------------------------------
typedef struct bits
{
    unsigned char* bits;
    unsigned int bitcount;
    unsigned int bytecount;
} bits;

//--------------------------------------------------------
// FUNCTION PROTOTYPES
//--------------------------------------------------------
bits* create_bits(unsigned int bitcount);
void print_bits_unfriendly(bits* b);
void print_bits_friendly(bits* b);
void set_bit(bits* b, unsigned int bit, bool value);
bool get_bit(bits* b, unsigned int bit);
void free_bits(bits* b);
