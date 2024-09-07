#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int n;
  extern char *optarg;
  extern int optind;

  printf("Current optind: %d\n", optind);
  while ((n = getopt(argc, argv, "abc:")) != -1) {
    switch (n) {
    case 'a':
      printf("option: a\n");
      break;
    case 'b':
      printf("option: b\n");
      break;
    case 'c':
      printf("option: c, value: %s\n", optarg);
      break;
    }
    printf("Next optind: %d\n", optind);
  }
}