#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct map_block{
    int type;
    int is_filled;
};

struct map_block** map_build(char* map_data , int map_dim){
    unsigned int block_numbers = 0;
    struct map_block **block = NULL;

    block = (struct map_block **)malloc(map_dim* sizeof(struct map_block*));

    for (int i = 0; i < map_dim ; ++i)
        block[i] = (struct map_block *)malloc(map_dim* sizeof(struct map_block ));

    for (int i = 0; i < map_dim ; ++i) {
        for (int j = 0; j < map_dim ; ++j) {
            block[i][j].type = *(map_data+i*map_dim+j)-'0';
            block[i][j].is_filled = 0;
            //printf("%d\t%d\t%d\t%d\n",i,j,block[i][j].type,block[i][j].is_filled);
        }
    }

    return block;
}
