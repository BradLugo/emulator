#include <stdio.h>
#include "components.h"
#include "../logger/logger.h"
void and_action(and_component_ptr component_ptr) {
    log_message(INFO_LOG_LEVEL, "AND component action called");

    char str[BUFFER_SIZE / 2];
    sprintf(str, "Input 0 :: %d", *(component_ptr->input_0));
    log_message(DEBUG_LOG_LEVEL, str);
    sprintf(str, "Input 1 :: %d", *(component_ptr->input_1));
    log_message(DEBUG_LOG_LEVEL, str);
    sprintf(str, "Output before action :: %d", *(component_ptr->output));
    log_message(DEBUG_LOG_LEVEL, str);

    *(component_ptr->output) = *(component_ptr->input_0) & *(component_ptr->input_1);

    sprintf(str, "Output after action :: %d\n", *(component_ptr->output));
    log_message(DEBUG_LOG_LEVEL, str);
}

void or_action(or_component_ptr component_ptr) {
    log_message(INFO_LOG_LEVEL, "OR component action called");

    char str[BUFFER_SIZE / 2];
    sprintf(str, "Input 0 :: %d", *(component_ptr->input_0));
    log_message(DEBUG_LOG_LEVEL, str);
    sprintf(str, "Input 1 :: %d", *(component_ptr->input_1));
    log_message(DEBUG_LOG_LEVEL, str);
    sprintf(str, "Output before action :: %d", *(component_ptr->output));
    log_message(DEBUG_LOG_LEVEL, str);

    *(component_ptr->output) = *(component_ptr->input_0) | *(component_ptr->input_1);

    sprintf(str, "Output after action :: %d\n", *(component_ptr->output));
    log_message(DEBUG_LOG_LEVEL, str);
}

void not_action(not_component_ptr component_ptr) {
    log_message(INFO_LOG_LEVEL, "NOT component action called");

    char str[BUFFER_SIZE / 2];
    sprintf(str, "Input :: %d", *(component_ptr->input));
    log_message(DEBUG_LOG_LEVEL, str);
    sprintf(str, "Output before action :: %d", *(component_ptr->output));
    log_message(DEBUG_LOG_LEVEL, str);

    *(component_ptr->output) = ~*(component_ptr->input);

    sprintf(str, "Output after action :: %d\n", *(component_ptr->output));
    log_message(DEBUG_LOG_LEVEL, str);
}

void xor_action(xor_component_ptr component_ptr) {
    log_message(INFO_LOG_LEVEL, "XOR component action called");

    char str[BUFFER_SIZE / 2];
    sprintf(str, "Input 0 :: %d", *(component_ptr->input_0));
    log_message(DEBUG_LOG_LEVEL, str);
    sprintf(str, "Input 1 :: %d", *(component_ptr->input_1));
    log_message(DEBUG_LOG_LEVEL, str);
    sprintf(str, "Output before action :: %d", *(component_ptr->output));
    log_message(DEBUG_LOG_LEVEL, str);

    *(component_ptr->output) = *(component_ptr->input_0) ^ *(component_ptr->input_1);

    sprintf(str, "Output after action :: %d\n", *(component_ptr->output));
    log_message(DEBUG_LOG_LEVEL, str);
}

void adder_subtractor_action(adder_subtractor_component_ptr component_ptr) {
    log_message(INFO_LOG_LEVEL, "ADDER-SUBTRACTOR component action called");
    log_message(INFO_LOG_LEVEL, "Note: This component may be used as a stack adder in which case, "
                                "the flags don't really matter");

    char str[BUFFER_SIZE / 2];

    if (*(component_ptr->input_2)) {
        log_message(DEBUG_LOG_LEVEL, "Determined to subtract");
        *(component_ptr->output) = *(component_ptr->input_0) - *(component_ptr->input_1);
    } else {
        log_message(DEBUG_LOG_LEVEL, "Determined to add");
        *(component_ptr->output) = *(component_ptr->input_0) + *(component_ptr->input_1);
    }

    if (*(component_ptr->output) > 511) {
        log_message(FATAL_LOG_LEVEL, "Outside of 8-bits and buffer overflow");
    }

    log_message(DEBUG_LOG_LEVEL, "Setting carry flag");
    if (*(component_ptr->output) >= 0) {
        *(component_ptr->carry) = (*(component_ptr->output) >> 8) & 1;
    } else {
        *(component_ptr->carry) = !((*(component_ptr->output) >> 8) & 1);
    }
    sprintf(str, "Carry flag :: %d", *(component_ptr->carry));
    log_message(DEBUG_LOG_LEVEL, str);

    log_message(DEBUG_LOG_LEVEL, "Setting sign flag");
    *(component_ptr->sign) = *(component_ptr->output) < 0;
    sprintf(str, "Sign flag :: %d", *(component_ptr->sign));
    log_message(DEBUG_LOG_LEVEL, str);

    log_message(DEBUG_LOG_LEVEL, "Setting zero flag");
    *(component_ptr->zero) = *(component_ptr->output) == 0;
    sprintf(str, "Zero flag :: %d", *(component_ptr->zero));
    log_message(DEBUG_LOG_LEVEL, str);

    log_message(DEBUG_LOG_LEVEL, "Setting overflow flag");
    if (*(component_ptr->output) >= 0) {
        *(component_ptr->overflow) = (*(component_ptr->output) >> 9) & 1;
    } else {
        *(component_ptr->overflow) = !((*(component_ptr->output) >> 9) & 1);
    }
    sprintf(str, "Overflow flag :: %d\n", *(component_ptr->overflow));
    log_message(DEBUG_LOG_LEVEL, str);
}

