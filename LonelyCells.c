#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "map_read.h"
#include "map_build.h"
#include "map_print.h"
#include "map_save.h"
#include "map_read_supply.h"
#include "cell_data_read.h"
#include "cell_rand_name.h"
#include "cell_creat_list.h"
#include "cell_move.h"
#include "cell_split_spawn.h"
#include "cell_split.h"
#include "cell_increase_energy.h"
#include "cell_save.h"
#include "cell_list_append.h"

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
    int player_num;
    struct cell* next;
};

struct map_block{
    int type;
    int supply;
    int is_filled;
};

int player;

int main() {
    int option , counter = 0 , map_dim , cell_num = 0 , cell_num2 = 0 , move_num , cell_selected , *map_supply;
    char *map_data , cell_names[100][8], cell_names2[100][8] ,cell_split_name[2][8];
    struct cell* cells = 0 , *tmp = 0 , *cell = 0;
    struct map_block **map;

    main_menu : printf("[1]load\n[2]New single player game\n[3]New multiplayer game\n[4]Exit\n");

    scanf("%d",&option);

    switch (option){
        case 4:
            return 52;
        //Load
        case 1:
            map_data = map_read();
            map_dim = (int)round(sqrt(strlen(map_data)));
            cells = cell_data_read();
            cell = cells;
            /*while(cell)
            {
                printf("%s\n",cell->name);
                printf("%d\n",cell->x);
                printf("%d\n",cell->y);
                printf("%d\n",cell->energy);
                cell = cell->next;
            }*/
            map_supply = map_read_supply(map_dim);
            map = map_build(map_data , map_dim , cells);
            for (int k = 0; k < map_dim ; ++k) {
                for (int i = 0; i < map_dim ; ++i) {
                    map[k][i].supply = *(map_supply+k*map_dim+i);
                }
            }
            map_print(map , map_dim , cells);
            cell_num = 0;
            cell_num2 = 0;

            cell = cells;
            while(cell->next){
                cell = cell->next;
            }
            if ( cell-> player_num == 1) {
                cell = cells;
                while(cell)
                {
                    cell_num++;
                    cell = cell->next;
                }
                goto gameplay_single;
            }
            else{
                cell = cells;
                while(cell)
                {
                    if ( cell->player_num == 1)
                        cell_num++;
                    else
                        cell_num2++;
                    cell = cell->next;
                }
                goto gameplay_multi;
            }
                break;

            //New single player
        case 2:
            player = 1;
            printf("Enter the number of cells\n");
            scanf("%d",&cell_num);

            for (int j = 0; j < cell_num ; ++j) {
                getchar();
                printf("Enter the %dth cell's name that is less than 8 characters\n",j+1);
                scanf(" %s",cell_names[j]);
                cell_names[j][7] = '\0';
            }

            map_dim = (int)round(sqrt(strlen(map_read())));
            map_data = map_read();
            cells = cell_creat_list(cell_num , map_dim ,cell_names , map_data);
            map = map_build(map_read() , map_dim , cells);
            map_print(map , map_dim , cells);

        gameplay_single : while(1) {
                printf("Choose one of your cells\n");
                cell = cells;
                for (int i = 0; i < cell_num; ++i) {
                    printf("[%d]%s  ( %d , %d )\n", i + 1, cell->name, cell->x, cell->y);
                    cell = cell->next;
                }
                scanf("%d", &cell_selected);

                printf("What do you want to do?\n");
                printf("[1]Move\n[2]Split a cell\n[3]Boost energy\n[4]save\n[5]Exit\n");
                scanf("%d", &option);
                switch (option) {
                    case 5:
                        goto main_menu;
                    case 1:
                        printf("[1]North\n[2]South\n[3]Northeast\n[4]Northwest\n[5]Southeast\n[6]Southwest\n");
                        scanf("%d", &move_num);
                        cell_move(cells ,move_num , map , cell_selected );
                        map_print(map , map_dim , cells);
                        break;
                    case 2:
                        cell = cells;
                        for (int j = 0; j < cell_selected - 1 ; ++j) {
                            cell = cell->next;
                        }
                        if ( map[cell->x][cell->y].type != MITOSIS )
                        {
                            printf("You can not split a cell in this block\n");
                        }else {
                            if (cell->energy < 80) {
                                printf("Not enough energy\n");
                            } else {
                                for (int i = 0; i < 2; ++i) {
                                    printf("Enter the %dth cell's name\n", i + 1);
                                    getchar();
                                    scanf("%s", cell_split_name[i]);
                                    cell_split_name[i][7] = '\0';
                                }
                                cells = cell_split(&cells, map, cell_split_name, map_dim, cell_selected);
                                cell_num += 1;
                            }
                        }
                        map_print(map , map_dim , cells);
                        break;
                    case 3:
                        cell_increase_energy(map , cells , map_dim , cell_selected);
                        map_print(map , map_dim , cells);
                        break;
                    case 4:
                        cell_save(cells);
                        map_save(map , map_dim);
                        break;

                }
            }

            //New multiplayer game
        case 3:
            player = 1;
            printf("1st player : Enter the number of your cells \n");
            scanf("%d",&cell_num);

            for (int j = 0; j < cell_num ; ++j) {
                getchar();
                printf("1st player : Enter the %dth cell's name that is less than 8 characters\n",j+1);
                scanf(" %s",cell_names[j]);
                cell_names[j][7] = '\0';
            }

            map_dim = (int)round(sqrt(strlen(map_read())));
            map_data = map_read();
            cells = cell_creat_list(cell_num , map_dim ,cell_names , map_data);
            map = map_build(map_read() , map_dim , cells);

            player = 2;
            printf("2nd player : Enter the number of your cells \n");
            scanf("%d",&cell_num2);

            for (int j = 0; j < cell_num2 ; ++j) {
                getchar();
                printf("2nd player : Enter the %dth cell's name that is less than 8 characters\n",j+1);
                scanf(" %s",cell_names2[j]);
                cell_names2[j][7] = '\0';
            }

            cell_list_append(map , cells , cell_num2 , map_dim , cell_names2);
            map = map_build(map_data , map_dim , cells);

            /*cell = cells;
            while ( cell ) {
                map[cell->x][cell->y].is_filled = 1;
                cell = cell->next;
            }*/

            map_print(map , map_dim , cells);

        gameplay_multi: while(1) {
                player = 1;
                printf("1st player : Choose one of your cells\n");
                cell = cells;
                for (int i = 0; i < cell_num ; ++i) {
                    printf("[%d]%s  ( %d , %d )\n", i + 1, cell->name, cell->x, cell->y);
                    cell = cell->next;
                }
                scanf("%d", &cell_selected);

                printf("1st player : What do you want to do?\n");
                printf("[1]Move\n[2]Split a cell\n[3]Boost energy\n[4]save\n[5]Exit\n");
                scanf("%d", &option);
                switch (option) {
                    case 5:
                        goto main_menu;
                    case 1:
                        printf("[1]North\n[2]South\n[3]Northeast\n[4]Northwest\n[5]Southeast\n[6]Southwest\n");
                        scanf("%d", &move_num);
                        cell_move(cells ,move_num , map , cell_selected );
                        map_print(map , map_dim , cells);
                        break;
                    case 2:
                        cell = cells;
                        for (int j = 0; j < cell_selected - 1 ; ++j) {
                            cell = cell->next;
                        }
                        if ( map[cell->x][cell->y].type != MITOSIS )
                        {
                            printf("You can not split a cell in this block\n");
                        }else {
                            if (cell->energy < 80) {
                                printf("Not enough energy\n");
                            } else {
                                for (int i = 0; i < 2; ++i) {
                                    printf("Enter the %dth cell's name\n", i + 1);
                                    getchar();
                                    scanf("%s", cell_split_name[i]);
                                    cell_split_name[i][7] = '\0';
                                }
                                cells = cell_split(&cells, map, cell_split_name, map_dim, cell_selected);
                                cell_num += 1;
                            }
                        }
                        map_print(map , map_dim , cells);
                        break;
                    case 3:
                        cell_increase_energy(map , cells , map_dim , cell_selected);
                        map_print(map , map_dim , cells);
                        break;
                    case 4:
                        cell_save(cells);
                        map_save(map , map_dim);
                        break;
                }

                player = 2;
                printf("2nd player : Choose one of your cells\n");
                cell = cells;
                counter = 0;
                while( counter < cell_num ) {
                    counter++;
                    cell = cell->next;
                }
                for (int i = 0; i < cell_num2 ; ++i) {
                    printf("[%d]%s  ( %d , %d )\n", i + 1, cell->name, cell->x, cell->y);
                    cell = cell->next;
                }
                scanf("%d", &cell_selected);

                printf("2nd player : What do you want to do?\n");
                printf("[1]Move\n[2]Split a cell\n[3]Boost energy\n[4]save\n[5]Exit\n");
                scanf("%d", &option);
                switch (option) {
                    case 5:
                        goto main_menu;
                    case 1:
                        printf("[1]North\n[2]South\n[3]Northeast\n[4]Northwest\n[5]Southeast\n[6]Southwest\n");
                        scanf("%d", &move_num);
                        cell_move(cells, move_num, map, cell_selected + cell_num);
                        map_print(map, map_dim, cells);
                        break;
                    case 2:
                        cell = cells;
                        counter = 0;
                        while( counter < cell_num - 1) {
                            counter++;
                            cell = cell->next;
                        }
                        for (int j = 0; j < cell_selected ; ++j) {
                            cell = cell->next;
                        }
                        if (map[cell->x][cell->y].type != MITOSIS) {
                            printf("You can not split a cell in this block\n");
                        } else {
                            if (cell->energy < 80) {
                                printf("Not enough energy\n");
                            } else {
                                for (int i = 0; i < 2; ++i) {
                                    printf("Enter the %dth cell's name\n", i + 1);
                                    getchar();
                                    scanf("%s", cell_split_name[i]);
                                    cell_split_name[i][7] = '\0';
                                }
                                cells = cell_split(&cells, map, cell_split_name, map_dim, cell_selected + cell_num);
                                cell_num2 += 1;
                            }
                        }
                        map_print(map, map_dim, cells);
                        break;
                    case 3:
                        cell_increase_energy(map, cells, map_dim, cell_selected + cell_num);
                        map_print(map, map_dim, cells);
                        break;
                    case 4:
                        cell_save(cells);
                        map_save(map, map_dim);
                        break;
                }
            }
    }
    return 1440;
}