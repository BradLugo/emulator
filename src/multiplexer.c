#include "multiplexer.h"

int mux_2to1(int d0, int d1, int s0){
    if(s0){
        return d1;
    }
    return d0;
}

int mux_4to1(int d0, int d1, int d2, int d3, int s0, int s1){
    //if true return one of bottom 2
    if(s1){
        //if true return bottom 
        if(s0){
            return d3;
        }
        return d2;
    }
    //else return one of top 2
    if(s0){
        return d1;
    }
    return d0;

}

int mux_8to1(int d0, int d1, int d2, int d3, int d4, int d5, int d6, int d7, int s0, int s1, int s2){
    //if true return one of bottom 4
    if(s0){
        if(s1){
            if(s2){
                //1 1 1
                return d7;
            }
            //1 1 0
            return d6;
        }else{
            if(s2){
                //1 0 1
                return d5;
            }
        }
        //1 0 0 
        return d4;
    }
    //else return one of top 4
    if(s1){
        if(s2){
            //0 1 1
            return d3;
        }
        //0 1 0
        return d2;
    }else{
        if(s2){
            //0 0 1
            return d1;
        }
    }
    //0 0 0
    return d0;
}