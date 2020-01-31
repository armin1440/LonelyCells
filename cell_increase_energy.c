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

void cell_increase_energy ( struct map_block ** map , struct cell * cells , int map_dim , int cell_selected){
    struct cell * cell = 0;
    cell = cells;

    for (int i = 0; i < cell_selected -1 ; ++i) {
        cell = cell->next;
    }

    if( map[cell->x][cell->y].type != 1){
        printf("You can not boost energy in this block\n");
    }else if( map[cell->x][cell->y].supply == 0 ){
        printf("This block is out of energy\n");
    }
    else {
        if (cell->energy <= 85) {
            if (map[cell->x][cell->y].supply >= 15) {
                cell->energy += 15;
                map[cell->x][cell->y].supply -= 15;
                printf("energy successfully boosted, your new energy = %d , remained energy of this block = %d\n",cell->energy,map[cell->x][cell->y].supply);
            } else {
                cell->energy += map[cell->x][cell->y].supply;
                map[cell->x][cell->y].supply = 0;
                printf("energy successfully boosted, your new energy = %d , remained energy of this block = %d\n",cell->energy,map[cell->x][cell->y].supply);
            }
        } else{
            if( map[cell->x][cell->y].supply >= (100 - cell->energy) ){
                map[cell->x][cell->y].supply -= 100 - cell->energy;
                cell->energy = 100;
                printf("energy successfully boosted, your new energy = %d , remained energy of this block = %d\n",cell->energy,map[cell->x][cell->y].supply);
            } else{
                cell->energy += map[cell->x][cell->y].supply;
                map[cell->x][cell->y].supply = 0;
                printf("energy successfully boosted, your new energy = %d , remained energy of this block = %d\n",cell->energy,map[cell->x][cell->y].supply);
            }
        }
    }
}