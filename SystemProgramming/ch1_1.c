#include <errno.h>
#include <stdio.h>
#include <unistd.h>

extern int errno;

int main() {
  if (access("test.txt", F_OK) == -1) {
    printf("errno=%d\n", errno);
    perror("test.txt");
  } else {
    printf("test.txt exists\n");
  }
}
