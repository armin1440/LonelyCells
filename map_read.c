#include <stdio.h>
#include <stdlib.h>

char * map_read(char* map_name) {
    FILE *map;
    unsigned int n;
    char *properties;

    map = fopen(map_name, "rb");
    fread(&n, sizeof(unsigned int), 1, map);

    properties = (char *) malloc((n * n + 1) * sizeof(char));
    fread(properties, sizeof(char), n * n, map);

    properties[n * n] = '\0';
    //printf("%d\n", n);
    //printf("%s", properties);
    fclose(map);

    return properties;
}
