#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Simplified solution

int main(int argc, char *argv[])
{
    int exit_val = EXIT_SUCCESS;
    FILE *script;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s [script]\n", argv[0]);
        exit_val = EXIT_FAILURE;
    }
    if (exit_val == EXIT_SUCCESS && (script = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Error opening %s\n", argv[1]);
        exit_val = EXIT_FAILURE;
    }
    if (exit_val == EXIT_SUCCESS) {
        int pos = 0, line = 1;
        char c, prev_c;
        while ((c = fgetc(script)) != EOF) {
            ++pos;
            if (c == '(') {
                while ((c = fgetc(script)) != EOF) {
                    ++pos;
                    if (c == ')' || c == '(')
                        break;
                    else if (c == '\n')
                        ++line;
                }
                if (c == '(') {
                    fprintf(stderr, "Open parenthesis after open parenthesis, line %d position %s\n", line, pos);
                    break;
                }
                else if (c == 'EOF')
                    fprintf(stderr, "Missing closing parenthesis\n");
            }
            else if (c == '[') {
                while ((c = fgetc(script)) != EOF) {
                    ++pos;
                    if (c == ']' || c == '[')
                        break;
                    else if (c == '\n')
                        ++line;
                }
                if (c == '[') {
                    fprintf(stderr, "Open bracket after open bracket, line %d position %s\n", line, pos);
                    break;
                }
                else if (c == 'EOF')
                    fprintf(stderr, "Missing closing bracket\n");
            }
            else if (c == '{') {
                while ((c = fgetc(script)) != EOF) {
                    ++pos;
                    if (c == '}' || c == '{')
                        break;
                    else if (c == '\n')
                        ++line;
                }
                if (c == '{') {
                    fprintf(stderr, "Open brace after open brace, line %d position %s\n", line, pos);
                    break;
                }
                else if (c == 'EOF')
                    fprintf(stderr, "Missing closing brace\n");
            }
            else if (c == '\'') {
                while ((c = fgetc(script)) != EOF) {
                    ++pos;
                    if (c == '\'')
                        break;
                    else if (c == '\n')
                        ++line;
                }
                if (c == EOF)
                    fprintf(stderr, "Missing single quote\n");
            }
            else if (c == '\"') {
                while ((c = fgetc(script)) != EOF) {
                    ++pos;
                    if (c == '\"')
                        break;
                    else if (c == '\n')
                        ++line;
                }
                if (c == EOF)
                    fprintf(stderr, "Missing double quote\n");
            }
            else if (c == '/') {
                prev_c = EOF;
                if ((c = fgetc(script)) != EOF) {
                    ++pos;
                    if (c == '/')
                        while ((c = fgetc(script)) != EOF) {
                            ++pos;
                            if (c == '\n' && prev_c != '\') {
                                ++line;
                                break;
                            }
                            prev_c = c;
                        }
                    else if (c == '*') {
                        while ((c = fgetc(script)) != EOF) {
                            ++pos;
                            if (c == '/' && prev_c == '*')
                                break;
                            else if (c == '\n')
                                ++line;
                            prev_c = c;
                        }
                        if (c == EOF)
                            fprintf(stderr, "Missing */\n"); 
                    }
                }
            }
            else if (c == ')') {
                fprintf(stderr, "Close parenthesis before open parenthesis, line %d position %d\n", line, pos);
                break;
            }
            else if (c == ']') {
                fprintf(stderr, "Close bracket before open bracket, line %d position %d\n", line, pos);
                break;
            }
            else if (c == '}') {
                fprintf(stderr, "Close brace before open brace, line %d position %d\n", line, pos);
                break;
            }
            else if (c == '\n')
                ++line;
        }
        fclose(script);
    }
    exit(exit_val);
}
