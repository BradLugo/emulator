#include "unity.h"
#include "emulator.h"

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

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_half_adder);
    RUN_TEST(test_full_adder);
    return UNITY_END();
}