#include "emulator.h"

int half_adder(int a, int b, int *cout)
{
    *cout = a & b;
    return a ^ b;
}

int full_adder(int a, int b, int cin, int *cout)
{
    int xor = a ^ b;
    *cout = (xor & cin) | (a & b);
    return xor ^ cin;
}