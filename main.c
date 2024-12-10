#include <stdio.h>
#include <stdlib.h>

int main() {
    char map[5][10];

    FILE* file;

    file = fopen("/workspaces/pac-man-game-c-language/map.txt", "r+");

    if (file == NULL) {
        printf("The file wasn't found.\n");
        exit(1);
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

    return 0;
}