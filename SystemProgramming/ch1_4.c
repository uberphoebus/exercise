#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  if (access("test.txt", R_OK) == -1) {
    perror("test.txt");
    exit(1);
  }
}