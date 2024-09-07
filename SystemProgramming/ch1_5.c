#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern int errno;

int main() {
  char *err;

  if (access("test.txt", R_OK) == -1) {
    err = strerror(errno);
    printf("Error: %s\n", err);
    exit(1);
  }
}