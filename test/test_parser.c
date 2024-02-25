#include "unity/unity.h"
#include <string.h>
#include <stdlib.h>

#include "parser.h"


#define MAX_ARGS 10
#define MAX_ARG_LENGTH 50

char *buffer;
char *args[MAX_ARGS];
size_t nargs;

void setUp(void)
{
	buffer = malloc(MAX_ARG_LENGTH);
	for (int i = 0; i < MAX_ARGS; ++i) {
		args[i] = NULL;
	}
	nargs = 0;
}

void tearDown(void)
{
	free(buffer);
}


void test_parse_args(void)
{
	strcpy(buffer, "cmd -arg1 -arg2 -arg3");

	// ACT
	parse_args(buffer, args, MAX_ARGS, &nargs);

	// ASSERT
	TEST_ASSERT_EQUAL_STRING("cmd", args[0]);
	TEST_ASSERT_EQUAL_STRING("-arg1", args[1]);
	TEST_ASSERT_EQUAL_STRING("-arg2", args[2]);
	TEST_ASSERT_EQUAL_STRING("-arg3", args[3]);
	TEST_ASSERT_EQUAL(4, nargs);

}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_parse_args);
	return UNITY_END();
}

