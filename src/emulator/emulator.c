#include <stdio.h>
#include <stdlib.h>
#include "emulator.h"
#include "../components/components.h"
#include <string.h>

void data_line_action(unsigned int *data_line, unsigned int *input_0, unsigned int *input_1) {
    *data_line = (*input_0 << 8) | *input_1;
}

void emulator(char *filename) {
    int i;
    unsigned int clock = 0;
    unsigned int stack = 2;

    unsigned int memory = 0;
    //unsigned char *MEMORY[16];
    unsigned int flags = 0;
    unsigned int instruction = 0;

    unsigned int data = 0;

    unsigned int U_500_inst_len = 0;
    unsigned int U_500_offset = 0;
    unsigned int U_500_instruction = 0;
    unsigned int *U_500_mem_0;
    unsigned int *U_500_mem_1;
    unsigned int *U_500_mem_2;
    unsigned int *U_500_mem_3;

    memory_component_ptr U_200s = (memory_component_ptr) malloc(sizeof(struct memory_component));

    for(i = 0;i < 16;i++){
        if(i== 14)continue;
        U_200s->MEMORY[i] = (unsigned char*) malloc(0x1000);
    }

    init_memory(U_200s->MEMORY[15], filename);

    U_200s->eprom = U_200s->MEMORY[15];

    // Wire U_500

    unsigned int U_114_output_0 = 0;
    unsigned int U_10_output = 0;
    // Wire U_10
    register_component_ptr U_10 = (register_component_ptr) malloc(sizeof(struct register_component));
    U_10->clock = &clock;
    U_10->select = &U_114_output_0;
    U_10->input = &U_114_output_0;
    U_10->output = &U_10_output;

    unsigned int U_114_output_1 = 0;
    unsigned int U_11_output = 0;
    // Wire U_11
    register_component_ptr U_11 = (register_component_ptr) malloc(sizeof(struct register_component));
    U_11->clock = &clock;
    U_11->select = &U_114_output_1;
    U_11->input = &U_114_output_1;
    U_11->output = &U_11_output;

    unsigned int U_114_output_2 = 0;
    unsigned int U_12_output = 0;
    // Wire U_12
    register_component_ptr U_12 = (register_component_ptr) malloc(sizeof(struct register_component));
    U_12->clock = &clock;
    U_12->select = &U_114_output_2;
    U_12->input = &U_114_output_2;
    U_12->output = &U_12_output;

    unsigned int U_114_output_3 = 0;
    unsigned int U_13_output = 0;
    // Wire U_13
    register_component_ptr U_13 = (register_component_ptr) malloc(sizeof(struct register_component));
    U_13->clock = &clock;
    U_13->select = &U_114_output_3;
    U_13->input = &U_114_output_3;
    U_13->output = &U_13_output;

    unsigned int U_117_output = 0;
    unsigned int U_14_output = 0;
    unsigned int U_14_select = 0;
    // Wire U_14
    register_component_ptr U_14 = (register_component_ptr) malloc(sizeof(struct register_component));
    U_14->clock = &clock;
    U_14->select = &U_14_select;
    U_14->input = &U_117_output;
    U_14->output = &U_14_output;

    unsigned int U_115_output = 0;
    unsigned int U_15_output = 0;
    unsigned int U_15_select = 0;
    // Wire U_15
    register_component_ptr U_15 = (register_component_ptr) malloc(sizeof(struct register_component));
    U_15->clock = &clock;
    U_15->select = &U_15_select;
    U_15->input = &U_115_output;
    U_15->output = &U_14_output;

    unsigned int U_120_output = 0;
    unsigned int U_110_output = 0;
    // Wire U_110
    register_component_ptr U_110 = (register_component_ptr) malloc(sizeof(struct register_component));
    U_110->clock = &clock;
    U_110->select = &stack;
    U_110->input = &U_120_output;
    U_110->output = &U_110_output;

    unsigned int U_112_output = 0;
    unsigned int U_112_select_0 = 0;
    unsigned int U_112_select_1 = 0;
    unsigned int U_112_select_2 = 0;
    // Wire U_112
    mux_8_to_1_component_ptr U_112 = (mux_8_to_1_component_ptr) malloc(sizeof(struct mux_8_to_1_component));
    U_112->select_0 = &U_112_select_0;
    U_112->select_1 = &U_112_select_1;
    U_112->select_2 = &U_112_select_2;
    U_112->input_0 = &U_10_output;
    U_112->input_1 = &U_11_output;
    U_112->input_2 = &U_12_output;
    U_112->input_3 = &U_13_output;
    U_112->input_4 = &memory;
    U_112->input_5 = &flags;
    U_112->input_6 = &instruction;
    U_112->output = &U_112_output;

    unsigned int U_113_output = 0;
    unsigned int U_113_select_0 = 0;
    unsigned int U_113_select_1 = 0;
    unsigned int U_113_select_2 = 0;
    // Wire U_113
    mux_8_to_1_component_ptr U_113 = (mux_8_to_1_component_ptr) malloc(sizeof(struct mux_8_to_1_component));
    U_113->select_0 = &U_113_select_0;
    U_113->select_1 = &U_113_select_1;
    U_113->select_2 = &U_113_select_2;
    U_113->input_0 = &U_10_output;
    U_113->input_1 = &U_11_output;
    U_113->input_2 = &U_12_output;
    U_113->input_3 = &U_13_output;
    U_113->input_4 = &memory;
    U_113->input_5 = &flags;
    U_113->input_6 = &instruction;
    U_113->output = &U_113_output;

    int U_107_output = 0;
    // Wire U_107
    adder_subtractor_component_ptr U_107 = (adder_subtractor_component_ptr) malloc(
            sizeof(struct adder_subtractor_component));
    U_107->input_0 = &U_14_output;
    U_107->input_1 = &stack;
    U_107->input_2 = &stack;
    U_107->output = &U_107_output;

    int U_105_output = 0;
    // Wire U_105
    adder_subtractor_component_ptr U_105 = (adder_subtractor_component_ptr) malloc(
            sizeof(struct adder_subtractor_component));
    U_105->input_0 = &U_15_output;
    U_105->input_1 = &U_500_inst_len;
    U_105->output = &U_105_output;

    unsigned int U_100_output = 0;
    // Wire U_100
    adder_subtractor_component_ptr U_100 = (adder_subtractor_component_ptr) malloc(
            sizeof(struct adder_subtractor_component));
    U_100->input_0 = &U_112_output;
    U_100->input_1 = &U_113_output;
    U_100->output = &U_100_output;
    U_200s->chip_sel = U_100->output;


    unsigned int U_101_output = 0;
    // Wire U_101
    and_component_ptr U_101 = (and_component_ptr) malloc(sizeof(struct and_component));
    U_101->input_0 = &U_112_output;
    U_101->input_1 = &U_113_output;
    U_101->output = &U_101_output;

    unsigned int U_102_output = 0;
    // Wire U_102
    or_component_ptr U_102 = (or_component_ptr) malloc(sizeof(struct or_component));
    U_102->input_0 = &U_112_output;
    U_102->input_1 = &U_113_output;
    U_102->output = &U_102_output;

    unsigned int U_103_output = 0;
    // Wire U_103
    xor_component_ptr U_103 = (xor_component_ptr) malloc(sizeof(struct xor_component));
    U_103->input_0 = &U_112_output;
    U_103->input_1 = &U_113_output;
    U_103->output = &U_103_output;

    unsigned int U_104_output = 0;
    // Wire U_104
    not_component_ptr U_104 = (not_component_ptr) malloc(sizeof(struct not_component));
    U_104->input = &U_113_output;
    U_104->output = &U_104_output;

    unsigned int U_106_output = 0;
    // Wire U_106
    adder_subtractor_component_ptr U_106 = (adder_subtractor_component_ptr) malloc(
            sizeof(struct adder_subtractor_component));
    U_106->input_0 = &U_105_output;
    U_106->input_1 = &U_500_offset;
    U_106->output = &U_106_output;

    unsigned int U_116_output = 0;
    unsigned int U_116_select_0 = 0;
    unsigned int U_116_select_1 = 0;
    // Wire U_116
    mux_4_to_1_component_ptr U_116 = (mux_4_to_1_component_ptr) malloc(sizeof(struct mux_4_to_1_component));
    U_116->select_0 = U_116_select_0;
    U_116->select_1 = U_116_select_1;
    U_116->input_0 = &U_15_output;
    U_116->input_1 = &U_14_output;
    U_116->input_2 = &U_500_instruction;
    U_116->input_3 = &data;
    U_116->output = &U_116_output;

    unsigned int U_117_select_0 = 0;
    // Wire U_117
    mux_2_to_1_component_ptr U_117 = (mux_2_to_1_component_ptr)  malloc(sizeof(struct mux_2_to_1_component));
    U_117->select_0 = &U_117_select_0;
    U_117->input_0 = &data;
    U_117->input_1 = &U_107;//This can be set during the while loop!
    U_117->output = &U_117_output;

    unsigned int U_111_output = 0;
    unsigned int U_111_select_0 = 0;
    unsigned int U_111_select_1 = 0;
    unsigned int U_111_select_2 = 0;
    // Wire U_111
    mux_8_to_1_component_ptr U_111 = (mux_8_to_1_component_ptr) malloc(sizeof(struct mux_8_to_1_component));
    U_111->select_0 = &U_111_select_0;
    U_111->select_1 = &U_111_select_1;
    U_111->select_2 = &U_111_select_2;
    U_111->input_0 = &U_100_output;
    U_111->input_1 = &U_101_output;
    U_111->input_2 = &U_102_output;
    U_111->input_3 = &U_103_output;
    U_111->input_4 = &U_104_output;
    U_111->output = U_111_output;

    unsigned int U_115_select_0 = 0;
    unsigned int U_115_select_1 = 0;
    // Wire U_115
    mux_4_to_1_component_ptr U_115 = (mux_4_to_1_component_ptr) malloc(sizeof(struct mux_4_to_1_component));
    U_115->select_0 = &U_115_select_0;
    U_115->select_1 = &U_115_select_1;
    U_115->input_0 = &data;
    U_115->input_1 = &U_500_instruction;
    U_115->input_2 = &U_105_output;
    U_115->input_3 = &U_106_output;
    U_115->output = &U_115_output;

    unsigned int U_220_output = 0;
    unsigned int U_220_select_0 = 0;
    unsigned int U_220_select_1 = 0;
    // Wire U_220
    mux_4_to_1_component_ptr U_220 = (mux_4_to_1_component_ptr) malloc(sizeof(struct mux_4_to_1_component));
    U_220->select_0 = &U_220_select_0;
    U_220->select_1 = &U_220_select_1;
    U_220->input_0 = &U_112_output;
    U_220->input_1 = &U_113_output;
    U_220->input_2 = &U_111_output;
    U_220->input_3 = &U_500_instruction;
    U_220->output = &U_220_output;

    // Wire U_221
    // TODO :: Tranmission gate
    //transmission_gate_component_ptr U_221 = (transmission_gate_component_ptr) malloc(sizeof (struct transmission_gate_component));
    unsigned int U_221_output;
    unsigned int U_221_oe;
    transmission_gate_component_ptr U_221 = (transmission_gate_component_ptr) malloc(sizeof(struct transmission_gate_component));
    U_221->data_line_out = &U_221_output;
    U_221->output_enable = &U_221_oe;

    unsigned int U_120_select_0 = 0;
    // Wire U_120
    mux_2_to_1_component_ptr U_120 = (mux_2_to_1_component_ptr) malloc(sizeof(struct mux_2_to_1_component));
    U_120->select_0 = &U_120_select_0;
    U_120->input_0 = &U_100_output;
    U_120->input_1 = &U_111_output;
    U_120->output = &U_120_output;

    unsigned int U_118_A_select_0 = 0;
    unsigned int U_118_A_select_1 = 0;
    unsigned int U_118_A_select_2 = 0;
    unsigned int U_118_A_output = 0;
    // Wire U_118_A
    mux_8_to_1_component_ptr U_118_A = (mux_8_to_1_component_ptr) malloc(sizeof(struct mux_8_to_1_component));
    U_118_A->select_0 = &U_118_A_select_0;
    U_118_A->select_1 = &U_118_A_select_1;
    U_118_A->select_2 = &U_118_A_select_2;
    U_118_A->input_0 = &data;
    U_118_A->input_1 = &U_14_output;
    U_118_A->input_2 = &U_500_instruction;
    U_118_A->input_3 = &U_111_output;
    U_118_A->input_5 = &memory;
    U_118_A->output = &U_118_A_output;

    unsigned int U_118_B_select_0 = 0;
    unsigned int U_118_B_select_1 = 0;
    unsigned int U_118_B_select_2 = 0;
    unsigned int U_118_B_output = 0;
    // Wire U_118_B
    mux_8_to_1_component_ptr U_118_B = (mux_8_to_1_component_ptr) malloc(sizeof(struct mux_8_to_1_component));
    U_118_B->select_0 = &U_118_B_select_0;
    U_118_B->select_1 = &U_118_B_select_1;
    U_118_B->select_2 = &U_118_B_select_2;
    U_118_B->input_0 = &data;
    U_118_B->input_1 = &U_14_output;
    U_118_B->input_2 = &U_500_instruction;
    U_118_B->input_3 = &U_111_output;
    U_118_B->input_5 = &memory;
    U_118_B->output = &U_118_B_output;

    // Wire U_114
    demux_2_to_4_component_ptr U_114 = (demux_2_to_4_component_ptr) malloc(sizeof(struct demux_2_to_4_component));

    // This is where the loop should run
    // while()
    unsigned int output_enable;
    unsigned int select = 1;
    unsigned int no_select = 0;
    U_500_instruction = 0xf000;

    U_116->select_1 = &select;
    U_116->select_0 = &no_select;
    U_116->input_2 = &U_500_instruction;
    mux_4_to_1_action(U_116);
    U_200s->chip_sel = U_116->output;
    memory_action(U_200s);


    printf("End of test");
    getchar();
    // This is *generally* how the loop should run
/*
    mux_8_to_1_action(U_112);
    mux_8_to_1_action(U_113);

    adder_subtractor_action(U_107);
    adder_subtractor_action(U_105);
    adder_subtractor_action(U_100);

    and_action(U_101);
    or_action(U_102);
    xor_action(U_103);
    not_action(U_104);

    adder_subtractor_action(U_106);

    mux_4_to_1_action(U_116);

    mux_2_to_1_action(U_117);

    mux_8_to_1_action(U_111);

    mux_4_to_1_action(U_115);
    mux_4_to_1_action(U_220);

    //mux_8_to_1_action(U_118_A);
    mux_8_to_1_action(U_118_B);

    register_action(U_10);
    register_action(U_11);
    register_action(U_12);
    register_action(U_13);
    register_action(U_14);
    register_action(U_15);
    register_action(U_110);
    printf("Before seg fault");
    getchar();
*/
//    free(U_500);
    free(U_10);
    free(U_11);
    free(U_12);
    free(U_13);
    free(U_14);
    free(U_15);
    free(U_110);
    free(U_112);
    free(U_113);
    free(U_107);
    free(U_105);
    free(U_100);
    free(U_101);
    free(U_102);
    free(U_103);
    free(U_104);
    free(U_106);
    free(U_116);
    free(U_117);
    free(U_111);
    free(U_115);
    free(U_220);
//    free(U_221);
    free(U_120);
    free(U_118_A);
    free(U_118_B);
    free(U_114);
}


void init_memory(unsigned char *memory, char *filename){
    FILE *file;
    if((file = fopen(filename, "r")) == NULL){
        printf("Unable to open file");
        exit(-1);
    }
    printf("FILE opened");

    //read file instructions into EPROM Location
    int j = 0;
    unsigned char buff;
    while(fscanf(file, "%02X",(unsigned int*) &buff) != EOF && (j < 0x1000)){
        memcpy(&memory[j], &buff, sizeof(unsigned char));
        printf("GOT: %x\n", buff);
        j++;
    }
}
