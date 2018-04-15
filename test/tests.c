#include "unity.h"
#include "components.h"

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

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_and);
    RUN_TEST(test_or);
    RUN_TEST(test_not);
    RUN_TEST(test_xor);
    return UNITY_END();
}
