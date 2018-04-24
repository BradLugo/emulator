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

int decoder(){
    unsigned char *ptr;
    //An instruction can have up to 4 bytes of information
    //ins can be seen as instruction pointer
    unsigned char ins, op1, op2, op3;

    while(1){
        if((ins = get_byte(&ptr)) == 0xFF){
            printf("End of program");
            return 0;
        }
        switch(ins){
            case 0x10:
                printf("Unimplemented instruction");
                break;
            case 0x11:
                printf("Unimplemented instruction");
                break;
            case 0x12:
                printf("Unimplemented instruction");
                break;
            case 0x13:
                printf("Unimplemented instruction");
                break;
            case 0x20:
                printf("Unimplemented instruction");
                break;
            case 0x21:
                printf("Unimplemented instruction");
                break;
            case 0x22:
                printf("Unimplemented instruction");
                break;
            case 0x23:
                printf("Unimplemented instruction");
                break;
            case 0x30:
                printf("Unimplemented Instruction");
                break;
            case 0x31:
                printf("Unimplemented Instruction");
                break;
            case 0x32:
                printf("Unimplemented Instruction");
                break;
            case 0x33:
                printf("Unimplemented Instruction");
                break;
            case 0x40:
                printf("Unimplemented instruction");
                break;
            case 0x43:
                printf("Unimplemented instruction");
                break;
            case 0x50:
                printf("Unimplemented instruction");
                break;
            case 0x51:
                printf("Unimplemented instruction");
                break;
            case 0x52:
                printf("Unimplemented instruction");
                break;
            case 0x53:
                printf("Unimplemented instruction");
                break;
            case 0x60:
                printf("Unimplemented instruction");
                break;
            case 0x61:
                printf("Unimplemented instruction");
                break;
            case 0x62:
                printf("Unimplemented Instruction");
                break;
            case 0x63:
                printf("Unimplemented Instruction");
                break;
            case 0x70:
                printf("Unimplemented Instruction");
                break;
            case 0x71:
                printf("Unimplemented Instruction");
                break;
            case 0x72:
                printf("Unimplemented instruction");
                break;
            case 0x73:
                printf("Unimplemented instruction");
                break;
            case 0x80:
                printf("Unimplemented instruction");
                break;
            case 0x81:
                printf("Unimplemented instruction");
                break;
            case 0x82:
                printf("Unimplemented instruction");
                break;
            case 0x83:
                printf("Unimplemented instruction");
                break;
            case 0x84:
                printf("Unimplemented instruction");
                break;
            case 0x85:
                printf("Unimplemented instruction");
                break;
            case 0x88:
                printf("Unimplemented Instruction");
                break;
            case 0x90:
                printf("Unimplemented Instruction");
                break;
            case 0xA0:
                printf("Unimplemented Instruction");
                break;
            case 0xB8:
                printf("Unimplemented Instruction");
                break;
            case 0xB9:
                printf("Unimplemented instruction");
                break;
            case 0xC8:
                printf("Unimplemented instruction");
                break;
            case 0xC9:
                printf("Unimplemented instruction");
                break;
            case 0xD6:
                printf("Unimplemented instruction");
                break;
            case 0xD7:
                printf("Unimplemented instruction");
                break;
            case 0xD8:
                printf("Unimplemented instruction");
                break;
            case 0xD9:
                printf("Unimplemented instruction");
                break;
            case 0xDA:
                printf("Unimplemented instruction");
                break;
            case 0xDB:
                printf("Unimplemented Instruction");
                break;
            case 0xDC:
                printf("Unimplemented Instruction");
                break;
            case 0xDD:
                printf("Unimplemented Instruction");
                break;
            case 0xE0:
                break;
            default:
                printf("Unkown instruction");
                exit(-1);
        }


    }
}

/**
*   Functionally returns the next byte stored in memory
*   Modifies ptr in place
*/
unsigned char get_byte(unsigned char **ptr){
  unsigned char a = **ptr;

  ptr++;

  if(ptr == NULL){
    return NULL;
  }
  return a;
}
