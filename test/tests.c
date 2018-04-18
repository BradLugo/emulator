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

void test_demux_1to4(void){
    int input = 0;
    int A = -1;
    int B = -1;
    int C = -1;
    int D = -1;

    demux_1to4(input, 0, 0, &A, &B, &C, &D);
    TEST_ASSERT_EQUAL(input, A);
    demux_1to4(input, 0, 1, &A, &B, &C, &D);
    TEST_ASSERT_EQUAL(input, B);
    demux_1to4(input, 1, 0, &A, &B, &C, &D);
    TEST_ASSERT_EQUAL(input, C);
    demux_1to4(input, 1, 1, &A, &B, &C, &D);
    TEST_ASSERT_EQUAL(input, D);

    input = 1;
    demux_1to4(input, 0, 0, &A, &B, &C, &D);
    TEST_ASSERT_EQUAL(input, A);
    demux_1to4(input, 0, 1, &A, &B, &C, &D);
    TEST_ASSERT_EQUAL(input, B);
    demux_1to4(input, 1, 0, &A, &B, &C, &D);
    TEST_ASSERT_EQUAL(input, C);
    demux_1to4(input, 1, 1, &A, &B, &C, &D);
    TEST_ASSERT_EQUAL(input, D);

}
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_half_adder);
    RUN_TEST(test_full_adder);
    RUN_TEST(test_demux_1to4);
    return UNITY_END();
}