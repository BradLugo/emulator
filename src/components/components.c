#include "components.h"
#include "logger.h"

void and_action(and_component_ptr component_ptr) {
    component_ptr->output = component_ptr->input_0 & component_ptr->input_1;
}

void or_action(or_component_ptr component_ptr) {
    component_ptr->output = component_ptr->input_0 | component_ptr->input_1;
}

void not_action(not_component_ptr component_ptr) {
    component_ptr->output = ~ component_ptr->input;
}

void xor_component(xor_component_ptr component_ptr) {
    component_ptr->output = component_ptr->input_0 ^ component_ptr->input_1;
}

void mux_2_to_1_action(mux_2_to_1_component_ptr component_ptr) {
    if (component_ptr->select_0) {
        component_ptr->output = component_ptr->input_1;
    } else {
        component_ptr->output = component_ptr->input_0;
    }
}

void mux_4_to_1_action(mux_4_to_1_component_ptr component_ptr) {
    // TODO :: Check if multiple selects are on
    if (component_ptr->select_1) {
        if (component_ptr->select_0) {
            component_ptr->output = component_ptr->input_3;
        } else {
            component_ptr->output = component_ptr->input_2;
        }
    } else if (component_ptr->select_0) {
        component_ptr->output = component_ptr->input_1;
    } else {
        component_ptr->output = component_ptr->input_0;
    }
}

void mux_8_to_1_action(mux_8_to_1_component_ptr component_ptr) {
    if (component_ptr->select_2) {
        if (component_ptr->select_1) {
            if (component_ptr->select_0) {
                // 1 1 1
                component_ptr->output = component_ptr->input_7;
            } else {
                // 1 1 0
                component_ptr->output = component_ptr->input_6;
            }
        } else if (component_ptr->select_0) {
            // 1 0 1
            component_ptr->output = component_ptr->input_5;
        } else {
            // 1 0 0
            component_ptr->output = component_ptr->input_4;
        }
    } else {
        if (component_ptr->select_1) {
            if (component_ptr->select_0) {
                // 0 1 1
                component_ptr->output = component_ptr->input_3;
            } else {
                // 0 1 0
                component_ptr->output = component_ptr->input_2;
            }
        } else if (component_ptr->select_0) {
            // 0 0 1
            component_ptr->output = component_ptr->input_1;
        } else {
            // 0 0 0
            component_ptr->output = component_ptr->input_0;
        }
    }
}

void demux_2_to_4_action(demux_2_to_4_component_ptr component_ptr) {
    if (component_ptr->select_1) {
        if (component_ptr->select_0) {
            component_ptr->output_3 = component_ptr->input;
        } else {
            component_ptr->output_2 = component_ptr->input;
        }
    } else {
        if (component_ptr->select_0) {
            component_ptr->output_1 = component_ptr->input;
        } else {
            component_ptr->output_0 = component_ptr->input;
        }
    }
}

void register_component_action(register_component_ptr component_ptr) {
    if (component_ptr->select && component_ptr->clock) {
        component_ptr->output = component_ptr->input;
    }
}
