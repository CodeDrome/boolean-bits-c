
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#include"booleanbits.h"

//--------------------------------------------------------
// FUNCTION main
//--------------------------------------------------------
int main(int argc, char* argv[])
{
    puts("-----------------");
    puts("| codedrome.com |");
    puts("| Boolean Bits  |");
    puts("-----------------\n");

    bits* b = create_bits(25);

    if(b != NULL)
    {
        puts("Set bit 0 from false to true\n----------------------------");
        print_bits_unfriendly(b);
        set_bit(b, 0, true);
        print_bits_unfriendly(b);
        puts("");

        puts("Set bit 1 from false to false\n-----------------------------");
        print_bits_unfriendly(b);
        set_bit(b, 1, false);
        print_bits_unfriendly(b);
        puts("");

        puts("Set bit 2 from true to false\n----------------------------");
        set_bit(b, 2, true);
        print_bits_unfriendly(b);
        set_bit(b, 2, false);
        print_bits_unfriendly(b);
        puts("");

        puts("Set bit 3 from true to true\n---------------------------");
        set_bit(b, 3, true);
        print_bits_unfriendly(b);
        set_bit(b, 3, true);
        print_bits_unfriendly(b);
        puts("");

        print_bits_friendly(b);

        free_bits(b);
    }

    return EXIT_SUCCESS;
}
