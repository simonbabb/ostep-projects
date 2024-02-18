#include <stdio.h>
#include <stdlib.h>

int BUFF_SIZE = 100;

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("wzip: file1 [file2 ...]\n");
    exit(1);
  }

  char ch = '\0';
  int count = 0;
  char prev = '\n';
  for (int i = 1; i < argc; i++) {
    // open the file
    FILE *fp = fopen(argv[i], "r");
    if (fp == NULL) {
      exit(1);
    }

    while ((ch = (char)fgetc(fp)) != EOF) {
      if (ch == prev) {
        count++;
        prev = ch;
      } else {
        if (count > 0) {
          // printf("%d", count);
          // printf("%c", prev);
          fwrite(&count, sizeof count, 1, stdout);
          fwrite(&prev, sizeof prev, 1, stdout);
        }
        count = 1;
        prev = ch;
      }
    }
  }
  fwrite(&count, sizeof count, 1, stdout);
  fwrite(&prev, sizeof prev, 1, stdout);
}
