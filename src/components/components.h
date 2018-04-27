#ifndef COMPONENTS_H
#define COMPONENTS_H

typedef struct and_component {
    unsigned int *input_0;
    unsigned int *input_1;
    unsigned int *output;
} *and_component_ptr;

typedef struct or_component {
    unsigned int *input_0;
    unsigned int *input_1;
    unsigned int *output;
} *or_component_ptr;

typedef struct not_component {
    unsigned int *input;
    unsigned int *output;
} *not_component_ptr;

typedef struct xor_component {
    unsigned int *input_0;
    unsigned int *input_1;
    unsigned int *output;
} *xor_component_ptr;

typedef struct adder_subtractor_component {
    // TODO :: Fix the unsigned ints
    int *input_0;
    int *input_1;
    unsigned int *input_2;
    int *output;
    unsigned int *carry;
    unsigned int *sign;
    unsigned int *zero;
    unsigned int *overflow;
} *adder_subtractor_component_ptr;

typedef struct mux_2_to_1_component {
    unsigned int *input_0;
    unsigned int *input_1;
    unsigned int *select_0;
    unsigned int *output;
} *mux_2_to_1_component_ptr;

typedef struct mux_4_to_1_component {
    unsigned int *input_0;
    unsigned int *input_1;
    unsigned int *input_2;
    unsigned int *input_3;
    unsigned int *select_0;
    unsigned int *select_1;
    unsigned int *output;
} *mux_4_to_1_component_ptr;

typedef struct mux_8_to_1_component {
    unsigned int *input_0;
    unsigned int *input_1;
    unsigned int *input_2;
    unsigned int *input_3;
    unsigned int *input_4;
    unsigned int *input_5;
    unsigned int *input_6;
    unsigned int *input_7;
    unsigned int *select_0;
    unsigned int *select_1;
    unsigned int *select_2;
    unsigned int *output;
} *mux_8_to_1_component_ptr;

typedef struct demux_2_to_4_component {
    unsigned int *input;
    unsigned int *select_0;
    unsigned int *select_1;
    unsigned int *output_0;
    unsigned int *output_1;
    unsigned int *output_2;
    unsigned int *output_3;
} *demux_2_to_4_component_ptr;

typedef struct register_component {
    unsigned int *input;
    unsigned int *select;
    unsigned int *clock;
    unsigned int *output;
} *register_component_ptr;


typedef struct memory_component{
    unsigned char *MEMORY[16];
    unsigned char *eprom;
    unsigned int *offset;
    unsigned int *chip_sel;
    unsigned int *output;
} *memory_component_ptr;

typedef struct transmission_gate_component{
    unsigned int *output_enable;
    unsigned int *data_line_out;
} *transmission_gate_component_ptr;

typedef struct decoder_4_to_16_component{
    unsigned int *input_0;
    unsigned int *input_1;
    unsigned int *input_2;
    unsigned int *input_3;

    unsigned int *output;
} decoder_4_to_16_component_ptr;






void and_action(and_component_ptr component_ptr);

void or_action(or_component_ptr component_ptr);

void not_action(not_component_ptr component_ptr);

void xor_action(xor_component_ptr component_ptr);

void adder_subtractor_action(adder_subtractor_component_ptr);

void mux_2_to_1_action(mux_2_to_1_component_ptr component_ptr);

void mux_4_to_1_action(mux_4_to_1_component_ptr component_ptr);

void mux_8_to_1_action(mux_8_to_1_component_ptr component_ptr);

void demux_2_to_4_action(demux_2_to_4_component_ptr component_ptr);

void register_action(register_component_ptr component_ptr);

void init_memory(unsigned char *memory, char *filename);

void memory_action(memory_component_ptr component_ptr);
#endif //COMPONENTS_H
