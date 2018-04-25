#include <time.h>
#include <stdlib.h>
#include <memory.h>
#include <components.h>
#include "unity.h"
#include "logger.h"

void setUp(void) {
}

void tearDown(void) {
}

void test_and(void) {
    and_component_ptr component_ptr = (and_component_ptr) malloc(sizeof(struct and_component));
    component_ptr->output = 0;

    component_ptr->input_0 = 1;
    component_ptr->input_1 = 1;
    and_action(component_ptr);
    TEST_ASSERT_EQUAL(1, component_ptr->output);

    component_ptr->input_0 = 1;
    component_ptr->input_1 = 0;
    and_action(component_ptr);
    TEST_ASSERT_EQUAL(0, component_ptr->output);

    component_ptr->input_0 = 0;
    component_ptr->input_1 = 1;
    and_action(component_ptr);
    TEST_ASSERT_EQUAL(0, component_ptr->output);

    component_ptr->input_0 = 0;
    component_ptr->input_1 = 0;
    and_action(component_ptr);
    TEST_ASSERT_EQUAL(0, component_ptr->output);

    free(component_ptr);
}

void test_or(void) {
    or_component_ptr component_ptr = (or_component_ptr) malloc(sizeof(struct or_component));
    component_ptr->output = 0;

    component_ptr->input_0 = 1;
    component_ptr->input_1 = 1;
    or_action(component_ptr);
    TEST_ASSERT_EQUAL(1, component_ptr->output);

    component_ptr->input_0 = 1;
    component_ptr->input_1 = 0;
    or_action(component_ptr);
    TEST_ASSERT_EQUAL(1, component_ptr->output);

    component_ptr->input_0 = 0;
    component_ptr->input_1 = 1;
    or_action(component_ptr);
    TEST_ASSERT_EQUAL(1, component_ptr->output);

    component_ptr->input_0 = 0;
    component_ptr->input_1 = 0;
    or_action(component_ptr);
    TEST_ASSERT_EQUAL(0, component_ptr->output);

    free(component_ptr);
}

void test_not(void) {
    not_component_ptr component_ptr = (not_component_ptr) malloc(sizeof(struct not_component));
    component_ptr->output = 0;

    component_ptr->input = 1;
    not_action(component_ptr);
    TEST_ASSERT_EQUAL(0, component_ptr->output & 1);

    component_ptr->input = 0;
    not_action(component_ptr);
    TEST_ASSERT_EQUAL(1, component_ptr->output & 1);

    free(component_ptr);
}

void test_xor(void) {
    xor_component_ptr component_ptr = (xor_component_ptr) malloc(sizeof(struct xor_component));
    component_ptr->output = 0;

    component_ptr->input_0 = 1;
    component_ptr->input_1 = 1;
    xor_action(component_ptr);
    TEST_ASSERT_EQUAL(0, component_ptr->output);

    component_ptr->input_0 = 1;
    component_ptr->input_1 = 0;
    xor_action(component_ptr);
    TEST_ASSERT_EQUAL(1, component_ptr->output);

    component_ptr->input_0 = 0;
    component_ptr->input_1 = 1;
    xor_action(component_ptr);
    TEST_ASSERT_EQUAL(1, component_ptr->output);

    component_ptr->input_0 = 0;
    component_ptr->input_1 = 0;
    xor_action(component_ptr);
    TEST_ASSERT_EQUAL(0, component_ptr->output);

    free(component_ptr);
}

