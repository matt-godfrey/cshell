#ifndef PARSER_H
#define PARSER_H

void parse_args(char*, char**, size_t, size_t*);
void find_binary(char *);
void ch_dir(char *);

char **file_completion(const char *text, int start, int end);
char *file_generator(const char *text, int state);

#endif