#include <stdio.h>

void writeFile(FILE *file, char *text) {

    file = fopen("output.txt", "w");
    if (file == NULL) {
        printf("Failed to open file for writing\n");
    }

    fprintf(file, "Hello, World!\n");

    fclose(file);
}