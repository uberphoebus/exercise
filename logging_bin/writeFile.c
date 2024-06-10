#include <stdio.h>

void writeFile(FILE *file, char *text) {

    file = fopen("output.txt", "a+");
    if (file == NULL) {
        printf("Failed to open file for writing\n");
    }

    fprintf(file, "%s", text);

    fclose(file);
}