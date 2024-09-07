#include <stdio.h>

extern int addnum(int a, int b);

int main() {
  int sum;
  sum = addnum(1, 5);
  printf("sum=%d\n", sum);
}