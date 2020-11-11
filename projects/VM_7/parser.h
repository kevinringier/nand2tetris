#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>

FILE *openStream(char *);

int hasMoreCommands(FILE *);

char *advance(FILE *);

int commandType(char *);

char *parse_arg_one(char *, int);

char *parse_arg_two(char *);

int mapWordtoCommand(char *);

int isArithmetic(char *);

#endif