void test_adder_subtractor() {
    int a = 5;
    int b = 6;
    int cin = 0;
    int out = 0;
    int carry = 0;
    int sign = 0;
    int zero = 0;
    int overflow = 0;

    adder_subtractor(&a, &b, &cin, &out, &carry, &sign, &zero, &overflow);
    TEST_ASSERT_EQUAL(11, out);
    TEST_ASSERT_EQUAL(0, carry);
    TEST_ASSERT_EQUAL(0, sign);
    TEST_ASSERT_EQUAL(0, zero);
    TEST_ASSERT_EQUAL(0, overflow);

    a = 255;
    adder_subtractor(&a, &b, &cin, &out, &carry, &sign, &zero, &overflow);
    TEST_ASSERT_EQUAL(261, out);
    TEST_ASSERT_EQUAL(1, carry);
    TEST_ASSERT_EQUAL(0, sign);
    TEST_ASSERT_EQUAL(0, zero);
    TEST_ASSERT_EQUAL(0, overflow);

    a = 511;
    adder_subtractor(&a, &b, &cin, &out, &carry, &sign, &zero, &overflow);
    TEST_ASSERT_EQUAL(517, out);
    TEST_ASSERT_EQUAL(0, carry);
    TEST_ASSERT_EQUAL(0, sign);
    TEST_ASSERT_EQUAL(0, zero);
    TEST_ASSERT_EQUAL(1, overflow);

    a = 5;
    cin = 1;
    adder_subtractor(&a, &b, &cin, &out, &carry, &sign, &zero, &overflow);
    TEST_ASSERT_EQUAL(-1, out);
    TEST_ASSERT_EQUAL(0, carry);
    TEST_ASSERT_EQUAL(1, sign);
    TEST_ASSERT_EQUAL(0, zero);
    TEST_ASSERT_EQUAL(0, overflow);

    a = 6;
    adder_subtractor(&a, &b, &cin, &out, &carry, &sign, &zero, &overflow);
    TEST_ASSERT_EQUAL(0, out);
    TEST_ASSERT_EQUAL(0, carry);
    TEST_ASSERT_EQUAL(0, sign);
    TEST_ASSERT_EQUAL(1, zero);
    TEST_ASSERT_EQUAL(0, overflow);

    b = 545;
    adder_subtractor(&a, &b, &cin, &out, &carry, &sign, &zero, &overflow);
    TEST_ASSERT_EQUAL(-539, out);
    TEST_ASSERT_EQUAL(0, carry);
    TEST_ASSERT_EQUAL(1, sign);
    TEST_ASSERT_EQUAL(0, zero);
    TEST_ASSERT_EQUAL(1, overflow);

    a = 7;
    b = 6;
    adder_subtractor(&a, &b, &cin, &out, &carry, &sign, &zero, &overflow);
    TEST_ASSERT_EQUAL(1, out);
    TEST_ASSERT_EQUAL(0, carry);
    TEST_ASSERT_EQUAL(0, sign);
    TEST_ASSERT_EQUAL(0, zero);
    TEST_ASSERT_EQUAL(0, overflow);
}

void test_mux_2_to_1(void) {
    mux_2_to_1_component_ptr component_ptr = (mux_2_to_1_component_ptr) malloc(sizeof(struct mux_2_to_1_component));
    component_ptr->output = 0;

    component_ptr->select_0 = 0;

    component_ptr->input_0 = 0;
    component_ptr->input_1 = 0;
    mux_2_to_1_action(component_ptr);
    TEST_ASSERT_EQUAL(0, component_ptr->output);

    component_ptr->input_0 = 0;
    component_ptr->input_1 = 1;
    mux_2_to_1_action(component_ptr);
    TEST_ASSERT_EQUAL(0, component_ptr->output);

    component_ptr->input_0 = 1;
    component_ptr->input_1 = 0;
    mux_2_to_1_action(component_ptr);
    TEST_ASSERT_EQUAL(1, component_ptr->output);

    component_ptr->input_0 = 1;
    component_ptr->input_1 = 1;
    mux_2_to_1_action(component_ptr);
    TEST_ASSERT_EQUAL(1, component_ptr->output);

    component_ptr->select_0 = 1;

    component_ptr->input_0 = 0;
    component_ptr->input_1 = 0;
    mux_2_to_1_action(component_ptr);
    TEST_ASSERT_EQUAL(0, component_ptr->output);

    component_ptr->input_0 = 0;
    component_ptr->input_1 = 1;
    mux_2_to_1_action(component_ptr);
    TEST_ASSERT_EQUAL(1, component_ptr->output);

    component_ptr->input_0 = 1;
    component_ptr->input_1 = 0;
    mux_2_to_1_action(component_ptr);
    TEST_ASSERT_EQUAL(0, component_ptr->output);

    component_ptr->input_0 = 1;
    component_ptr->input_1 = 1;
    mux_2_to_1_action(component_ptr);
    TEST_ASSERT_EQUAL(1, component_ptr->output);

    free(component_ptr);
}

