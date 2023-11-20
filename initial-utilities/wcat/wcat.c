#include <stdio.h>
#include <stdlib.h>
int BUFF_SIZE = 100;
int main(int argc, char *argv[]) {
    // return 0 if there are no args
    if (argc == 1) {
        return 0;
    } 
    // loop through all arguments
    int i;
    for (i = 1; i < argc; i++) {
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf("wcat: cannot open file\n");
            exit(1);
        }
        // print out the file contents
        char *buffer = malloc(BUFF_SIZE);
        char *s = fgets(buffer, BUFF_SIZE, fp);
        while (s != NULL) {
            printf("%s", buffer);
            s = fgets(buffer, BUFF_SIZE, fp);
        }
    } 
    return 0;
}