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

void map_print(struct map_block ** block , int map_dim , struct cell * cells){
    struct cell * temp ;
    temp = cells;

    for (int row = 1; row <=  2*map_dim ; ++row) {
        if ( row%2 == 1 ) {
            printf("      ");
            for (int column = 1; column < map_dim ; column += 2) {
                if (block[ column ][ map_dim-1-(row-1)/2 ].is_filled == 1) {
                    temp = cells;
                    while( (temp->x != column || temp->y != map_dim-1-(row-1)/2) )
                        temp = temp->next;
                    if (temp->player_num == 1)
                        printf("%-12c", 'X');
                    else
                        printf("%-12c",'Y');
                }
                else{
                    if (block[ column ][ map_dim-1-(row-1)/2 ].type == 1)
                        printf("%-12c", 'E');
                    if (block[ column ][ map_dim-1-(row-1)/2 ].type == 2)
                        printf("%-12c", 'M');
                    if (block[ column ][ map_dim-1-(row-1)/2 ].type == 3)
                        printf("%-12c", '-');
                    if (block[ column ][ map_dim-1-(row-1)/2 ].type == 4)
                        printf("%-12c", '0');
                }
            }
            printf("\n");
        }
        else{
            for (int column = 0; column < map_dim ; column += 2) {
                if (block[ column ][ map_dim-1-(row-2)/2 ].is_filled == 1) {
                    temp = cells;
                    while ( (temp->x != column || temp->y != map_dim - 1 - (row - 2) / 2) )
                        temp = temp->next;
                    if (temp->player_num == 1)
                        printf("%-12c", 'X');
                    else
                        printf("%-12c", 'Y');
                }
                else{
                    if (block[ column ][ map_dim-1-(row-1)/2 ].type == 1)
                        printf("%-12c", 'E');
                    if (block[ column ][ map_dim-1-(row-1)/2 ].type == 2)
                        printf("%-12c", 'M');
                    if (block[ column ][ map_dim-1-(row-1)/2 ].type == 3)
                        printf("%-12c", '-');
                    if (block[ column ][ map_dim-1-(row-1)/2 ].type == 4)
                        printf("%-12c", '0');
                }
            }
            printf("\n");
        }
    }
}