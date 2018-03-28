#include <ntsid.h>
#include <time.h>
#include <memory.h>
#include <stdlib.h>
#include "unity.h"
#include "emulator.h"
#include "logger.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_half_adder(void)
{
    int c = 0;
    TEST_ASSERT_EQUAL(0, half_adder(0, 0, &c));
    TEST_ASSERT_EQUAL(0, c);

    c = 0;
    TEST_ASSERT_EQUAL(1, half_adder(0, 1, &c));
    TEST_ASSERT_EQUAL(0, c);

    c = 0;
    TEST_ASSERT_EQUAL(1, half_adder(1, 0, &c));
    TEST_ASSERT_EQUAL(0, c);

    c = 0;
    TEST_ASSERT_EQUAL(0, half_adder(1, 1, &c));
    TEST_ASSERT_EQUAL(1, c);
}

void test_full_adder(void)
{
    int c = 0;
    TEST_ASSERT_EQUAL(0, full_adder(0, 0, 0, &c));
    TEST_ASSERT_EQUAL(0, c);

    c = 0;
    TEST_ASSERT_EQUAL(1, full_adder(0, 1, 0, &c));
    TEST_ASSERT_EQUAL(0, c);

    c = 0;
    TEST_ASSERT_EQUAL(1, full_adder(1, 0, 0, &c));
    TEST_ASSERT_EQUAL(0, c);

    c = 0;
    TEST_ASSERT_EQUAL(0, full_adder(1, 1, 0, &c));
    TEST_ASSERT_EQUAL(1, c);

    c = 0;
    TEST_ASSERT_EQUAL(1, full_adder(0, 0, 1, &c));
    TEST_ASSERT_EQUAL(0, c);

    c = 0;
    TEST_ASSERT_EQUAL(0, full_adder(0, 1, 1, &c));
    TEST_ASSERT_EQUAL(1, c);

    c = 0;
    TEST_ASSERT_EQUAL(0, full_adder(1, 0, 1, &c));
    TEST_ASSERT_EQUAL(1, c);

    c = 0;
    TEST_ASSERT_EQUAL(1, full_adder(1, 1, 1, &c));
    TEST_ASSERT_EQUAL(1, c);
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


int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_half_adder);
    RUN_TEST(test_full_adder);
    RUN_TEST(test_logging);
    return UNITY_END();
}