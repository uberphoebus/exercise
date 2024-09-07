#include <errno.h>
#include <stdio.h>
#include <unistd.h>

extern int errno;

int main() {
  FILE *file;

  if ((file = fopen("file.txt", "r")) == NULL) {
    printf("Error: %d\n", errno);
    exit(1);
  }
  fclose(file);
}
