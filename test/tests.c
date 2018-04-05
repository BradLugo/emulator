#include "unity.h"
#include "emulator.h"
#include "multiplexer.h"

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
    TEST_ASSERT_EQUAL(0, mux_4to1(0, 0, 0, 0, s0, s1));
    TEST_ASSERT_EQUAL(1, mux_4to1(1, 0, 0, 0, s0, s1));
    s0 = 1;
    TEST_ASSERT_EQUAL(0, mux_4to1(0, 0, 0, 0, s0, s1));
    TEST_ASSERT_EQUAL(1, mux_4to1(0, 1, 0, 0, s0, s1)); //failed
    s0 = 0;
    s1 = 1;
    TEST_ASSERT_EQUAL(0, mux_4to1(0, 0, 0, 0, s0, s1));
    TEST_ASSERT_EQUAL(1, mux_4to1(0, 0, 1, 0, s0, s1));
    s0 = 1;
    TEST_ASSERT_EQUAL(0, mux_4to1(0, 0, 0, 0, s0, s1));
    TEST_ASSERT_EQUAL(1, mux_4to1(0, 0, 0, 1, s0, s1));

}

void test_mux_8to1(void){
    int s0 = 0;
    int s1 = 0;
    int s2 = 0;
    TEST_ASSERT_EQUAL(0, mux_8to1(0, 1, 1, 1, 1, 1, 1, 1, s0, s1, s2));
    TEST_ASSERT_EQUAL(1, mux_8to1(1, 0, 0, 0, 0, 0, 0, 0, s0, s1, s2));
    s2 = 1;
    TEST_ASSERT_EQUAL(0, mux_8to1(1, 0, 1, 1, 1, 1, 1, 1, s0, s1, s2));
    TEST_ASSERT_EQUAL(1, mux_8to1(0, 1, 0, 0, 0, 0, 0, 0, s0, s1, s2));
    s1 = 1;
    s2 = 0;
    TEST_ASSERT_EQUAL(0, mux_8to1(1, 1, 0, 1, 1, 1, 1, 1, s0, s1, s2));
    TEST_ASSERT_EQUAL(1, mux_8to1(0, 0, 1, 0, 0, 0, 0, 0, s0, s1, s2));
    s2 = 1;
    TEST_ASSERT_EQUAL(0, mux_8to1(1, 1, 1, 0, 1, 1, 1, 1, s0, s1, s2));
    TEST_ASSERT_EQUAL(1, mux_8to1(0, 0, 0, 1, 0, 0, 0, 0, s0, s1, s2));
    s0 = 1;
    s1 = 0;
    s2 = 0;
    TEST_ASSERT_EQUAL(0, mux_8to1(1, 1, 1, 1, 0, 1, 1, 1, s0, s1, s2));
    TEST_ASSERT_EQUAL(1, mux_8to1(0, 0, 0, 0, 1, 0, 0, 0, s0, s1, s2));
    s2 = 1;
    TEST_ASSERT_EQUAL(0, mux_8to1(1, 1, 1, 1, 1, 0, 1, 1, s0, s1, s2));
    TEST_ASSERT_EQUAL(1, mux_8to1(0, 0, 0, 0, 0, 1, 0, 0, s0, s1, s2));
    s1 = 1;
    s2 = 0;
    TEST_ASSERT_EQUAL(0, mux_8to1(1, 1, 1, 1, 1, 1, 0, 1, s0, s1, s2));
    TEST_ASSERT_EQUAL(1, mux_8to1(0, 0, 0, 0, 0, 0, 1, 0, s0, s1, s2));
    s2 = 1;
    TEST_ASSERT_EQUAL(0, mux_8to1(1, 1, 1, 1, 1, 1, 1, 0, s0, s1, s2));
    TEST_ASSERT_EQUAL(1, mux_8to1(0, 0, 0, 0, 0, 0, 0, 1, s0, s1, s2));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_half_adder);
    RUN_TEST(test_full_adder);
    RUN_TEST(test_mux_2to1);
    RUN_TEST(test_mux_4to1);
    RUN_TEST(test_mux_8to1);
    return UNITY_END();
}