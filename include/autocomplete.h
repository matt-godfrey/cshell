#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include <readline/readline.h>
#include <readline/history.h>

char **file_completion(const char *text, int start, int end);
char *file_generator(const char *text, int state);

#endif