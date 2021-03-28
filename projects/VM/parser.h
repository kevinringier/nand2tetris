#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>

FILE *open_stream(char *);

int has_more_commands(FILE *);

char *advance(FILE *);

int commandType(char *);

char *parse_arg_one(char *, int);

char *parse_arg_two(char *);

int mapWordtoCommand(char *);

int isArithmetic(char *);

char *parse_file_name(char *);

#endif
