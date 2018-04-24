#include <time.h>
#include <stdlib.h>
#include <memory.h>
#include "unity.h"
#include "components.h"
#include "emulator.h"
#include "multiplexer.h"
#include "logger.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_and(void)
{
	TEST_ASSERT_EQUAL(1, and(1,1));
	TEST_ASSERT_EQUAL(0, and(0,0));
	TEST_ASSERT_EQUAL(0, and(1,0));
	TEST_ASSERT_EQUAL(0, and(0,1));
}

void test_or(void)
{
	TEST_ASSERT_EQUAL(1, or(1,1));
	TEST_ASSERT_EQUAL(0, or(0,0));
	TEST_ASSERT_EQUAL(1, or(1,0));
	TEST_ASSERT_EQUAL(1, or(0,1));
}

void test_not(void)
{
	TEST_ASSERT_EQUAL(0, not(1));
	TEST_ASSERT_EQUAL(1, not(0));
}

void test_xor(void)
{
	TEST_ASSERT_EQUAL(0, xor(1,1));
	TEST_ASSERT_EQUAL(0, xor(0,0));
	TEST_ASSERT_EQUAL(1, xor(1,0));
	TEST_ASSERT_EQUAL(1, xor(0,1));
}

void test_mux_2to1(void){
    int s0 = 0;
    TEST_ASSERT_EQUAL(0, mux_2to1(0, 0, s0));
    TEST_ASSERT_EQUAL(0, mux_2to1(0, 1, s0));
    TEST_ASSERT_EQUAL(1, mux_2to1(1, 0, s0));
    TEST_ASSERT_EQUAL(1, mux_2to1(1, 1, s0));
    s0 = 1;
    TEST_ASSERT_EQUAL(0, mux_2to1(0, 0, s0));
    TEST_ASSERT_EQUAL(1, mux_2to1(0, 1, s0));
    TEST_ASSERT_EQUAL(0, mux_2to1(1, 0, s0));
    TEST_ASSERT_EQUAL(1, mux_2to1(1, 1, s0));

}

void test_mux_4to1(void){
    int s0 = 0;
    int s1 = 0;
    TEST_ASSERT_EQUAL(0, mux_4to1(0, 0, 0, 0, s1, s0));
    TEST_ASSERT_EQUAL(1, mux_4to1(1, 0, 0, 0, s1, s0));
    s0 = 1;
    TEST_ASSERT_EQUAL(0, mux_4to1(0, 0, 0, 0, s1, s0));
    TEST_ASSERT_EQUAL(1, mux_4to1(0, 1, 0, 0, s1, s0)); //failed
    s0 = 0;
    s1 = 1;
    TEST_ASSERT_EQUAL(0, mux_4to1(0, 0, 0, 0, s1, s0));
    TEST_ASSERT_EQUAL(1, mux_4to1(0, 0, 1, 0, s1, s0));
    s0 = 1;
    TEST_ASSERT_EQUAL(0, mux_4to1(0, 0, 0, 0, s1, s0));
    TEST_ASSERT_EQUAL(1, mux_4to1(0, 0, 0, 1, s1, s0));

}

