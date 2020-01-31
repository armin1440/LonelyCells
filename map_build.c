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
enum blocks{
    ENERGY = 1,
    MITOSIS,
    FORBIDDEN,
    NORMAL
};

struct map_block** map_build(char* map_data , int map_dim , struct cell * cells ){
    unsigned int block_numbers = 0;
    struct map_block **block = NULL;
    struct cell * temp = cells;

    block = (struct map_block **)malloc(map_dim* sizeof(struct map_block*));

    for (int i = 0; i < map_dim ; ++i)
        block[i] = (struct map_block *)malloc(map_dim* sizeof(struct map_block ));

    for (int i = 0; i < map_dim ; ++i) {
        for (int j = 0; j < map_dim ; ++j) {
            temp = cells;
            block[i][j].type = *(map_data+j*map_dim+i)-'0';
            if ( block[i][j].type == ENERGY)
                block[i][j].supply = 100;
            else
                block[i][j].supply = 0;
            if ( block[i][j].type == FORBIDDEN )
                block[i][j].is_filled = 3;
            else
                block[i][j].is_filled = 0;
            while( temp != NULL )
            {
                if ( temp->x == i && temp->y == j )
                    block[i][j].is_filled = 1;
                temp = temp->next;
            }
            //printf("%d\t%d\t%d\t%d\n",i,j,block[i][j].type,block[i][j].is_filled);
        }
    }

    return block;
}
