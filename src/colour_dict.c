#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "colour_dict.h"


void init_colour_dict(ColourDict *dict) {
    dict->size = 0;
}