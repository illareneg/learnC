#include <stdio.h>
#include <stdlib.h>

void normal(FILE*, FILE*);
void encountered_forwardslash(FILE*, FILE*);
void in_singleline_comment(FILE*, FILE*);
void in_multiline_comment(FILE*, FILE*);
void in_string(FILE*, FILE*);
void in_char(FILE*, FILE*);

void normal(FILE *in, FILE *out)
{
    char c;

    while ((c = fgetc(in)) != EOF) {
        if (c == '/')
            encountered_forwardslash(in, out);
        else {
            fputc(c, out);
            if (c == '\"')
                in_string(in, out);
            if (c == '\'')
                in_char(in, out);
        }
    }
}

void encountered_forwardslash(FILE *in, FILE *out)
{
    char c = fgetc(in);
   
    if (c == '/')
        in_singleline_comment(in, out);
    else if (c == '*')
        in_multiline_comment(in, out);
    else {
        fputc('/', out);
        if (c != EOF)
            fputc(c, out);
        normal(in, out);
    }
}

void in_singleline_comment(FILE *in, FILE *out)
{
    char c, prev_c = EOF;

    while ((c = fgetc(in)) != EOF) {
        if (c == '\n' && prev_c != '\\') {
            fputc('\n', out);
            break;
        }    
        prev_c = c;
    }
    normal(in, out);
}

void in_multiline_comment(FILE *in, FILE *out)
{
    char c, prev_c = EOF;

    while ((c = fgetc(in)) != EOF && (c != '/' || prev_c != '*')) 
        prev_c = c;
    normal(in, out);
}

void in_string(FILE *in, FILE *out)
{
    char c, prev_c = EOF;
    
    while ((c = fgetc(in)) != EOF) {
        fputc(c, out);
        if (c == '\"' && prev_c != '\\')
             break;
        prev_c = c;
    }
    normal(in, out);
}

void in_char(FILE *in, FILE *out)
{
    char c, prev_c = EOF;

    while ((c = fgetc(in)) != EOF) {
        fputc(c, out);
        if (c == '\'' && prev_c != '\\')
           break;
        prev_c = c;
    }
    normal(in, out);
}

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
    normal(in, out);
    fclose(in);
    fclose(out);
    exit(exit_val);
}
