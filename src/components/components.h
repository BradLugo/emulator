#ifndef COMPONENTS_H
#define COMPONENTS_H

int and(int a, int b);

int or(int a, int b);

int not(int a);

int xor(int a, int b);

int mux_2_to_1(int d0, int d1, int s0);

int mux_4_to_2(int d0, int d1, int d2, int d3, int s1, int s0);

int mux_8_to_3(int d0, int d1, int d2, int d3, int d4, int d5, int d6, int d7, int s2, int s1, int s0);

void demux_2_to_4(int input, int sel1, int sel0, int *A, int *B, int *C, int *D);

#endif //COMPONENTS_H
