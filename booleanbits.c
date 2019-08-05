
#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
#include<string.h>
#include<math.h>

#include"booleanbits.h"

//------------------------------------------------------------
// FUNCTION create_bits
//------------------------------------------------------------
bits* create_bits(unsigned int bitcount)
{
    unsigned int bytecount = ceil(bitcount / 8.0);

    bits* b = malloc(sizeof(bits));

    if(b != NULL)
    {
        *b = (bits){.bits = malloc(bytecount), .bitcount = bitcount, bytecount = bytecount};

        if(b->bits != NULL)
        {
            for(int i = 0; i < bytecount; i++)
            {
                b->bits[i] = 0;
            }

            return b;
        }
        else
        {
            free(b);

            return NULL;
        }
    }
    else
    {
        return NULL;
    }
}

//------------------------------------------------------------
// FUNCTION free_bits
//------------------------------------------------------------
void free_bits(bits* b)
{
    free(b->bits);
    free(b);
}

//------------------------------------------------------------
// FUNCTION print_bits_unfriendly
//------------------------------------------------------------
void print_bits_unfriendly(bits* b)
{
    printf("bitcount:  %d\n", b->bitcount);
    printf("bytecount: %d\n", b->bytecount);

	char s[(b->bytecount * 8) + 1];
	int si = 0;

    for(int bit = (b->bytecount * 8) - 1; bit >= 0; bit--)
    {
        if(bit >= b->bitcount)
        {
            s[si] = 'X';
        }
        else
        {
            if(get_bit(b, bit) == true)
            {
                s[si] = '1';
            }
            else
            {
                s[si] = '0';
            }
        }

        si++;
    }

    s[si] = '\0';

	printf("%s\n", s);
}

//------------------------------------------------------------
// FUNCTION print_bits_friendly
//------------------------------------------------------------
void print_bits_friendly(bits* b)
{
    printf("bitcount:  %d\n", b->bitcount);
    printf("bytecount: %d\n", b->bytecount);

    for(int bit = 0; bit < b->bitcount; bit++)
    {
        printf("bit %2d = %s\n", bit, get_bit(b, bit) == true ? "true" : "false");
    }
}

//------------------------------------------------------------
// FUNCTION set_bit
//------------------------------------------------------------
void set_bit(bits* b, unsigned int bit, bool value)
{
    unsigned int byte = abs((floor(bit / 8.0)) - (b->bytecount - 1));

    unsigned char localbit = bit % 8;

    if(value == true)
    {
        b->bits[byte] = b->bits[byte] | (unsigned char)pow(2, localbit);
    }
    else
    {
        b->bits[byte] = b->bits[byte] & ~ (unsigned char)pow(2, localbit);
    }
}

//------------------------------------------------------------
// FUNCTION get_bit
//------------------------------------------------------------
bool get_bit(bits* b, unsigned int bit)
{
    unsigned int byte = abs((floor(bit / 8.0)) - (b->bytecount - 1));

    unsigned char localbit = bit % 8;

    return b->bits[byte] & (unsigned char)pow(2, localbit);
}
