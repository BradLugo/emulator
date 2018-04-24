#include <stdio.h>
#include "emulator.h"
#include "multiplexer.h"

int main() {
    printf("Hello, World!\n");
    int c = 0;
	int a = 100;
	int b = 6;
    int s0 = 0;
    printf("Before :: %d %d\n", half_adder(0, 1, &c), c);
    printf("After :: %d\n", c);
    printf("mux 2to1 0 1 switch false => %d\n", mux_2to1(0, 1, s0));
    return 0;
}
