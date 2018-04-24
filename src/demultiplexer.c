#include "demultiplexer.h"

void demux_2to4(int input, int sel1, int sel0, int *A, int *B, int *C, int *D){
	if(sel1){
		if(sel0){
			*D = input;
			return;
		}
		*C = input;
		return;
	}
	if(sel0){
		*B = input;
		return;
	}
	*A = input;
}
