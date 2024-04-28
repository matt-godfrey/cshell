#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "parser.h"

void parse_args(char *buffer, char **args, size_t args_size, size_t *nargs) 
{
	
	int i = 0;
	char *tok = strtok(buffer, " \n\t");

	while (tok != NULL) {
		if (strlen(tok) > 0) {
			args[i] = tok;
			if (i >= args_size - 1) {
				break;
			}
		}
		printf("arg [%d]: %s\n", i, args[i]);
		i++;
		tok = strtok(NULL, " \n\t");
	}

	*nargs = i;
	args[i] = NULL;
}


void find_binary(char *path) {
	
	char *token = strtok(path, ":");

	while (token != NULL) {
		// printf("%s\n", token);
		token = strtok(NULL, ":");
	}
}


void ch_dir(char *target) {
	char cwd[100];
	char new_dir[100];

	if (getcwd(cwd, sizeof(cwd)) != NULL) {
		printf("CWD: %s\n", cwd);
	}
	else {
		perror("error: could not find cwd");
	}

	int ret = chdir(target);
	if (ret < 0) {
		printf("error: %s\n", strerror(errno));
		return;
	}

	getcwd(new_dir, sizeof(new_dir));
	printf("New CWD: %s\n", new_dir);

}
