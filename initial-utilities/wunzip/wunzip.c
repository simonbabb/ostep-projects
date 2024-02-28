#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("wunzip: file1 [file2 ...]\n");
    exit(1);
  }

  int count;
  char ch;
  for (int i = 1; i < argc; i++) {
    // open the file
    FILE *fp = fopen(argv[i], "r");
    if (fp == NULL) {
      exit(1);
    }
    while (fread(&count, sizeof count, 1, fp) > 0 &&
           fread(&ch, sizeof ch, 1, fp) > 0) {
      while (count > 0) {
        fwrite(&ch, sizeof ch, 1, stdout);
        count--;
      }
    }
  }
}