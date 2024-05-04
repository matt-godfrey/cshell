#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "parser.h"

void parse_args(char *buffer, char **args, size_t args_size, size_t *nargs) 
{
	
	int i = 0;
	char *tok = strtok(buffer, " \t");

	while (tok != NULL) {
		if (strlen(tok) > 0) {
			args[i] = tok;
			if (i >= args_size - 1) {
				break;
			}
		}
		// printf("arg [%d]:%s\n", i, args[i]);
		i++;
		tok = strtok(NULL, " \t");
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
    char *result = NULL;
    char *home_dir;
    size_t path_size;

    home_dir = getenv("HOME");
    if (home_dir == NULL) {
        printf("error: HOME environment variable not set\n");
        return;
    }

    if (target[0] == '~') {
        path_size = strlen(home_dir) + strlen(target);
        result = malloc(path_size);
        if (result == NULL) {
            perror("malloc");
            return;
        }
        strcpy(result, home_dir);
        strcat(result, target + 1);
    } else {
        path_size = strlen(target) + 1;
        result = malloc(path_size);
        if (result == NULL) {
            perror("malloc");
            return;
        }
        strcpy(result, target);
    }

    if (chdir(result) < 0) {
        printf("error (cd): %s\n", strerror(errno));
    } 
	// else {
    //     printf("Changed directory to %s\n", result);
    // }

    free(result);
}
