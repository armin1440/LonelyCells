#include <stdio.h>
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

void cell_move(struct cell * cells , int move_num , struct map_block ** map , int cell_choice){
    struct cell * cell;
    cell = cells;
    for (int i = 0; i < cell_choice-1 ; ++i) {
        cell = cell ->next;
    }
    switch (move_num) {
        case 1:
            if (map[cell->x][1 + cell->y].is_filled == 3)
                printf("Forbidden block\n");
            else {
                map[cell->x][cell->y + 1].is_filled = 1;
                map[cell->x][cell->y].is_filled = 0;
                cell->y += 1;
            }
            break;
        case 2:
            if (map[cell->x][cell->y - 1].is_filled == 3)
                printf("Forbidden block\n");
            else {
                map[cell->x][cell->y - 1].is_filled = 1;
                map[cell->x][cell->y].is_filled = 0;
                cell->y -= 1;
            }
            break;
        case 3:
            if (cell->x % 2 == 1) {
                if (map[cell->x + 1][cell->y + 1].is_filled == 3)
                    printf("Forbidden block\n");
                else {
                    map[cell->x + 1][cell->y + 1].is_filled = 1;
                    map[cell->x][cell->y].is_filled = 0;
                    cell->x += 1;
                    cell->y += 1;
                }
            } else {
                if (map[cell->x + 1][cell->y].is_filled == 3)
                    printf("Forbidden block\n");
                else {
                    map[cell->x + 1][cell->y].is_filled = 1;
                    map[cell->x][cell->y].is_filled = 0;
                    cell->x += 1;
                }
            }
            break;
        case 4:
            if (cell->x % 2 == 1) {
                if (map[cell->x - 1][cell->y + 1].is_filled == 3)
                    printf("Forbidden block\n");
                else {
                    map[cell->x - 1][cell->y + 1].is_filled = 1;
                    map[cell->x][cell->y].is_filled = 0;
                    cell->x -= 1;
                    cell->y += 1;
                }
            } else {
                if (map[cell->x - 1][cell->y].is_filled == 3)
                    printf("Forbidden block\n");
                else {
                    map[cell->x - 1][cell->y].is_filled = 1;
                    map[cell->x][cell->y].is_filled = 0;
                    cell->x -= 1;
                }
            }
            break;
        case 5:
            if (cell->x % 2 == 1) {
                if (map[cell->x + 1][cell->y].is_filled == 3)
                    printf("Forbidden block\n");
                else {
                    map[cell->x + 1][cell->y].is_filled = 1;
                    map[cell->x][cell->y].is_filled = 0;
                    cell->x += 1;
                }
            } else {
                if (map[cell->x + 1][cell->y - 1].is_filled == 3)
                    printf("Forbidden block\n");
                else {
                    map[cell->x + 1][cell->y - 1].is_filled = 1;
                    map[cell->x][cell->y].is_filled = 0;
                    cell->x += 1;
                    cell->y -= 1;
                }
            }
            break;
        case 6:
            if (cell->x % 2 == 1) {
                if (map[cell->x - 1][cell->y].is_filled == 3)
                    printf("Forbidden block\n");
                else {
                    map[cell->x - 1][cell->y].is_filled = 1;
                    map[cell->x][cell->y].is_filled = 0;
                    cell->x -= 1;
                }
            } else {
                if (map[cell->x - 1][cell->y - 1].is_filled == 3)
                    printf("Forbidden block\n");
                else {
                    map[cell->x - 1][cell->y - 1].is_filled = 1;
                    map[cell->x][cell->y].is_filled = 0;
                    cell->x -= 1;
                    cell->y -= 1;
                }
            }
            break;
    }
}