void test_mux_8to1(void){
    int s0 = 0;
    int s1 = 0;
    int s2 = 0;
    TEST_ASSERT_EQUAL(0, mux_8to1(0, 1, 1, 1, 1, 1, 1, 1, s2, s1, s0));
    TEST_ASSERT_EQUAL(1, mux_8to1(1, 0, 0, 0, 0, 0, 0, 0, s2, s1, s0));
    s0 = 1;
    TEST_ASSERT_EQUAL(0, mux_8to1(1, 0, 1, 1, 1, 1, 1, 1, s2, s1, s0));
    TEST_ASSERT_EQUAL(1, mux_8to1(0, 1, 0, 0, 0, 0, 0, 0, s2, s1, s0));
    s1 = 1;
    s0 = 0;
    TEST_ASSERT_EQUAL(0, mux_8to1(1, 1, 0, 1, 1, 1, 1, 1, s2, s1, s0));
    TEST_ASSERT_EQUAL(1, mux_8to1(0, 0, 1, 0, 0, 0, 0, 0, s2, s1, s0));
    s0 = 1;
    TEST_ASSERT_EQUAL(0, mux_8to1(1, 1, 1, 0, 1, 1, 1, 1, s2, s1, s0));
    TEST_ASSERT_EQUAL(1, mux_8to1(0, 0, 0, 1, 0, 0, 0, 0, s2, s1, s0));
    s2 = 1;
    s1 = 0;
    s0 = 0;
    TEST_ASSERT_EQUAL(0, mux_8to1(1, 1, 1, 1, 0, 1, 1, 1, s2, s1, s0));
    TEST_ASSERT_EQUAL(1, mux_8to1(0, 0, 0, 0, 1, 0, 0, 0, s2, s1, s0));
    s0 = 1;
    TEST_ASSERT_EQUAL(0, mux_8to1(1, 1, 1, 1, 1, 0, 1, 1, s2, s1, s0));
    TEST_ASSERT_EQUAL(1, mux_8to1(0, 0, 0, 0, 0, 1, 0, 0, s2, s1, s0));
    s1 = 1;
    s0 = 0;
    TEST_ASSERT_EQUAL(0, mux_8to1(1, 1, 1, 1, 1, 1, 0, 1, s2, s1, s0));
    TEST_ASSERT_EQUAL(1, mux_8to1(0, 0, 0, 0, 0, 0, 1, 0, s2, s1, s0));
    s0 = 1;
    TEST_ASSERT_EQUAL(0, mux_8to1(1, 1, 1, 1, 1, 1, 1, 0, s2, s1, s0));
    TEST_ASSERT_EQUAL(1, mux_8to1(0, 0, 0, 0, 0, 0, 0, 1, s2, s1, s0));
}

void test_logging(void)
{
    char *message = "test123";
    char compare[1024];
    char *log_message;
    time_t now;
    time(&now);

    sprintf(compare, "%s [%s]: %s", ctime(&now), "DEBUG", message);
    log_message = generate_log_message(DEBUG_LOG_LEVEL, message, now, 1024);
    TEST_ASSERT(strcmp(compare, log_message) == 0);
    free(log_message);

    sprintf(compare, "%s [%s]: %s", ctime(&now), "INFO", message);
    log_message = generate_log_message(INFO_LOG_LEVEL, message, now, 1024);
    TEST_ASSERT(strcmp(compare, log_message) == 0);
    free(log_message);

    sprintf(compare, "%s [%s]: %s", ctime(&now), "WARN", message);
    log_message = generate_log_message(WARN_LOG_LEVEL, message, now, 1024);
    TEST_ASSERT(strcmp(compare, log_message) == 0);
    free(log_message);

    sprintf(compare, "%s [%s]: %s", ctime(&now), "ERROR", message);
    log_message = generate_log_message(ERROR_LOG_LEVEL, message, now, 1024);
    TEST_ASSERT(strcmp(compare, log_message) == 0);
    free(log_message);

    sprintf(compare, "%s [%s]: %s", ctime(&now), "FATAL", message);
    log_message = generate_log_message(FATAL_LOG_LEVEL, message, now, 1024);
    TEST_ASSERT(strcmp(compare, log_message) == 0);
    free(log_message);
}

void test_demux_2to4(void){
    int input = 0;
    int A = -1;
    int B = -1;
    int C = -1;
    int D = -1;

    demux_2to4(input, 0, 0, &A, &B, &C, &D);
    TEST_ASSERT_EQUAL(input, A);
    demux_2to4(input, 0, 1, &A, &B, &C, &D);
    TEST_ASSERT_EQUAL(input, B);
    demux_2to4(input, 1, 0, &A, &B, &C, &D);
    TEST_ASSERT_EQUAL(input, C);
    demux_2to4(input, 1, 1, &A, &B, &C, &D);
    TEST_ASSERT_EQUAL(input, D);

    input = 1;
    demux_2to4(input, 0, 0, &A, &B, &C, &D);
    TEST_ASSERT_EQUAL(input, A);
    demux_2to4(input, 0, 1, &A, &B, &C, &D);
    TEST_ASSERT_EQUAL(input, B);
    demux_2to4(input, 1, 0, &A, &B, &C, &D);
    TEST_ASSERT_EQUAL(input, C);
    demux_2to4(input, 1, 1, &A, &B, &C, &D);
    TEST_ASSERT_EQUAL(input, D);

}
int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_and);
    RUN_TEST(test_or);
    RUN_TEST(test_not);
    RUN_TEST(test_xor);

    RUN_TEST(test_logging);

    RUN_TEST(test_mux_4to1);
    RUN_TEST(test_mux_8to1);
	
	RUN_TEST(test_demux_2to4);

    return UNITY_END();
}
