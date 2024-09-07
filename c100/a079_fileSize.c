#include <stdio.h>

int main() {
  char fileName[100];
  strcpy(fileName, "test.txt");
  FILE *fp = fopen(fileName, "r");

  int fsize;
  int fpos;

  fseek(fp, 0, SEEK_END); // move to the end of the file
  fsize = ftell(fp); // get the current position of the file pointer
  printf("File size: %d bytes\n", fsize);

  fseek(fp, 0, SEEK_SET); // move to the beginning of the file
  fpos = ftell(fp); // get the current position of the file pointer
  printf("File position: %d bytes\n", fpos);

  fseek(fp, 0, SEEK_END);
  fseek(fp, -10, SEEK_CUR); // move 10 bytes back from the current position
  fpos = ftell(fp); // get the current position of the file pointer
  printf("File position: %d bytes\n", fpos);

  fseek(fp, 10, SEEK_END); // move 10 bytes from the end of the file
  fpos = ftell(fp); // get the current position of the file pointer
  printf("File position: %d bytes\n", fpos);

  fclose(fp);
}