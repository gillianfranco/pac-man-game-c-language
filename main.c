#include <stdio.h>
#include <stdlib.h>
#include "pac-man-game.h"

char** map;
int rows, columns;

int main() {

    read_map();
    
    // Printing
    for (int i = 0; i < 5; i++) {
        printf("%s", map[i]);
        printf("\n");
    }

    free_map();

    return 0;
}

void read_map() {
    FILE* file;

    file = fopen("/workspaces/pac-man-game-c-language/map.txt", "r+");

    if (file == NULL) {
        printf("The file wasn't found.\n");
        exit(1);
    }

    fscanf(file, "%d %d", &rows, &columns);

    allocate_map();

    for (int i = 0; i < 5; i++) {
        fscanf(file, "%s", map[i]);
    }
}

void allocate_map() {
    // alocating rows in pointer
    map = malloc(sizeof(char*) * rows); 
    // alocating columns in the rows of the pointer
    for (int i = 0; i < rows; i++) {
        map[i] = malloc(sizeof(char) * (columns + 1)); // 1 more because \0 at the end of the line
    }
}

void free_map() {
    for (int i = 0; i < rows; i++) {
        free(map[i]);
    }
    free(map);
}