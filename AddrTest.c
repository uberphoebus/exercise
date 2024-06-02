#include <stdio.h>

typedef struct stA {
  int num1;
  int num2;
} stA;

typedef struct stB {
  float float1;
  float float2;
} stB;

void func1() {
  stA stA_local;
  stB stB_local;
  stA_local.num1 = 1254324;
  stB_local.float2 = 3.141592;
  printf("func1 stA_local: %p, stB_local: %p\n", &stA_local, &stB_local);
}

void func2() {
  stA stA_local;
  stB stB_local;
  printf("func2 stA_local: %p, stB_local: %p\n", &stA_local, &stB_local);
  printf("func2 stA_local.num1 = %d\n", stA_local.num1);
  printf("func2 stB_local.float2 = %f\n", stB_local.float2);
}

int main() {
  func1();
  func2();
  return 0;
}