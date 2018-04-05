#ifndef MULTIPLEXER_MULTIPLEXER_H
#define MULTIPLEXER_MULTIPLEXER_H
int mux_2to1(int d0, int d1, int s0);
int mux_4to1(int d0, int d1, int d2, int d3, int s0, int s1);
int mux_8to1(int d0, int d1, int d2, int d3, int d4, int d5, int d6, int d7, int s0, int s1, int s2);

#endif