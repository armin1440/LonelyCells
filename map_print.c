#include <stdio.h>

struct cell{
    char name[8];
    int energy;
    int x;
    int y;
    struct cell* next;
};
struct map_block{
    int type;
    int supply;
    int is_filled;
};

void map_print(struct map_block ** block , int map_dim , struct cell * cells){
    struct cell * temp = cells;

    for (int row = 1; row <=  2*map_dim ; ++row) {
        if ( row%2 == 1 ) {
            printf("   ");
            for (int column = 1; column < map_dim ; column += 2) {
                if (block[ column ][ map_dim-1-(row-1)/2 ].is_filled == 1) {
                    printf("%-6c", 'X');
                }
                else{
                    printf("%-6d", 0);
                }
            }
            printf("\n");
        }
        else{
            for (int column = 0; column < map_dim ; column += 2) {
                if (block[ column ][ map_dim-1-(row-2)/2 ].is_filled == 1)
                    printf("%-6c",'X');
                else
                    printf("%-6d",0);
            }
            printf("\n");
        }
    }
}