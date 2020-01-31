#include <stdio.h>
#include <stdlib.h>
struct cell{
    char name[8];
    int energy;
    int x;
    int y;
    int player_num;
    struct cell* next;
};

struct map_block{
    int type;
    int supply;
    int is_filled;
};

int * map_read_supply(int map_dim)
{
    int * out;
    FILE *supply;
    supply = fopen("map_supply.bin","rb");
    out = (int *)malloc((map_dim*map_dim)* sizeof(int));
    for (int i = 0; i < map_dim*map_dim ; ++i) {
        fread(out+i , sizeof(int) , 1 , supply);
    }
    fclose(supply);
    return out;
}