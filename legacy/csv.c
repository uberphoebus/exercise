#include <stdio.h>

int main() {
  char s1[] = "abcdef";

  s1[0] = 'X';

  printf("%s\n", s1); // Xbcdef

  char *s2 = "abcdef";

  // s2[0] = 'X'; // error

  s2++;

  printf("%s\n", s2); // abcdef

  return 0;
}