#include <stdio.h>
#include <stdlib.h>

char** map;
int rows, columns;

int main() {

    FILE* file;

    file = fopen("/workspaces/pac-man-game-c-language/map.txt", "r+");

    if (file == NULL) {
        printf("The file wasn't found.\n");
        exit(1);
    }

    fscanf(file, "%d %d", &rows, &columns);

    // alocating rows in pointer
    map = malloc(sizeof(char*) * rows); 
    // alocating columns in the rows of the pointer
    for (int i = 0; i < rows; i++) {
        map[i] = malloc(sizeof(char) * (columns + 1)); // 1 more because \0 at the end of the line
    }

    for (int i = 0; i < 5; i++) {
        fscanf(file, "%s", map[i]);
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rows; i++) {
        free(map[i]);
    }
    free(map);

    return 0;
}