void test_mux_4_to_1(void) {
    mux_4_to_1_component_ptr component_ptr = (mux_4_to_1_component_ptr) malloc(sizeof(struct mux_4_to_1_component));
    component_ptr->output = 0;

    component_ptr->select_0 = 0;
    component_ptr->select_1 = 0;

    component_ptr->input_0 = 0;
    component_ptr->input_1 = 1;
    component_ptr->input_2 = 1;
    component_ptr->input_3 = 1;
    mux_4_to_1_action(component_ptr);
    TEST_ASSERT_EQUAL(0, component_ptr->output);

    component_ptr->input_0 = 1;
    component_ptr->input_1 = 0;
    component_ptr->input_2 = 0;
    component_ptr->input_3 = 0;
    mux_4_to_1_action(component_ptr);
    TEST_ASSERT_EQUAL(1, component_ptr->output);

    component_ptr->select_0 = 1;

    component_ptr->input_0 = 1;
    component_ptr->input_1 = 0;
    component_ptr->input_2 = 1;
    component_ptr->input_3 = 1;
    mux_4_to_1_action(component_ptr);
    TEST_ASSERT_EQUAL(0, component_ptr->output);

    component_ptr->input_0 = 0;
    component_ptr->input_1 = 1;
    component_ptr->input_2 = 0;
    component_ptr->input_3 = 0;
    mux_4_to_1_action(component_ptr);
    TEST_ASSERT_EQUAL(1, component_ptr->output);

    component_ptr->select_0 = 0;
    component_ptr->select_1 = 1;

    component_ptr->input_0 = 1;
    component_ptr->input_1 = 1;
    component_ptr->input_2 = 0;
    component_ptr->input_3 = 1;
    mux_4_to_1_action(component_ptr);
    TEST_ASSERT_EQUAL(0, component_ptr->output);

    component_ptr->input_0 = 0;
    component_ptr->input_1 = 0;
    component_ptr->input_2 = 1;
    component_ptr->input_3 = 0;
    mux_4_to_1_action(component_ptr);
    TEST_ASSERT_EQUAL(1, component_ptr->output);

    component_ptr->select_0 = 1;

    component_ptr->input_0 = 1;
    component_ptr->input_1 = 1;
    component_ptr->input_2 = 1;
    component_ptr->input_3 = 0;
    mux_4_to_1_action(component_ptr);
    TEST_ASSERT_EQUAL(0, component_ptr->output);

    component_ptr->input_0 = 0;
    component_ptr->input_1 = 0;
    component_ptr->input_2 = 0;
    component_ptr->input_3 = 1;
    mux_4_to_1_action(component_ptr);
    TEST_ASSERT_EQUAL(1, component_ptr->output);

    free(component_ptr);
}

