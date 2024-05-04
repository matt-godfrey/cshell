#include "unity/unity.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

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

// void test_find_binary(void) {

// }

void test_ch_dir(void) {
	char cwd[100];
	char new_cwd[100];
	char target[] = "/home/matt/Code";

	// ACT
	getcwd(cwd, sizeof(cwd));
	ch_dir("..");
	getcwd(new_cwd, sizeof(new_cwd));

	// ASSERT
	TEST_ASSERT_EQUAL_STRING(target, new_cwd);
}

void test_ch_dir_homedir(void) {
	char *cwd;
	char *new_cwd;
	char home_dir[] = "/home/matt";

	cwd = getcwd(NULL, 0);
	if (cwd == NULL) {
		perror("cwd failed");
		return 1;
	}

	// ACT
	ch_dir("~");

	new_cwd = getcwd(NULL, 0);
	if (new_cwd == NULL) {
		perror("cwd failed");
		return 1;
	}

	// ASSERT
	TEST_ASSERT_EQUAL_STRING(home_dir, new_cwd);

}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_parse_args);
	RUN_TEST(test_ch_dir);
	RUN_TEST(test_ch_dir_homedir);
	return UNITY_END();
}

