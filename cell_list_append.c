#include <stdlib.h>
#include <string.h>
#include <time.h>

int player;

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

void cell_list_append( struct map_block ** map , struct cell * cells , int cell_num , int map_dim , char names[][8])
{
    struct cell * cell= NULL , * list = NULL, *previous = NULL;
    int *x , *y;

    x = (int *)malloc((cell_num+1)* sizeof(int));
    y = (int *)malloc((cell_num+1)* sizeof(int));

    x[0] = 100000000;
    y[0] = 100000000;

    for (int i = 1; i <= cell_num ; ++i) {
        cell = (struct cell*)malloc(sizeof(struct cell));

        cell->player_num = player;
        cell->energy = 0;
        strcpy ( cell->name , names[i-1] );
        cell->name[7] = '\0';

        srand(time(NULL));
        do{
            x[i] = rand()%map_dim;
            y[i] = rand()%map_dim;
        }while( map[ x[i] ][ y[i] ].is_filled != 0 || x[i] == x[i-1] || y[i] == y[i-1]  );

        cell->x = x[i];
        cell->y = y[i];

        if ( previous != NULL)
            previous->next = cell;

        if( i == cell_num)
            cell->next = NULL;

        if ( i == 1 )
            list = cell;

        previous = cell;
    }

    cell = cells;
    while ( cell->next != NULL )
        cell = cell->next;

    cell->next = list;

}