#include <stdio.h>
#include <stdlib.h>

struct cell{
    char name[8];
    int energy;
    int x;
    int y;
    struct cell* next;
};

struct cell* cell_data_read (void){
    FILE *cell_file;
    struct cell *temp = NULL , *previous = NULL , *list = NULL;
    int cell_num;

    cell_file = fopen("cell_data.txt","r");

    fscanf(cell_file , "%d" , &cell_num );

    for (int i = 0; i < cell_num ; ++i) {
        temp =(struct cell*)malloc(sizeof(struct cell));

        if ( previous != NULL)
            previous->next = temp;

        fgetc(cell_file);
        fscanf(cell_file , "%s" , temp->name);
        temp->name[7] = '\0';

        fgetc(cell_file);
        fscanf(cell_file , "%d" , &temp->x);

        fgetc(cell_file);
        fscanf(cell_file , "%d" , &temp->y);

        fgetc(cell_file);
        fscanf(cell_file , "%d" , &temp->energy);

        previous = temp;

        if ( i == 0 )
            list = temp;
    }
    previous->next = NULL;
    fclose(cell_file);
    return list;
}