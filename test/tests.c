#include "unity.h"
#include "components.h"
#include "emulator.h"
#include "multiplexer.h"

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

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_and);
    RUN_TEST(test_or);
    RUN_TEST(test_not);
    RUN_TEST(test_xor);
    RUN_TEST(test_half_adder);
    RUN_TEST(test_full_adder);
    RUN_TEST(test_mux_2to1);
    RUN_TEST(test_mux_4to1);
    RUN_TEST(test_mux_8to1);
    return UNITY_END();
}