void mux_2_to_1_action(mux_2_to_1_component_ptr component_ptr) {
    log_message(INFO_LOG_LEVEL, "MUX 2-to-1 component action called");

    char str[BUFFER_SIZE / 2];
    sprintf(str, "Select 0 :: %d", *(component_ptr->select_0));
    log_message(DEBUG_LOG_LEVEL, str);
    sprintf(str, "Input 0 :: %d", *(component_ptr->input_0));
    log_message(DEBUG_LOG_LEVEL, str);
    sprintf(str, "Input 1 :: %d", *(component_ptr->input_1));
    log_message(DEBUG_LOG_LEVEL, str);
    sprintf(str, "Output before action :: %d", *(component_ptr->output));
    log_message(DEBUG_LOG_LEVEL, str);

    if (*(component_ptr->select_0)) {
        log_message(INFO_LOG_LEVEL, "Determined that Select_0 = 1");
        log_message(DEBUG_LOG_LEVEL, "Setting output to Input_1");

        *(component_ptr->output) = *(component_ptr->input_1);
    } else {
        log_message(INFO_LOG_LEVEL, "Determined that Select_0 = 0");
        log_message(DEBUG_LOG_LEVEL, "Setting output to Input_1");

        *(component_ptr->output) = *(component_ptr->input_0);
    }

    sprintf(str, "Output after action :: %d\n", *(component_ptr->output));
    log_message(DEBUG_LOG_LEVEL, str);
}

void mux_4_to_1_action(mux_4_to_1_component_ptr component_ptr) {
    log_message(INFO_LOG_LEVEL, "MUX 4-to-1 component action called");

    char str[BUFFER_SIZE / 2];
    sprintf(str, "Select 0 :: %d", *(component_ptr->select_0));
    log_message(DEBUG_LOG_LEVEL, str);
    sprintf(str, "Select 1 :: %d", *(component_ptr->select_1));
    log_message(DEBUG_LOG_LEVEL, str);
    sprintf(str, "Input 0 :: %d", *(component_ptr->input_0));
    log_message(DEBUG_LOG_LEVEL, str);
    sprintf(str, "Input 1 :: %d", *(component_ptr->input_1));
    log_message(DEBUG_LOG_LEVEL, str);
    sprintf(str, "Input 2 :: %d", *(component_ptr->input_2));
    log_message(DEBUG_LOG_LEVEL, str);
    sprintf(str, "Input 3 :: %d", *(component_ptr->input_3));
    log_message(DEBUG_LOG_LEVEL, str);
    sprintf(str, "Output before action :: %d", *(component_ptr->output));
    log_message(DEBUG_LOG_LEVEL, str);

    // TODO :: Check if multiple selects are on
    if (*(component_ptr->select_1)) {
        log_message(INFO_LOG_LEVEL, "Determined that Select_1 = 1");

        if (*(component_ptr->select_0)) {
            log_message(INFO_LOG_LEVEL, "Determined that Select_0 = 1");
            log_message(DEBUG_LOG_LEVEL, "Setting output to Input_3");

            *(component_ptr->output) = *(component_ptr->input_3);
        } else {
            log_message(INFO_LOG_LEVEL, "Determined that Select_0 = 0");
            log_message(DEBUG_LOG_LEVEL, "Setting output to Input_2");

            *(component_ptr->output) = *(component_ptr->input_2);
        }
    } else if (*(component_ptr->select_0)) {
        log_message(INFO_LOG_LEVEL, "Determined that Select_1 = 0");
        log_message(INFO_LOG_LEVEL, "Determined that Select_0 = 1");
        log_message(DEBUG_LOG_LEVEL, "Setting output to Input_1");

        *(component_ptr->output) = *(component_ptr->input_1);
    } else {
        log_message(INFO_LOG_LEVEL, "Determined that Select_1 = 0");
        log_message(INFO_LOG_LEVEL, "Determined that Select_0 = 0");
        log_message(DEBUG_LOG_LEVEL, "Setting output to Input_0");

        *(component_ptr->output) = *(component_ptr->input_0);
    }

    sprintf(str, "Output after action :: %d\n", *(component_ptr->output));
    log_message(DEBUG_LOG_LEVEL, str);
}

