#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int main() {
  char *buffer;
  size_t fsize;

  char srcFileName[100];
  char destFileName[100];
  strcpy(srcFileName, "test.txt");
  strcpy(destFileName, "test_copy.txt");

  FILE *srcFile = fopen(srcFileName, "rb");
  FILE *destFile = fopen(destFileName, "wb");

  fseek(srcFile, 0, SEEK_END);
  fsize = ftell(srcFile);
  printf("File size: %zu bytes\n", fsize);

  buffer = (char *)malloc(fsize);
  memset(buffer, 0, fsize);

  fseek(srcFile, 0, SEEK_SET); // move to the beginning of the file
  fread(buffer, fsize, 1, srcFile); // read the file
  fwrite(buffer, fsize, 1, destFile); // write the file

  fclose(srcFile);
  fclose(destFile);
  free(buffer);
  printf("File copied successfully\n");
}