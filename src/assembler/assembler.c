#include "assembler.h"

int parse(char *filename){
    FILE *file;
    char buffer[128];
    if((file = fopen(filename, "r")) == NULL){
        printf("Unable to open file");
    }

    char mnemonics[21][];
    int i;
    for(i=0; i < 21; i++){
        mnemonics[i] = (char *) malloc(sizeof(char)* MAX_WORD_LEN);
    }
    strcpy(mnemonics[0], "MOV");
    strcpy(mnemonics[1], "ADDC");
    strcpy(mnemonics[2], "SUBB");
    strcpy(mnemonics[3], "CMP");
    strcpy(mnemonics[4], "NOT");
    strcpy(mnemonics[5], "AND");
    strcpy(mnemonics[6], "OR");
    strcpy(mnemonics[7], "XOR");
    strcpy(mnemonics[8], "PUSH");
    strcpy(mnemonics[9], "POP");
    strcpy(mnemonics[10], "JMP");
    strcpy(mnemonics[11], "CALL");
    strcpy(mnemonics[12], "JLO");
    strcpy(mnemonics[13], "JHS");
    strcpy(mnemonics[14], "JEQ");
    strcpy(mnemonics[15], "JNE");
    strcpy(mnemonics[16], "JMI");
    strcpy(mnemonics[17], "JPL");
    strcpy(mnemonics[18], "JVS");
    strcpy(mnemonics[19], "JVC");
    strcpy(mnemonics[20], "NOP");

    char tokens[3][MAX_WORD_LEN];
    int count;

    while(fgets(buffer, 128, file) != NULL){



    }
}
