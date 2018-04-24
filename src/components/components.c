#include "components.h"

int and(int a, int b) {
    return a && b;
}

int or(int a, int b) {
    return a || b;
}

int not(int a) {
    return !a;
}

int xor(int a, int b) {
    return a != b;
}

int mux_2_to_1(int d0, int d1, int s0) {
    if (s0) {
        return d1;
    }
    return d0;
}

int mux_4_to_1(int d0, int d1, int d2, int d3, int s1, int s0) {
    //if true return one of bottom 2
    if (s1) {
        //if true return bottom
        if (s0) {
            return d3;
        }
        return d2;
    }
    //else return one of top 2
    if (s0) {
        return d1;
    }
    return d0;

}

int mux_8_to_1(int d0, int d1, int d2, int d3, int d4, int d5, int d6, int d7, int s2, int s1, int s0) {
    //if true return one of bottom 4
    if (s2) {
        if (s1) {
            if (s0) {
                //1 1 1
                return d7;
            }
            //1 1 0
            return d6;
        } else {
            if (s0) {
                //1 0 1
                return d5;
            }
        }
        //1 0 0
        return d4;
    }
    //else return one of top 4
    if (s1) {
        if (s0) {
            //0 1 1
            return d3;
        }
        //0 1 0
        return d2;
    } else {
        if (s0) {
            //0 0 1
            return d1;
        }
    }
    //0 0 0
    return d0;
}

void demux_2_to_4(int input, int sel1, int sel0, int *A, int *B, int *C, int *D) {
    if (sel1) {
        if (sel0) {
            *D = input;
            return;
        }
        *C = input;
        return;
    }
    if (sel0) {
        *B = input;
        return;
    }
    *A = input;
}
