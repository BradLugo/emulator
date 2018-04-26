#include <stdio.h>
#include <stdlib.h>
#include "emulator/emulator.h"
#include "components/components.h"

int main() {
    printf("Hello, World!\n");
    int c = 0;
    int a = 100;
    int b = 6;
    int s0 = 0;

    //printf("Before :: %d %d\n", half_adder(0, 1, &c), c);
    //printf("After :: %d\n", c);
    //printf("mux 2to1 0 1 switch false => %d\n", mux_2_to_1(0, 1, s0));

    int input = 1;
    int A = -1;
    int B = -1;
    int C = -1;
    int D = -1;
    //demux_2_to_4(input, 0, 0, &A, &B, &C, &D);
    printf("A: %d B: %d C: %d, D: %d\n", A, B, C, D);

    return EXIT_SUCCESS;
}
