#include <stdio.h>
#include "emulator.h"
#include "demultiplexer.h"

int main() {
    printf("Hello, World!\n");
    int c = 0;
    printf("Before :: %d %d\n", half_adder(0, 1, &c), c);
    printf("After :: %d\n", c);
    int input = 1;
    int A = -1;
    int B = -1;
    int C = -1;
    int D = -1;
    demux_1to4(input, 0, 0, &A, &B, &C, &D);
    printf("A: %d B: %d C: %d, D: %d\n", A, B, C, D);
    return 0;
}