#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "colour_dict.h"


void init_colour_dict(ColourDict *dict) {
    dict->size = 0;

    for (int i = 0; i < MAX_ENTRIES; i++) {
        dict->colours[i] = NULL;
    }
}

int add_colour(ColourDict *dict, const char *colour, int value) {
    if (dict->size < MAX_ENTRIES) {
        ColourEntry *newColour = (ColourEntry *)malloc(sizeof(ColourEntry));
        if (newColour == NULL) {
            printf("Memory allocation failed\n");
            return -1;
        }

        strncpy(newColour->colour, colour, sizeof(newColour->colour) - 1);
        newColour->colour[sizeof(newColour->colour) - 1] = '\0';
        newColour->value = value;

        dict->colours[dict->size] = newColour;
        dict->size++;
        return 0;
    }
    return -1;

}