void test_mux_8_to_1(void) {
    mux_8_to_1_component_ptr component_ptr = (mux_8_to_1_component_ptr) malloc(sizeof(struct mux_8_to_1_component));
    component_ptr->output = 0;

    component_ptr->select_0 = 0;
    component_ptr->select_1 = 0;
    component_ptr->select_2 = 0;

    component_ptr->input_0 = 0;
    component_ptr->input_1 = 1;
    component_ptr->input_2 = 1;
    component_ptr->input_3 = 1;
    component_ptr->input_4 = 1;
    component_ptr->input_5 = 1;
    component_ptr->input_6 = 1;
    component_ptr->input_7 = 1;
    mux_8_to_1_action(component_ptr);
    TEST_ASSERT_EQUAL(0, component_ptr->output);

    component_ptr->input_0 = 1;
    component_ptr->input_1 = 0;
    component_ptr->input_2 = 0;
    component_ptr->input_3 = 0;
    component_ptr->input_4 = 0;
    component_ptr->input_5 = 0;
    component_ptr->input_6 = 0;
    component_ptr->input_7 = 0;
    mux_8_to_1_action(component_ptr);
    TEST_ASSERT_EQUAL(1, component_ptr->output);

    component_ptr->select_0 = 1;

    component_ptr->input_0 = 1;
    component_ptr->input_1 = 0;
    component_ptr->input_2 = 1;
    component_ptr->input_3 = 1;
    component_ptr->input_4 = 1;
    component_ptr->input_5 = 1;
    component_ptr->input_6 = 1;
    component_ptr->input_7 = 1;
    mux_8_to_1_action(component_ptr);
    TEST_ASSERT_EQUAL(0, component_ptr->output);

    component_ptr->input_0 = 0;
    component_ptr->input_1 = 1;
    component_ptr->input_2 = 0;
    component_ptr->input_3 = 0;
    component_ptr->input_4 = 0;
    component_ptr->input_5 = 0;
    component_ptr->input_6 = 0;
    component_ptr->input_7 = 0;
    mux_8_to_1_action(component_ptr);
    TEST_ASSERT_EQUAL(1, component_ptr->output);

    component_ptr->select_1 = 1;
    component_ptr->select_0 = 0;

    component_ptr->input_0 = 1;
    component_ptr->input_1 = 1;
    component_ptr->input_2 = 0;
    component_ptr->input_3 = 1;
    component_ptr->input_4 = 1;
    component_ptr->input_5 = 1;
    component_ptr->input_6 = 1;
    component_ptr->input_7 = 1;
    mux_8_to_1_action(component_ptr);
    TEST_ASSERT_EQUAL(0, component_ptr->output);

    component_ptr->input_0 = 0;
    component_ptr->input_1 = 0;
    component_ptr->input_2 = 1;
    component_ptr->input_3 = 0;
    component_ptr->input_4 = 0;
    component_ptr->input_5 = 0;
    component_ptr->input_6 = 0;
    component_ptr->input_7 = 0;
    mux_8_to_1_action(component_ptr);
    TEST_ASSERT_EQUAL(1, component_ptr->output);

    component_ptr->select_0 = 1;

    component_ptr->input_0 = 1;
    component_ptr->input_1 = 1;
    component_ptr->input_2 = 1;
    component_ptr->input_3 = 0;
    component_ptr->input_4 = 1;
    component_ptr->input_5 = 1;
    component_ptr->input_6 = 1;
    component_ptr->input_7 = 1;
    mux_8_to_1_action(component_ptr);
    TEST_ASSERT_EQUAL(0, component_ptr->output);

    component_ptr->input_0 = 0;
    component_ptr->input_1 = 0;
    component_ptr->input_2 = 0;
    component_ptr->input_3 = 1;
    component_ptr->input_4 = 0;
    component_ptr->input_5 = 0;
    component_ptr->input_6 = 0;
    component_ptr->input_7 = 0;
    mux_8_to_1_action(component_ptr);
    TEST_ASSERT_EQUAL(1, component_ptr->output);

    component_ptr->select_0 = 0;
    component_ptr->select_1 = 0;
    component_ptr->select_2 = 1;

    component_ptr->input_0 = 1;
    component_ptr->input_1 = 1;
    component_ptr->input_2 = 1;
    component_ptr->input_3 = 1;
    component_ptr->input_4 = 0;
    component_ptr->input_5 = 1;
    component_ptr->input_6 = 1;
    component_ptr->input_7 = 1;
    mux_8_to_1_action(component_ptr);
    TEST_ASSERT_EQUAL(0, component_ptr->output);

    component_ptr->input_0 = 0;
    component_ptr->input_1 = 0;
    component_ptr->input_2 = 0;
    component_ptr->input_3 = 0;
    component_ptr->input_4 = 1;
    component_ptr->input_5 = 0;
    component_ptr->input_6 = 0;
    component_ptr->input_7 = 0;
    mux_8_to_1_action(component_ptr);
    TEST_ASSERT_EQUAL(1, component_ptr->output);

    component_ptr->select_0 = 1;

    component_ptr->input_0 = 1;
    component_ptr->input_1 = 1;
    component_ptr->input_2 = 1;
    component_ptr->input_3 = 1;
    component_ptr->input_4 = 1;
    component_ptr->input_5 = 0;
    component_ptr->input_6 = 1;
    component_ptr->input_7 = 1;
    mux_8_to_1_action(component_ptr);
    TEST_ASSERT_EQUAL(0, component_ptr->output);

    component_ptr->input_0 = 0;
    component_ptr->input_1 = 0;
    component_ptr->input_2 = 0;
    component_ptr->input_3 = 0;
    component_ptr->input_4 = 0;
    component_ptr->input_5 = 1;
    component_ptr->input_6 = 0;
    component_ptr->input_7 = 0;
    mux_8_to_1_action(component_ptr);
    TEST_ASSERT_EQUAL(1, component_ptr->output);

    component_ptr->select_1 = 1;
    component_ptr->select_0 = 0;

    component_ptr->input_0 = 1;
    component_ptr->input_1 = 1;
    component_ptr->input_2 = 0;
    component_ptr->input_3 = 1;
    component_ptr->input_4 = 1;
    component_ptr->input_5 = 1;
    component_ptr->input_6 = 0;
    component_ptr->input_7 = 1;
    mux_8_to_1_action(component_ptr);
    TEST_ASSERT_EQUAL(0, component_ptr->output);

    component_ptr->input_0 = 0;
    component_ptr->input_1 = 0;
    component_ptr->input_2 = 0;
    component_ptr->input_3 = 0;
    component_ptr->input_4 = 0;
    component_ptr->input_5 = 0;
    component_ptr->input_6 = 1;
    component_ptr->input_7 = 0;
    mux_8_to_1_action(component_ptr);
    TEST_ASSERT_EQUAL(1, component_ptr->output);

    component_ptr->select_0 = 1;

    component_ptr->input_0 = 1;
    component_ptr->input_1 = 1;
    component_ptr->input_2 = 1;
    component_ptr->input_3 = 1;
    component_ptr->input_4 = 1;
    component_ptr->input_5 = 1;
    component_ptr->input_6 = 1;
    component_ptr->input_7 = 0;
    mux_8_to_1_action(component_ptr);
    TEST_ASSERT_EQUAL(0, component_ptr->output);

    component_ptr->input_0 = 0;
    component_ptr->input_1 = 0;
    component_ptr->input_2 = 0;
    component_ptr->input_3 = 0;
    component_ptr->input_4 = 0;
    component_ptr->input_5 = 0;
    component_ptr->input_6 = 0;
    component_ptr->input_7 = 1;
    mux_8_to_1_action(component_ptr);
    TEST_ASSERT_EQUAL(1, component_ptr->output);

    free(component_ptr);
}

