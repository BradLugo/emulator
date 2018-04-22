//
// Created by Christian Lugo on 2/13/18.
//

#include "emulator.h"

int half_adder(int a, int b, int *cout)
{
    *cout = a & b;
    return a ^ b;
}

int full_adder(int a, int b, int cin, int *cout)
{
    int xor = a ^ b;
    *cout = (xor & cin) | (a & b);
    return xor ^ cin;
}

int init_emulator(char *filename)
{
    int i, j;
    FILE* file;
    //allocate space for memory
    for (i = 0; i < 16; i++)
    {
        if(i==14)continue;//IO is not emulated in this case
        MEMORY[i] = (unsigned char *)malloc(0x1000*sizeof(unsigned char));
        if(MEMORY[i] == NULL)
        {
            printf("Error allocating memory at component %d", i);
            return -1;
        }
    }

    if((file = fopen(filename, "r")) == NULL){
        printf("Unable to open file");
        return -1;
    }

    //read file instructions into EPROM Location
    j = 0;
    unsigned char buff;
    while(fscanf(file, "%02X",(unsigned int*) &buff) != EOF && (j < 0x1000)){
        memcpy(&MEMORY[15][j], &buff, sizeof(unsigned char));
        j++;
    }
    MEMORY[15][j] = '\0';

    //Set the state of any structures here
    return 0;
}


