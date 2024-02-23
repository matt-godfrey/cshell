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
		//printf("arg [%d]: %s\n", i, args[i]);
		i++;
		tok = strtok(NULL, " \n\t");
	}

	*nargs = i;
	args[i] = NULL;
}
