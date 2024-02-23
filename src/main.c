#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "defs.h"
#include "parser.h"


void prompt(char *username, char *path, char *envp[])
{
	char buffer[BUFFER_SIZE];
	char *args[MAX_ARR];
	char *s;
	size_t nargs;

	while (1) {
		printf("%s $ ", username);

		s = fgets(buffer, BUFFER_SIZE, stdin);

		if (s == NULL) {
			printf("EOF reached\n");
			exit(0);
		}

		// parse args here
		parse_args(buffer, args, MAX_ARR, &nargs);

		if (nargs ==0) continue;

		// check for internal commands
		if (strcmp(args[0], "exit") == 0) {
			exit(0);
		}
	}
}

int main(int argc, char *argv[], char *envp[])
{

	char *username;

	char *path;

	username = getenv("USER");
	path = getenv("PATH");

	printf("username: %s\n", username);
	//printf("path: %s\n", path);

	/*
	char **p = envp;
	while (*p != NULL) {
		printf("envp: %s\n", *p);
		p++;
	}
	*/


	prompt(username, path, envp);

	return 0;
}
