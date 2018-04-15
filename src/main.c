#include <stdio.h>
#include "emulator.h"

int main() {
    printf("Hello, World!\n");
    int c = 0;
	int a = 100;
	int b = 6;
    printf("Before :: %d %d\n", half_adder(0, 1, &c), c);
    printf("After :: %d\n", c);
    return 0;
}
