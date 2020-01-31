#include <stdlib.h>
#include <time.h>

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

int cell_split_spawn(struct map_block ** map , struct cell* splited_cell , int map_dim ){
    if ( splited_cell->x == 0 ){
        if ( splited_cell->y == 0 )
        {
            if ( map[splited_cell->x][splited_cell->y+1].is_filled == 0 ){
                splited_cell->next->x = splited_cell->x;
                splited_cell->next->y = splited_cell->y+1;
                map[splited_cell->x][splited_cell->y+1].is_filled = 1;
                return 1;
            }
            if ( map[splited_cell->x+1][splited_cell->y].is_filled == 0 ){
                splited_cell->next->x = splited_cell->x+1;
                splited_cell->next->y = splited_cell->y;
                map[splited_cell->x+1][splited_cell->y].is_filled = 1;
                return 1;
            }
        }

        else if( splited_cell->y == map_dim - 1){
            if ( map[splited_cell->x][splited_cell->y-1].is_filled == 0 ){
                splited_cell->next->x = splited_cell->x;
                splited_cell->next->y = splited_cell->y-1;
                map[splited_cell->x][splited_cell->y-1].is_filled = 1;
                return 1;
            }
            if ( map[splited_cell->x+1][splited_cell->y-1].is_filled == 0 ){
                splited_cell->next->x = splited_cell->x+1;
                splited_cell->next->y = splited_cell->y-1;
                map[splited_cell->x+1][splited_cell->y-1].is_filled = 1;
                return 1;
            }
            if ( map[splited_cell->x+1][splited_cell->y].is_filled == 0 ){
                splited_cell->next->x = splited_cell->x+1;
                splited_cell->next->y = splited_cell->y;
                map[splited_cell->x+1][splited_cell->y].is_filled = 1;
                return 1;
            }

        }

        else{
            if ( map[splited_cell->x][splited_cell->y-1].is_filled == 0 ){
                splited_cell->next->x = splited_cell->x;
                splited_cell->next->y = splited_cell->y-1;
                map[splited_cell->x][splited_cell->y-1].is_filled = 1;
                return 1;
            }
            if ( map[splited_cell->x+1][splited_cell->y].is_filled == 0 ){
                splited_cell->next->x = splited_cell->x+1;
                splited_cell->next->y = splited_cell->y;
                map[splited_cell->x+1][splited_cell->y].is_filled = 1;
                return 1;
            }
            if ( map[splited_cell->x+1][splited_cell->y-1].is_filled == 0 ){
                splited_cell->next->x = splited_cell->x+1;
                splited_cell->next->y = splited_cell->y-1;
                map[splited_cell->x+1][splited_cell->y-1].is_filled = 1;
                return 1;
            }
            if ( map[splited_cell->x][splited_cell->y+1].is_filled == 0 ){
                splited_cell->next->x = splited_cell->x;
                splited_cell->next->y = splited_cell->y+1;
                map[splited_cell->x][splited_cell->y+1].is_filled = 1;
                return 1;
            }
        }
    }

    else if ( splited_cell->x == map_dim - 1 ){
        if ( splited_cell->x %2 == 0 )
        {
            if ( splited_cell->y == 0 ){
                if ( map[splited_cell->x-1][splited_cell->y].is_filled == 0 ){
                    splited_cell->next->x = splited_cell->x-1;
                    splited_cell->next->y = splited_cell->y;
                    map[splited_cell->x-1][splited_cell->y].is_filled = 1;
                    return 1;
                }
                if ( map[splited_cell->x][splited_cell->y+1].is_filled == 0 ){
                    splited_cell->next->x = splited_cell->x;
                    splited_cell->next->y = splited_cell->y+1;
                    map[splited_cell->x][splited_cell->y+1].is_filled = 1;
                    return 1;
                }
            }

            else if ( splited_cell->y == map_dim - 1 )
            {
                if ( map[splited_cell->x][splited_cell->y-1].is_filled == 0 ){
                    splited_cell->next->x = splited_cell->x;
                    splited_cell->next->y = splited_cell->y-1;
                    map[splited_cell->x][splited_cell->y-1].is_filled = 1;
                    return 1;
                }
                if ( map[splited_cell->x-1][splited_cell->y].is_filled == 0 ){
                    splited_cell->next->x = splited_cell->x-1;
                    splited_cell->next->y = splited_cell->y;
                    map[splited_cell->x-1][splited_cell->y].is_filled = 1;
                    return 1;
                }
                if ( map[splited_cell->x-1][splited_cell->y-1].is_filled == 0 ){
                    splited_cell->next->x = splited_cell->x-1;
                    splited_cell->next->y = splited_cell->y-1;
                    map[splited_cell->x-1][splited_cell->y-1].is_filled = 1;
                    return 1;
                }
            }

            else
            {
                if ( map[splited_cell->x][splited_cell->y-1].is_filled == 0 ){
                    splited_cell->next->x = splited_cell->x;
                    splited_cell->next->y = splited_cell->y-1;
                    map[splited_cell->x][splited_cell->y-1].is_filled = 1;
                    return 1;
                }
                if ( map[splited_cell->x-1][splited_cell->y-1].is_filled == 0 ){
                    splited_cell->next->x = splited_cell->x-1;
                    splited_cell->next->y = splited_cell->y-1;
                    map[splited_cell->x-1][splited_cell->y-1].is_filled = 1;
                    return 1;
                }
                if ( map[splited_cell->x-1][splited_cell->y].is_filled == 0 ){
                    splited_cell->next->x = splited_cell->x-1;
                    splited_cell->next->y = splited_cell->y;
                    map[splited_cell->x-1][splited_cell->y].is_filled = 1;
                    return 1;
                }
                if ( map[splited_cell->x][splited_cell->y+1].is_filled == 0 ){
                    splited_cell->next->x = splited_cell->x;
                    splited_cell->next->y = splited_cell->y+1;
                    map[splited_cell->x][splited_cell->y+1].is_filled = 1;
                    return 1;
                }
            }
        }
        if ( splited_cell->x %2 == 1)
        {
            if ( splited_cell->y == 0 ){
                if ( map[splited_cell->x-1][splited_cell->y].is_filled == 0 ){
                    splited_cell->next->x = splited_cell->x-1;
                    splited_cell->next->y = splited_cell->y;
                    map[splited_cell->x-1][splited_cell->y].is_filled = 1;
                    return 1;
                }
                if ( map[splited_cell->x][splited_cell->y+1].is_filled == 0 ){
                    splited_cell->next->x = splited_cell->x;
                    splited_cell->next->y = splited_cell->y+1;
                    map[splited_cell->x][splited_cell->y+1].is_filled = 1;
                    return 1;
                }
                if ( map[splited_cell->x-1][splited_cell->y+1].is_filled == 0 ){
                    splited_cell->next->x = splited_cell->x-1;
                    splited_cell->next->y = splited_cell->y+1;
                    map[splited_cell->x-1][splited_cell->y+1].is_filled = 1;
                    return 1;
                }
            }

            else if ( splited_cell->y == map_dim - 1 )
            {
                if ( map[splited_cell->x][splited_cell->y-1].is_filled == 0 ){
                    splited_cell->next->x = splited_cell->x;
                    splited_cell->next->y = splited_cell->y-1;
                    map[splited_cell->x][splited_cell->y-1].is_filled = 1;
                    return 1;
                }
                if ( map[splited_cell->x-1][splited_cell->y].is_filled == 0 ){
                    splited_cell->next->x = splited_cell->x-1;
                    splited_cell->next->y = splited_cell->y;
                    map[splited_cell->x-1][splited_cell->y].is_filled = 1;
                    return 1;
                }
            }

            else
            {
                if ( map[splited_cell->x][splited_cell->y-1].is_filled == 0 ){
                    splited_cell->next->x = splited_cell->x;
                    splited_cell->next->y = splited_cell->y-1;
                    map[splited_cell->x][splited_cell->y-1].is_filled = 1;
                    return 1;
                }
                if ( map[splited_cell->x-1][splited_cell->y+1].is_filled == 0 ){
                    splited_cell->next->x = splited_cell->x-1;
                    splited_cell->next->y = splited_cell->y+1;
                    map[splited_cell->x-1][splited_cell->y+1].is_filled = 1;
                    return 1;
                }
                if ( map[splited_cell->x-1][splited_cell->y].is_filled == 0 ){
                    splited_cell->next->x = splited_cell->x-1;
                    splited_cell->next->y = splited_cell->y;
                    map[splited_cell->x-1][splited_cell->y].is_filled = 1;
                    return 1;
                }
                if ( map[splited_cell->x][splited_cell->y+1].is_filled == 0 ){
                    splited_cell->next->x = splited_cell->x;
                    splited_cell->next->y = splited_cell->y+1;
                    map[splited_cell->x][splited_cell->y+1].is_filled = 1;
                    return 1;
                }
            }
        }
    }

    else if ( splited_cell->y == 0 )
    {
        if ( splited_cell->x %2 == 1)
        {
            if ( map[splited_cell->x][splited_cell->y+1].is_filled == 0 ){
                splited_cell->next->x = splited_cell->x;
                splited_cell->next->y = splited_cell->y+1;
                map[splited_cell->x][splited_cell->y+1].is_filled = 1;
                return 1;
            }
            if ( map[splited_cell->x-1][splited_cell->y+1].is_filled == 0 ){
                splited_cell->next->x = splited_cell->x-1;
                splited_cell->next->y = splited_cell->y+1;
                map[splited_cell->x-1][splited_cell->y+1].is_filled = 1;
                return 1;
            }
            if ( map[splited_cell->x+1][splited_cell->y+1].is_filled == 0 ){
                splited_cell->next->x = splited_cell->x+1;
                splited_cell->next->y = splited_cell->y+1;
                map[splited_cell->x+1][splited_cell->y+1].is_filled = 1;
                return 1;
            }
            if ( map[splited_cell->x+1][splited_cell->y].is_filled == 0 ){
                splited_cell->next->x = splited_cell->x+1;
                splited_cell->next->y = splited_cell->y;
                map[splited_cell->x+1][splited_cell->y].is_filled = 1;
                return 1;
            }
            if ( map[splited_cell->x-1][splited_cell->y].is_filled == 0 ){
                splited_cell->next->x = splited_cell->x-1;
                splited_cell->next->y = splited_cell->y;
                map[splited_cell->x-1][splited_cell->y].is_filled = 1;
                return 1;
            }
        }

        if ( splited_cell->x %2 == 0)
        {
            if ( map[splited_cell->x][splited_cell->y+1].is_filled == 0 ){
                splited_cell->next->x = splited_cell->x;
                splited_cell->next->y = splited_cell->y+1;
                map[splited_cell->x][splited_cell->y+1].is_filled = 1;
                return 1;
            }
            if ( map[splited_cell->x+1][splited_cell->y].is_filled == 0 ){
                splited_cell->next->x = splited_cell->x+1;
                splited_cell->next->y = splited_cell->y;
                map[splited_cell->x+1][splited_cell->y].is_filled = 1;
                return 1;
            }
            if ( map[splited_cell->x-1][splited_cell->y].is_filled == 0 ){
                splited_cell->next->x = splited_cell->x-1;
                splited_cell->next->y = splited_cell->y;
                map[splited_cell->x-1][splited_cell->y].is_filled = 1;
                return 1;
            }
        }
    }

    else if ( splited_cell->y == map_dim -1 )
    {
        if ( splited_cell->x %2 == 0)
        {
            if ( map[splited_cell->x][splited_cell->y-1].is_filled == 0 ){
                splited_cell->next->x = splited_cell->x;
                splited_cell->next->y = splited_cell->y-1;
                map[splited_cell->x][splited_cell->y-1].is_filled = 1;
                return 1;
            }
            if ( map[splited_cell->x-1][splited_cell->y-1].is_filled == 0 ){
                splited_cell->next->x = splited_cell->x-1;
                splited_cell->next->y = splited_cell->y-1;
                map[splited_cell->x-1][splited_cell->y-1].is_filled = 1;
                return 1;
            }
            if ( map[splited_cell->x+1][splited_cell->y-1].is_filled == 0 ){
                splited_cell->next->x = splited_cell->x+1;
                splited_cell->next->y = splited_cell->y-1;
                map[splited_cell->x+1][splited_cell->y-1].is_filled = 1;
                return 1;
            }
            if ( map[splited_cell->x+1][splited_cell->y].is_filled == 0 ){
                splited_cell->next->x = splited_cell->x+1;
                splited_cell->next->y = splited_cell->y;
                map[splited_cell->x+1][splited_cell->y].is_filled = 1;
                return 1;
            }
            if ( map[splited_cell->x-1][splited_cell->y].is_filled == 0 ){
                splited_cell->next->x = splited_cell->x-1;
                splited_cell->next->y = splited_cell->y;
                map[splited_cell->x-1][splited_cell->y].is_filled = 1;
                return 1;
            }
        }

        if ( splited_cell->x %2 == 1)
        {
            if ( map[splited_cell->x][splited_cell->y-1].is_filled == 0 ){
                splited_cell->next->x = splited_cell->x;
                splited_cell->next->y = splited_cell->y-1;
                map[splited_cell->x][splited_cell->y-1].is_filled = 1;
                return 1;
            }
            if ( map[splited_cell->x+1][splited_cell->y].is_filled == 0 ){
                splited_cell->next->x = splited_cell->x+1;
                splited_cell->next->y = splited_cell->y;
                map[splited_cell->x+1][splited_cell->y].is_filled = 1;
                return 1;
            }
            if ( map[splited_cell->x-1][splited_cell->y].is_filled == 0 ){
                splited_cell->next->x = splited_cell->x-1;
                splited_cell->next->y = splited_cell->y;
                map[splited_cell->x-1][splited_cell->y].is_filled = 1;
                return 1;
            }
        }
    }

    else{
        if ( splited_cell->x %2 == 1)
        {
            if ( map[splited_cell->x][splited_cell->y-1].is_filled == 0 ){
                splited_cell->next->x = splited_cell->x;
                splited_cell->next->y = splited_cell->y-1;
                map[splited_cell->x][splited_cell->y-1].is_filled = 1;
                return 1;
            }
            if ( map[splited_cell->x-1][splited_cell->y+1].is_filled == 0 ){
                splited_cell->next->x = splited_cell->x-1;
                splited_cell->next->y = splited_cell->y+1;
                map[splited_cell->x-1][splited_cell->y+1].is_filled = 1;
                return 1;
            }
            if ( map[splited_cell->x+1][splited_cell->y+1].is_filled == 0 ){
                splited_cell->next->x = splited_cell->x+1;
                splited_cell->next->y = splited_cell->y+1;
                map[splited_cell->x+1][splited_cell->y+1].is_filled = 1;
                return 1;
            }
            if ( map[splited_cell->x+1][splited_cell->y].is_filled == 0 ){
                splited_cell->next->x = splited_cell->x+1;
                splited_cell->next->y = splited_cell->y;
                map[splited_cell->x+1][splited_cell->y].is_filled = 1;
                return 1;
            }
            if ( map[splited_cell->x-1][splited_cell->y].is_filled == 0 ){
                splited_cell->next->x = splited_cell->x-1;
                splited_cell->next->y = splited_cell->y;
                map[splited_cell->x-1][splited_cell->y].is_filled = 1;
                return 1;
            }
            if ( map[splited_cell->x][splited_cell->y+1].is_filled == 0 ){
                splited_cell->next->x = splited_cell->x;
                splited_cell->next->y = splited_cell->y+1;
                map[splited_cell->x][splited_cell->y+1].is_filled = 1;
                return 1;
            }
        }

        if ( splited_cell->x %2 == 0)
        {
            if ( map[splited_cell->x][splited_cell->y-1].is_filled == 0 ){
                splited_cell->next->x = splited_cell->x;
                splited_cell->next->y = splited_cell->y-1;
                map[splited_cell->x][splited_cell->y-1].is_filled = 1;
                return 1;
            }
            if ( map[splited_cell->x-1][splited_cell->y-1].is_filled == 0 ){
                splited_cell->next->x = splited_cell->x-1;
                splited_cell->next->y = splited_cell->y-1;
                map[splited_cell->x-1][splited_cell->y-1].is_filled = 1;
                return 1;
            }
            if ( map[splited_cell->x+1][splited_cell->y-1].is_filled == 0 ){
                splited_cell->next->x = splited_cell->x+1;
                splited_cell->next->y = splited_cell->y-1;
                map[splited_cell->x+1][splited_cell->y-1].is_filled = 1;
                return 1;
            }
            if ( map[splited_cell->x+1][splited_cell->y].is_filled == 0 ){
                splited_cell->next->x = splited_cell->x+1;
                splited_cell->next->y = splited_cell->y;
                map[splited_cell->x+1][splited_cell->y].is_filled = 1;
                return 1;
            }
            if ( map[splited_cell->x-1][splited_cell->y].is_filled == 0 ){
                splited_cell->next->x = splited_cell->x-1;
                splited_cell->next->y = splited_cell->y;
                map[splited_cell->x-1][splited_cell->y].is_filled = 1;
                return 1;
            }
            if ( map[splited_cell->x][splited_cell->y+1].is_filled == 0 ){
                splited_cell->next->x = splited_cell->x;
                splited_cell->next->y = splited_cell->y+1;
                map[splited_cell->x][splited_cell->y+1].is_filled = 1;
                return 1;
            }
        }
    }

}