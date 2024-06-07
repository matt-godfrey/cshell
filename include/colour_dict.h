#ifndef COLOUR_DICT_H
#define COLOUR_DICT_H

#define MAX_ENTRIES 20
#define MAX_STRING_LENGTH 100

typedef struct {
    char colour[MAX_STRING_LENGTH];
    int value;
} ColourEntry;

typedef struct {
    ColourEntry *colours[MAX_ENTRIES];
    int size;
} ColourDict;

void init_colour_dict(ColourDict *dict);
int add_colour(ColourDict *dict, const char *colour, int value);


#endif