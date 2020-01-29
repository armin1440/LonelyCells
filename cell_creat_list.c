#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "cell_rand_name.h"

struct cell{
    char name[8];
    int energy;
    int x;
    int y;
    struct cell* next;
};

struct cell * cell_creat_list(int cell_num , int map_dim , char names[][8] )
{
    struct cell *temp = NULL , *previous = NULL , *list = NULL;
    int *a , *b, flag = 0 , counter1 = 1 , rnd1 , rnd2;

    a = (int*)malloc(cell_num* sizeof(int));
    b = (int*)malloc(cell_num* sizeof(int));
    srand(time(NULL));
    a[0] = rand()%map_dim;
    b[0] = rand()%map_dim;
    while ( counter1 < cell_num ) {
        rnd1 = rand()%map_dim;
        rnd2 = rand()%map_dim;
        flag = 0;
        for (int j = 0; j < counter1 ; ++j) {
            if ( rnd1 == a[j] && rnd2 == b[j] ){
                flag = 1;
                break;
            }
        }
        if ( flag == 0)
        {
            a[counter1] = rnd1;
            b[counter1] = rnd2;
            counter1++;
        }
    }

    list = (struct cell*)malloc(1* sizeof(struct cell));
    strcpy(list->name , names[0] );
    list->energy = 0;
    list->x = a[0];
    list->y = b[0];
    list->next = NULL;

    previous = list;
    for (int i = 1; i < cell_num ; ++i) {
        temp = (struct cell*)malloc(1* sizeof(struct cell));

        previous->next = temp;
        strcpy(temp->name , names[i] );
        temp->name[7] ='\0';
        temp->energy = 0;
        temp->x = a[i];
        temp->y = b[i];
        previous = temp;
        if ( i == cell_num - 1)
            temp->next = NULL;
    }
    return list;
}