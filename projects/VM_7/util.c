#include "util.h"
#include <ctype.h>
#include <string.h>

char *trimWhiteSpace(char *line) {
    char *end;

    // Trim leading space
    while(isspace((unsigned char)*line)) line++;

    if(*line == 0) {
        return line;
    } // All spaces?
      
    // Trim trailing space
    end = line + strlen(line) - 1;
    while(end > line && isspace((unsigned char)*end)) end--;

    // Write new null terminator character
    end[1] = '\0';

    return line;
}

char *trimComment(char *line) {
    size_t i;
    size_t length = strlen(line); 

    for (i = 0; i < length; i++) {
        if (isComment(line + i)) {
            line[i] = '\0';
        }
        
    }
    return line;
}

int isEmptyLine(char *line) {
    char accept[]=" \t\r\n"; /* white space characters (fgets stores \n) */
    return (strspn(line, accept) == strlen(line));
}

int isFullLineComment(char *line) {
    if (strlen(line) > 1 && isComment(line)) {
        return 1;
    }
    return 0;
}

int isComment(char *line) {
    if (line[0] == '/' && line[1] == '/') {
        return 1;
    }
    return 0;
}

int isArg2CommandType(int command) {
    int commands[] = { C_PUSH, C_POP, C_FUNCTION, C_CALL };
    size_t length = sizeof(commands) / sizeof(commands[0]);
    size_t i;

    for (i = 0; i < length; i++) {
        if (command == commands[i]) {
            return 1;
        }
    }
    return 0;
}
