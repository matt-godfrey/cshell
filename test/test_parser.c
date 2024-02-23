#include "unity/unity.h"


void setUp(void)
{
	
}

void tearDown(void)
{

}


void test_parse_args(void)
{
	TEST_ASSERT_TRUE(1);
}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_parse_args);
	return UNITY_END();
}

