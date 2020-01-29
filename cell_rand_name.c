#include <stdlib.h>
#include <time.h>

char * cell_rand_name(void){
    srand( time(NULL) );
    char * str = (char*) malloc(8* sizeof(char));
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (size_t i = 0; i < 7 ; ++i) {
        int key = rand() % (sizeof(charset) / sizeof(char) - 1);
        str[i] = charset[key];
    }
    str[7] = '\0';
    return str;
}