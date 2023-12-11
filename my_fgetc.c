#include "simple_shell.h"

int custom_fgetc(FILE* stream) {
    if (stream == NULL) {
        return EOF;
    }

    int c = getc(stream);

    if (c == EOF) {
        if (feof(stream)) {

            printf("End of file reached.\n");
        } else if (ferror(stream)) {
            perror("Error reading from file");
        }
    }

    return c;
}
