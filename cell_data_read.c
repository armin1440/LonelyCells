#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cell{
    char name[8];
    int energy;
    int x;
    int y;
    struct cell* next;
};

struct cell* cell_data_read (void){
    FILE *cell_file;
    struct cell *temp = NULL , *list = NULL;
    int cell_num;

    cell_file = fopen("cell_data.bin","rb");
    fread(&cell_num , sizeof(int), 1 ,cell_file);
    for (int i = 0; i < cell_num ; ++i) {
        temp =(struct cell*)malloc(sizeof(struct cell));
        fread(temp->name , sizeof(char) , 8 , cell_file);
        temp->name[7] = '\0';
        fread(&(temp->energy) , sizeof(int) , 1 , cell_file);
        fread(&(temp->x) , sizeof(int) , 1 ,cell_file);
        fread(&(temp->y) , sizeof(int) , 1 , cell_file);
        fread(&(temp->next) , sizeof(struct cell*) , 1 , cell_file);
        if ( i == 0 )
            list = temp;
    }
    fclose(cell_file);
    return list;
}