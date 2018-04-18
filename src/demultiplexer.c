#include "demultiplexer.h"

void demux_1to4(int input, int sel1, int sel2, int *A, int *B, int *C, int *D){
	if(sel1){
		if(sel2){
			*D = input;
			return;
		}
		*C = input;
		return;
	}
	if(sel2){
		*B = input;
		return;
	}
	*A = input;
}