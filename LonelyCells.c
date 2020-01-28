#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "map_read.h"
#include "map_build.h"

enum blocks{
    ENERGY = 1,
    MITOSIS,
    FORBIDDEN,
    NORMAL
};

struct map_block{
    int type;
    int is_filled;
};

int main() {
    char *s = 0;
    struct map_block** o = 0;
    s = map_read("map.bin");
    o = map_build(s,(int)sqrt(strlen(s)));
    for (int i = 0; i < (int)sqrt(strlen(s)) ; ++i) {
        for (int j = 0; j < (int)sqrt(strlen(s)); ++j) {
            printf("%d\t%d\t%d\t%d\n",i,j,o[i][j].type,o[i][j].is_filled);
        }
    }
    return 1440;
}