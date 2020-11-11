#include "parser.h"
#include "util.h"
#include <stdlib.h>
#include <string.h>

// TODO: is this good practice for import syntax?

FILE *openStream(char *filePath) {
    return fopen(filePath, "r");
}

int hasMoreCommands(FILE *fptr) {
   int c = getc(fptr);

   return c == EOF ? 0 : ungetc(c, fptr);
}

char *advance(FILE *fptr) {
    char *line = calloc(1024, sizeof(char));

    do {
        fgets(line, 1024, fptr); // TODO: here too
    } while (isEmptyLine(line) || isFullLineComment(line));

    trimComment(line);
    trimWhiteSpace(line);

    return line;
}

int commandType(char *line) {
    // copy argument to avoid mutating original value
    char copy[strlen(line)];
    strcpy(copy, line);
    const char *delimiter = " ";
    char *token = strtok(copy, delimiter);

    return mapWordtoCommand(token);
}

// should not be called if current command is C_RETURN
char *parse_arg_one(char *line, int commandType) {
    // TODO: refactor this, caller shouldn't have to know to free value
    size_t length = strlen(line);
    char copy[length];
    strcpy(copy, line);
    const char *delimiter = " ";
    char *token;
    token = strtok(copy, delimiter);

    if (commandType != C_ARITHMETIC) {
        // every call with NULL uses saved user_input value and returns next string
        token = strtok(NULL, delimiter);
    }

    char *retval = calloc(1024, sizeof(char));
    strcpy(retval, token); 

    return retval;
}

char *parse_arg_two(char *line) {
    // TODO: refactor this, caller shouldn't have to know to free value
    size_t length = strlen(line);
    char copy[length];
    strcpy(copy, line);
    const char *delimiter = " ";
    char *token;

    // better way to do this?
    token = strtok(copy, delimiter);
    token = strtok(NULL, delimiter);
    token = strtok(NULL, delimiter);
    
    char *retval = calloc(1024, sizeof(char));
    strcpy(retval, token); 

    return retval;
}

int mapWordtoCommand(char *word) {
    int commandType;

    if (strcmp(word, "push") == 0) {
        commandType = C_PUSH;
    } else if (strcmp(word, "funciton") == 0) {
        commandType = C_FUNCTION;
    } else if (strcmp(word, "label") == 0) {
        commandType = C_LABEL;
    } else if (strcmp(word, "pop") == 0) {
        commandType = C_POP;
    } else if (strcmp(word, "goto") == 0) {
        commandType = C_GOTO;
    } else if (strcmp(word, "return") == 0) {
        commandType = C_RETURN;
    } else if (strcmp(word, "if-goto") == 0) {
        commandType = C_IF;
    } else if (strcmp(word, "call") == 0) {
        commandType = C_CALL;
    } else if (isArithmetic(word)) {
        commandType = C_ARITHMETIC;
    } else {
        commandType = C_INVALID;
    }

    return commandType;
}

int isArithmetic(char *word) {
    char *arithmeticCommands[9] = {"add", "sub", "neg", "eq", "gt", "lt", "and", "or", "not"};
    size_t length = sizeof(arithmeticCommands) / sizeof(arithmeticCommands[0]);
    size_t i;

    for (i = 0; i < length; i++) {
        if (strcmp(word, arithmeticCommands[i])) {
            return 1;
        }
    }
    return 0;
}


