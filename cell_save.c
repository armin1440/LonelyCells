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


void cell_save(struct cell* cells ){
    FILE *cell_data;
    cell_data = fopen("cell_data.txt","w");
    struct cell* temp ;
    temp = cells;

    int counter = 0;
    while(temp != NULL){
        counter++;
        temp = temp->next;
    }
    fprintf(cell_data ,"%d\n" , counter);

    temp = cells;
    while(temp != NULL){
        fprintf(cell_data , "%s\n" , temp->name );
        fprintf(cell_data , "%d\n" , temp->player_num);
        fprintf(cell_data , "%d\n" , temp->x);
        fprintf(cell_data , "%d\n" , temp->y);
        fprintf(cell_data , "%d\n" , temp->energy);
        temp = temp->next;
    }
    fclose(cell_data);
    printf("cell data successfully saved\n");
}