void test_demux_2_to_4(void) {
    demux_2_to_4_component_ptr component_ptr = (demux_2_to_4_component_ptr) malloc(sizeof(struct demux_2_to_4_component));
    component_ptr->output_0 = 0;
    component_ptr->output_1 = 0;
    component_ptr->output_2 = 0;
    component_ptr->output_3 = 0;

    component_ptr->input = 1;

    component_ptr->select_0 = 0;
    component_ptr->select_1 = 0;
    demux_2_to_4_action(component_ptr);
    TEST_ASSERT_EQUAL(1, component_ptr->output_0);
    TEST_ASSERT_EQUAL(0, component_ptr->output_1);
    TEST_ASSERT_EQUAL(0, component_ptr->output_2);
    TEST_ASSERT_EQUAL(0, component_ptr->output_3);
    component_ptr->output_0 = 0;

    component_ptr->select_0 = 1;
    component_ptr->select_1 = 0;
    demux_2_to_4_action(component_ptr);
    TEST_ASSERT_EQUAL(0, component_ptr->output_0);
    TEST_ASSERT_EQUAL(1, component_ptr->output_1);
    TEST_ASSERT_EQUAL(0, component_ptr->output_2);
    TEST_ASSERT_EQUAL(0, component_ptr->output_3);
    component_ptr->output_1 = 0;

    component_ptr->select_0 = 0;
    component_ptr->select_1 = 1;
    demux_2_to_4_action(component_ptr);
    TEST_ASSERT_EQUAL(0, component_ptr->output_0);
    TEST_ASSERT_EQUAL(0, component_ptr->output_1);
    TEST_ASSERT_EQUAL(1, component_ptr->output_2);
    TEST_ASSERT_EQUAL(0, component_ptr->output_3);
    component_ptr->output_2 = 0;

    component_ptr->select_0 = 1;
    component_ptr->select_1 = 1;
    demux_2_to_4_action(component_ptr);
    TEST_ASSERT_EQUAL(0, component_ptr->output_0);
    TEST_ASSERT_EQUAL(0, component_ptr->output_1);
    TEST_ASSERT_EQUAL(0, component_ptr->output_2);
    TEST_ASSERT_EQUAL(1, component_ptr->output_3);
    component_ptr->output_3 = 0;

    free(component_ptr);


//    int input = 0;
//    int A = -1;
//    int B = -1;
//    int C = -1;
//    int D = -1;
//
//    demux_2_to_4(input, 0, 0, &A, &B, &C, &D);
//    TEST_ASSERT_EQUAL(input, A);
//    demux_2_to_4(input, 0, 1, &A, &B, &C, &D);
//    TEST_ASSERT_EQUAL(input, B);
//    demux_2_to_4(input, 1, 0, &A, &B, &C, &D);
//    TEST_ASSERT_EQUAL(input, C);
//    demux_2_to_4(input, 1, 1, &A, &B, &C, &D);
//    TEST_ASSERT_EQUAL(input, D);
//
//    input = 1;
//    demux_2_to_4(input, 0, 0, &A, &B, &C, &D);
//    TEST_ASSERT_EQUAL(input, A);
//    demux_2_to_4(input, 0, 1, &A, &B, &C, &D);
//    TEST_ASSERT_EQUAL(input, B);
//    demux_2_to_4(input, 1, 0, &A, &B, &C, &D);
//    TEST_ASSERT_EQUAL(input, C);
//    demux_2_to_4(input, 1, 1, &A, &B, &C, &D);
//    TEST_ASSERT_EQUAL(input, D);
}

