#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>

#include "defs.h"
#include "parser.h"


void run_program(char *args[], int background, char *path, char *envp[]) {

	pid_t pid;
	int ret_pid;
	int ret_execvp;

	pid = fork();
	// TODO: handle background process here
	if (pid) {
		pid = wait(&ret_pid);
	}
	else {
		// TODO: figure out if execve is better here
		ret_execvp = execvp(args[0], args);
		if (ret_execvp == -1) {
			printf("error: %s\n", strerror(errno));
			// exit(1);
		}
	}

}


void prompt(char *username, char *path, char *envp[])
{
	char buffer[BUFFER_SIZE];
	char *args[MAX_ARR];
	char *s;
	size_t nargs;
	int background = 0;

	while (1) {
		printf("%s $ ", username);

		s = fgets(buffer, BUFFER_SIZE, stdin);

		if (s == NULL) {
			printf("EOF reached\n");
			exit(0);
		}

		// parse args here
		parse_args(buffer, args, MAX_ARR, &nargs);

		if (nargs == 0) continue;

		// check for internal commands
        if (strcmp(args[0], "exit") == 0) {
			exit(0);        
		}

		if (strcmp(args[0], "cd") == 0) {
			// printf("target: %s\n", args[1]);
			ch_dir(args[1]);
			continue;
		}
		
	
		// find_binary(path);
		run_program(args, background, path, envp);

	}
}

int main(int argc, char *argv[], char *envp[])
{

	char *username;

	char *path;

	username = getenv("USER");
	path = getenv("PATH");

	// printf("username: %s\n", username);
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
