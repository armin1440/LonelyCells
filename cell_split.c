#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "cell_split_spawn.h"

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

struct cell * cell_split(struct cell ** cells , struct map_block **map , char names[][8] , int map_dim , int cell_selected){
    struct cell * cell , *new_cells ;
    cell = *cells;
    new_cells = (struct cell *)malloc( 2* sizeof(struct cell));
    new_cells[0].next = new_cells+1;
    new_cells[0].energy = 40;
    new_cells[1].energy = 40;
    srand(time(NULL));

    if ( cell_selected == 1 )
    {
        new_cells[1].next = (*cells)->next;
        new_cells[0].x = (*cells)->x;
        new_cells[0].y = (*cells)->y;
        new_cells[0].player_num = (*cells)->player_num;
        new_cells[1].player_num = (*cells)->player_num;
        strcpy( new_cells[0].name , names[0] );
        strcpy( new_cells[1].name , names[1] );

        cell_split_spawn(map , new_cells , map_dim);

        (*cells) = new_cells;
    }
    else {
        for (int i = 0; i < cell_selected - 2; ++i)
            cell = cell->next;

        new_cells[1].next = cell->next->next;
        new_cells[0].x = cell->next->x;
        new_cells[0].y = cell->next->y;
        new_cells[0].player_num = cell->next->player_num;
        new_cells[1].player_num = cell->next->player_num;
        strcpy( new_cells[0].name , names[0] );
        strcpy( new_cells[1].name , names[1] );
        cell->next = new_cells;

        cell_split_spawn(map , new_cells , map_dim);

    }
    return *cells;
}