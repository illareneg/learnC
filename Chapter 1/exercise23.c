#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int exit_val = EXIT_SUCCESS;
    FILE *in, *out;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s [input file] [output file]\n", argv[0]);
        exit_val = EXIT_FAILURE;
    }
    if (exit_val == EXIT_SUCCESS && !(in = fopen(argv[1], "r"))) {
        fprintf(stderr, "Error opening %s for read.\n", argv[1]);
        exit_val = EXIT_FAILURE;
    }
    if (exit_val == EXIT_SUCCESS && !(out = fopen(argv[2], "w"))) {
        fprintf(stderr, "Error opening %s for write.\n", argv[2]);
        exit_val = EXIT_FAILURE;
    }
    if (exit_val == EXIT_SUCCESS) {
        char c, prev_c;
        while ((c = fgetc(in)) != EOF) {
            if (c == '/') {
                char c = fgetc(in);
                if (c == '/') {
                    prev_c = EOF;
                    while ((c = fgetc(in)) != EOF) {
                        if (c == '\n' && prev_c != '\\') {
                            fputc('\n', out);
                            break;
                        }    
                        prev_c = c;
                    }
                }
                else if (c == '*') {
                    prev_c = EOF;
                    while ((c = fgetc(in)) != EOF && (c != '/' || prev_c != '*')) 
                        prev_c = c;
                }
                else {
                    fputc('/', out);
                    if (c != EOF)
                        fputc(c, out);
                }
            }
            else {
                fputc(c, out);
                if (c == '\"') {
                    prev_c = EOF;
                    while ((c = fgetc(in)) != EOF) {
                        fputc(c, out);
                        if (c == '\"' && prev_c != '\\')
                            break;
                        prev_c = c;
                    }
                }
                else if (c == '\'') {
                    prev_c = EOF;
                    while ((c = fgetc(in)) != EOF) {
                        fputc(c, out);
                        if (c == '\'' && prev_c != '\\')
                            break;
                        prev_c = c;
                    }
                }
            }
        }
        fclose(in);
        fclose(out);
    }
    exit(exit_val);
}
