#include "autocomplete.h"
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

char **file_completion(const char *text, int start, int end) {
    rl_attempted_completion_over = 1;
    return rl_completion_matches(text, file_generator);
}

char *file_generator(const char *text, int state) {
    static DIR *dir = NULL;
    static struct dirent *entry;
    static int len;

    if (!state) {
        if (dir) {
            closedir(dir);
            dir = NULL;
        }
        dir = opendir(".");
        len = strlen(text);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strncmp(entry->d_name, text, len) == 0) {
            return strdup(entry->d_name);
        }
    }

    if (dir) {
        closedir(dir);
        dir = NULL;
    }
    return NULL;
}