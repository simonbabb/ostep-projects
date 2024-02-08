#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }
    // get the search_term
    char *search_term = argv[1];
    FILE *fp;
    if (argc > 2) {
        // open the file
        fp = fopen(argv[2], "r");
    } else {
        fp = stdin;
    }

    if (fp == NULL) {
        printf("wgrep: cannot open file\n");
        exit(1);
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    while ((nread = getline(&line, &len, fp)) != -1) {
        char *ret = strstr(line, search_term);
        if (ret) {
            printf("%s", line);
        }
    }
    exit(0);
}