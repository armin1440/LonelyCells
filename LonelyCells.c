#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "map_read.h"
#include "map_build.h"
#include "map_print.h"
#include "cell_data_read.h"
#include "cell_rand_name.h"
#include "cell_creat_list.h"

enum blocks{
    ENERGY = 1,
    MITOSIS,
    FORBIDDEN,
    NORMAL
};

struct cell{
    char name[8];
    int energy;
    int x;
    int y;
    struct cell* next;
};

struct map_block{
    int type;
    int is_filled;
};

int main() {
    int option , option2 , map_dim , cell_num;
    char *map_data , cell_names[100][8];
    struct cell* cells = 0 , *tmp = 0;
    struct map_block **map;

    printf("[1]load\n[2]New single player game\n[3]New multiplayer game\n[4]Exit\n");

    scanf("%d",&option);

    switch (option){
        case 1:
            map_data = map_read();
            map_dim = (int)round(sqrt(strlen(map_data)));
            cells = cell_data_read();
            tmp = cells;
            while (tmp != NULL)
            {
                printf("%s\t",tmp->name);
                printf("%d\t",tmp->energy);
                printf("%d\t",tmp->x);
                printf("%d\n",tmp->y);
                tmp = tmp->next;
            }
            map = map_build(map_data , map_dim , cells);
            map_print(map , map_dim , cells);
            break;
        case 2:
            printf("Enter the number of cells\n");
            scanf("%d",&cell_num);
            map_dim = (int)round(sqrt(strlen(map_read())));
            for (int j = 0; j < cell_num ; ++j) {
                getchar();
                printf("Enter the %dth cell's name, It must be exactly 7 chararcters!\n",j+1);
                scanf(" %s",cell_names[j]);
                cell_names[j][7] = '\0';
            }
            cells = cell_creat_list(cell_num , 4 ,cell_names);
            map = map_build(map_read() , 4 , cells);
            map_print(map , 4 , cells);
            printf("Choose one of your cells\n");
            tmp = cells;
            for (int i = 0; i < cell_num ; ++i) {
                printf("[%d]%s  ( %d , %d )\n",i+1,tmp->name , tmp->x , tmp->y);
                tmp = tmp->next;
            }
            scanf("%d",&option);
            tmp = cells;
            for (int k = 0; k < option - 1 ; ++k)
                tmp = tmp->next;
            printf("What do you want to do?\n");
            printf("[1]Move\n[2]Split a cell\n[3]Boost energy\n[4]save\n[5]Exit\n");
            
    }

    /*
    tmp = cell_data_read();
    while (tmp != NULL)
    {
        printf("%s\t",tmp->name);
        printf("%d\t",tmp->energy);
        printf("%d\t",tmp->x);
        printf("%d\t",tmp->y);
        tmp = tmp->next;
    }
    o = map_build(s,(int)sqrt(strlen(s)),pa );
    map_print(o,(int)sqrt(strlen(s)),pa);
    for (int i = 0; i < (int)sqrt(strlen(s)) ; ++i) {
        for (int j = 0; j < (int)sqrt(strlen(s)); ++j) {
            printf("%d\t%d\t%d\t%d\n",i,j,o[i][j].type,o[i][j].is_filled);
        }
    }*/
    return 1440;
}