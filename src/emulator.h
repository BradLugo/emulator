//
// Created by Christian Lugo on 2/13/18.
//

#ifndef EMULATOR_EMULATOR_H
#define EMULATOR_EMULATOR_H
//IINCLUDES
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Global Variables
unsigned char* MEMORY[16];

int half_adder(int a, int b, int *cout);
int full_adder(int a, int b, int cin, int *cout);

int init_emulator(char* filename);
unsigned char get_byte(unsigned char **ptr);

#endif //EMULATOR_EMULATOR_H
