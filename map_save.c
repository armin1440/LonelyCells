#include <stdio.h>
#include <stdlib.h>

struct map_block{
    int type;
    int supply;
    int is_filled;
};

void map_save(struct map_block ** map , int map_dim){
    FILE * map_type , *map_isFilled , *map_supply;

    map_type = fopen("map.bin","wb");
    map_supply = fopen("map_supply.bin","wb");

    char *data;
    data = (char *)malloc(map_dim*map_dim);

    for (int k = 0; k < map_dim ; ++k) {
        for (int i = 0; i < map_dim ; ++i) {
            switch (map[i][k].type){
                case 1:
                    *(data + k*map_dim + i) = '1';
                    break;
                case 2:
                    *(data + k*map_dim + i) = '2';
                    break;
                case 3:
                    *(data + k*map_dim + i) = '3';
                    break;
                case 4:
                    *(data + k*map_dim + i) = '4';
                    break;
            }
        }
    }
    *(data + map_dim*map_dim) = '\0';

    fwrite(&map_dim , sizeof(int) , 1 , map_type);

    for (int i = 0; i < map_dim ; ++i) {
        for (int j = 0; j < map_dim ; ++j) {
            fwrite( data+i*map_dim+j , sizeof(char) , 1 , map_type);
            fwrite(&(map[j][i].supply) , sizeof(int) , 1 , map_supply );
        }
    }

    fclose(map_type);
    fclose(map_supply);
    printf("map successfully saved\n");
}