void mux_8_to_1_action(mux_8_to_1_component_ptr component_ptr) {
    log_message(INFO_LOG_LEVEL, "MUX 8-to-1 component action called");

    char str[BUFFER_SIZE / 2];
    sprintf(str, "Select 0 :: %d", *(component_ptr->select_0));
    log_message(DEBUG_LOG_LEVEL, str);
    sprintf(str, "Select 1 :: %d", *(component_ptr->select_1));
    log_message(DEBUG_LOG_LEVEL, str);
    sprintf(str, "Input 0 :: %d", *(component_ptr->input_0));
    log_message(DEBUG_LOG_LEVEL, str);
    sprintf(str, "Input 1 :: %d", *(component_ptr->input_1));
    log_message(DEBUG_LOG_LEVEL, str);
    sprintf(str, "Input 2 :: %d", *(component_ptr->input_2));
    log_message(DEBUG_LOG_LEVEL, str);
    sprintf(str, "Input 3 :: %d", *(component_ptr->input_3));
    log_message(DEBUG_LOG_LEVEL, str);
    sprintf(str, "Input 4 :: %d", *(component_ptr->input_4));
    log_message(DEBUG_LOG_LEVEL, str);
    sprintf(str, "Input 5 :: %d", *(component_ptr->input_5));
    log_message(DEBUG_LOG_LEVEL, str);
    sprintf(str, "Input 6 :: %d", *(component_ptr->input_6));
    log_message(DEBUG_LOG_LEVEL, str);
    sprintf(str, "Input 7 :: %d", *(component_ptr->input_7));
    log_message(DEBUG_LOG_LEVEL, str);
    sprintf(str, "Output before action :: %d", *(component_ptr->output));
    log_message(DEBUG_LOG_LEVEL, str);

    if (*(component_ptr->select_2)) {
        log_message(INFO_LOG_LEVEL, "Determined that Select_2 = 1");
        if (*(component_ptr->select_1)) {
            log_message(INFO_LOG_LEVEL, "Determined that Select_1 = 1");
            if (*(component_ptr->select_0)) {
                log_message(INFO_LOG_LEVEL, "Determined that Select_0 = 1");
                log_message(DEBUG_LOG_LEVEL, "Setting output to Input_7");

                // 1 1 1
                *(component_ptr->output) = *(component_ptr->input_7);
            } else {
                log_message(INFO_LOG_LEVEL, "Determined that Select_0 = 0");
                log_message(DEBUG_LOG_LEVEL, "Setting output to Input_6");

                // 1 1 0
                *(component_ptr->output) = *(component_ptr->input_6);
            }
        } else if (*(component_ptr->select_0)) {
            log_message(INFO_LOG_LEVEL, "Determined that Select_1 = 0");
            log_message(INFO_LOG_LEVEL, "Determined that Select_0 = 1");
            log_message(DEBUG_LOG_LEVEL, "Setting output to Input_5");

            // 1 0 1
            *(component_ptr->output) = *(component_ptr->input_5);
        } else {
            log_message(INFO_LOG_LEVEL, "Determined that Select_1 = 0");
            log_message(INFO_LOG_LEVEL, "Determined that Select_0 = 0");
            log_message(DEBUG_LOG_LEVEL, "Setting output to Input_4");

            // 1 0 0
            *(component_ptr->output) = *(component_ptr->input_4);
        }
    } else {
        log_message(INFO_LOG_LEVEL, "Determined that Select_2 = 0");
        if (*(component_ptr->select_1)) {
            log_message(INFO_LOG_LEVEL, "Determined that Select_1 = 1");
            if (*(component_ptr->select_0)) {
                log_message(INFO_LOG_LEVEL, "Determined that Select_0 = 1");
                log_message(DEBUG_LOG_LEVEL, "Setting output to Input_3");

                // 0 1 1
                *(component_ptr->output) = *(component_ptr->input_3);
            } else {
                log_message(INFO_LOG_LEVEL, "Determined that Select_0 = 0");
                log_message(DEBUG_LOG_LEVEL, "Setting output to Input_2");

                // 0 1 0
                *(component_ptr->output) = *(component_ptr->input_2);
            }
        } else if (*(component_ptr->select_0)) {
            log_message(INFO_LOG_LEVEL, "Determined that Select_1 = 0");
            log_message(INFO_LOG_LEVEL, "Determined that Select_0 = 1");
            log_message(DEBUG_LOG_LEVEL, "Setting output to Input_1");

            // 0 0 1
            *(component_ptr->output) = *(component_ptr->input_1);
        } else {
            log_message(INFO_LOG_LEVEL, "Determined that Select_1 = 0");
            log_message(INFO_LOG_LEVEL, "Determined that Select_0 = 0");
            log_message(DEBUG_LOG_LEVEL, "Setting output to Input_0");

            // 0 0 0
            *(component_ptr->output) = *(component_ptr->input_0);
        }
    }

    sprintf(str, "Output after action :: %d\n", *(component_ptr->output));
    log_message(DEBUG_LOG_LEVEL, str);
}

