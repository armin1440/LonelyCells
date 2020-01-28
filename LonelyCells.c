#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "map_read.h"
#include "map_build.h"
#include "map_print.h"
#include "cell_data_read.h"

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
    int option , map_dim;
    char *map_data;
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
            //map = map_build(map_data , map_dim , cells);
            //map_print(map , map_dim , cells);

    }
    FILE *cell;
    cell = fopen("cell_data.bin","wb");
    char *s = 0 , f[8];
    struct map_block** o = 0;
    s = map_read("map.bin");
    struct cell a , b , c ,*pa  ;
    int w = 3;
    strcpy(a.name ,"arminaa"); strcpy(b.name,"Aryabbb") ; strcpy(c.name,"goobsee"); a.energy=41 ;
    b.energy= 13; c.energy=12;
    a.x = 1; a.y = 0; a.next = &b; b.x= 0 ; b.y = 1; b.next=&c; c.x = 1 ; c.y = 1; c.next = NULL;
    tmp = &a;
    fwrite(&w , sizeof(int) , 1 , cell);
    while(tmp != NULL){
        fwrite(tmp->name , sizeof(char) , 8 , cell);
        fwrite(&(tmp->energy) , sizeof(int) , 1 , cell);
        fwrite(&(tmp->x) , sizeof(int) , 1 , cell);
        fwrite(&(tmp->y) , sizeof(int) , 1 , cell);
        fwrite(&(tmp->next) , sizeof(struct cell *) , 1 , cell);
        tmp = tmp->next;
    }
    fclose(cell);/*
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