void test_register_component(void) {
    register_component_ptr component_ptr = (register_component_ptr) malloc(sizeof(struct register_component));

    component_ptr->input = 0;
    component_ptr->clock = 0;
    component_ptr->select = 0;
    component_ptr->output = 0;

    register_component_action(component_ptr);
    TEST_ASSERT_EQUAL(0, component_ptr->output);

    component_ptr->input = 1;
    component_ptr->clock = 0;
    component_ptr->select = 0;
    register_component_action(component_ptr);
    TEST_ASSERT_EQUAL(0, component_ptr->output);

    component_ptr->input = 1;
    component_ptr->clock = 1;
    component_ptr->select = 0;
    register_component_action(component_ptr);
    TEST_ASSERT_EQUAL(0, component_ptr->output);

    component_ptr->input = 1;
    component_ptr->clock = 1;
    component_ptr->select = 1;
    register_component_action(component_ptr);
    TEST_ASSERT_EQUAL(1, component_ptr->output);

    free(component_ptr);

//    int input = 0;
//    int clock = 0;
//    int cs = 0;
//    int output = 0;
//
//    register_component(&input, &cs, &clock, &output);
//    TEST_ASSERT_EQUAL(output, 0);
//
//    input = 1;
//    register_component(&input, &cs, &clock, &output);
//    TEST_ASSERT_EQUAL(output, 0);
//
//    cs = 1;
//    register_component(&input, &cs, &clock, &output);
//    TEST_ASSERT_EQUAL(output, 0);
//
//    clock = 1;
//    register_component(&input, &cs, &clock, &output);
//    TEST_ASSERT_EQUAL(output, 1);
//
//    input = 0;
//    register_component(&input, &cs, &clock, &output);
//    TEST_ASSERT_EQUAL(output, 0);
}

void test_logging(void) {
    char *message = "test123";
    char compare[BUFFER_SIZE];
    char timestr[64];
    char *log_message;
    time_t now;
    time(&now);
    strftime(timestr, 64, "%c", localtime(&now));

    sprintf(compare, "%s [%s]: %s", timestr, "DEBUG", message);
    log_message = generate_log_message(DEBUG_LOG_LEVEL, message, now);
    TEST_ASSERT(strcmp(compare, log_message) == 0);
    free(log_message);

    sprintf(compare, "%s [%s]: %s", timestr, "INFO", message);
    log_message = generate_log_message(INFO_LOG_LEVEL, message, now);
    TEST_ASSERT(strcmp(compare, log_message) == 0);
    free(log_message);

    sprintf(compare, "%s [%s]: %s", timestr, "WARN", message);
    log_message = generate_log_message(WARN_LOG_LEVEL, message, now);
    TEST_ASSERT(strcmp(compare, log_message) == 0);
    free(log_message);

    sprintf(compare, "%s [%s]: %s", timestr, "ERROR", message);
    log_message = generate_log_message(ERROR_LOG_LEVEL, message, now);
    TEST_ASSERT(strcmp(compare, log_message) == 0);
    free(log_message);

    sprintf(compare, "%s [%s]: %s", timestr, "FATAL", message);
    log_message = generate_log_message(FATAL_LOG_LEVEL, message, now);
    TEST_ASSERT(strcmp(compare, log_message) == 0);
    free(log_message);
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_and);
    RUN_TEST(test_or);
    RUN_TEST(test_not);
    RUN_TEST(test_xor);

    RUN_TEST(test_adder_subtractor);

    RUN_TEST(test_mux_2_to_1);
    RUN_TEST(test_mux_4_to_1);
    RUN_TEST(test_mux_8_to_1);

    RUN_TEST(test_demux_2_to_4);

    RUN_TEST(test_register_component);

    RUN_TEST(test_logging);

    return UNITY_END();
}