void demux_2_to_4_action(demux_2_to_4_component_ptr component_ptr) {
    log_message(INFO_LOG_LEVEL, "DEMUX 2-to-4 component action called");

    char str[BUFFER_SIZE / 2];
    sprintf(str, "Select 0 :: %d", *(component_ptr->select_0));
    log_message(DEBUG_LOG_LEVEL, str);
    sprintf(str, "Select 1 :: %d", *(component_ptr->select_1));
    log_message(DEBUG_LOG_LEVEL, str);
    sprintf(str, "Input :: %d", *(component_ptr->input));
    log_message(DEBUG_LOG_LEVEL, str);
    sprintf(str, "Output_0 before action :: %d", *(component_ptr->output_0));
    log_message(DEBUG_LOG_LEVEL, str);
    sprintf(str, "Output_1 before action :: %d", *(component_ptr->output_1));
    log_message(DEBUG_LOG_LEVEL, str);
    sprintf(str, "Output_2 before action :: %d", *(component_ptr->output_2));
    log_message(DEBUG_LOG_LEVEL, str);
    sprintf(str, "Output_3 before action :: %d", *(component_ptr->output_3));
    log_message(DEBUG_LOG_LEVEL, str);

    if (*(component_ptr->select_1)) {
        if (*(component_ptr->select_0)) {
            *(component_ptr->output_3) = *(component_ptr->input);
        } else {
            *(component_ptr->output_2) = *(component_ptr->input);
        }
    } else {
        if (*(component_ptr->select_0)) {
            *(component_ptr->output_1) = *(component_ptr->input);
        } else {
            *(component_ptr->output_0) = *(component_ptr->input);
        }
    }

    sprintf(str, "Output_0 after action :: %d", *(component_ptr->output_0));
    log_message(DEBUG_LOG_LEVEL, str);
    sprintf(str, "Output_1 after action :: %d", *(component_ptr->output_1));
    log_message(DEBUG_LOG_LEVEL, str);
    sprintf(str, "Output_2 after action :: %d", *(component_ptr->output_2));
    log_message(DEBUG_LOG_LEVEL, str);
    sprintf(str, "Output_3 after action :: %d\n", *(component_ptr->output_3));
    log_message(DEBUG_LOG_LEVEL, str);
}

void register_action(register_component_ptr component_ptr) {
    log_message(INFO_LOG_LEVEL, "Register component action called");

    char str[BUFFER_SIZE / 2];
    sprintf(str, "Input :: %d", *(component_ptr->input));
    log_message(DEBUG_LOG_LEVEL, str);
    sprintf(str, "Select :: %d", *(component_ptr->select));
    log_message(DEBUG_LOG_LEVEL, str);
    sprintf(str, "Clock :: %d", *(component_ptr->clock));
    log_message(DEBUG_LOG_LEVEL, str);
    sprintf(str, "Output before action :: %d", *(component_ptr->output));
    log_message(DEBUG_LOG_LEVEL, str);

    if (*(component_ptr->select) && *(component_ptr->clock)) {
        *(component_ptr->output) = *(component_ptr->input);
    }

    sprintf(str, "Output after action :: %d\n", *(component_ptr->output));
    log_message(DEBUG_LOG_LEVEL, str);
}

void memory_action(memory_component_ptr component_ptr){
    log_message(INFO_LOG_LEVEL, "Memory component action called");

    char str[BUFFER_SIZE / 2];
    sprintf(str, "Selected chip %d", *(component_ptr->chip_sel)/0x1000);
    log_message(INFOR_LOG_LEVEL, str);

}
