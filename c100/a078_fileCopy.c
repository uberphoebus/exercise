#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  char srcFilename[100];
  char destFilename[100];
  strcpy(srcFilename, "text.txt");
  strcpy(destFilename, "text_copy.txt");
  FILE *ifp;
  FILE *ofp;
  ifp = fopen(srcFilename, "r");
  ofp = fopen(destFilename, "w");

  // copy the file by line(fgets, fputs)
  char buffer[100];
  int lineCnt = 0;
  while (fgets(buffer, 100, ifp) != NULL) {
    fputs(buffer, ofp);
    printf("lineCnt %d : %s", lineCnt++, buffer);
  }
  fclose(ifp);
  fclose(ofp);
}