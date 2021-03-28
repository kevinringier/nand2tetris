#include "util.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

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

int is_arg2_command_type(int command) {
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

int is_function(int command) {
    int function_command =  C_FUNCTION;
    if (command == function_command) {
            return 1;
    }
    
    return 0;
}

int is_call(int command) {
int function_command =  C_CALL;
    if (command == function_command) {
            return 1;
    }
    
    return 0;
}

int is_program_flow_command(int command) {
    int commands[] = { C_LABEL, C_GOTO, C_IF };
    size_t length = sizeof(commands) / sizeof(commands[0]);
    size_t i;

    for (i = 0; i < length; i++) {
        if (command == commands[i]) {
            return 1;
        }
    }
    return 0;
}

char* get_write_to_file_path(char *path) {
    // change last 
    size_t length = strlen(path);
    char *copy = calloc(length + 5, sizeof(char));

    // length of 3 for .vm extention
    strncpy(copy, path, (length - 3));
    strcat(copy, ".asm");

    return copy;
}

char *trim_file_path(char *file_path) {
    // this wasn't working when I was attempting to affect the pointer by incrementing.
    // the pointer outside caller function ptr was not incrementing.
    // however the extension trim worked, but I imagine that's because I was setting a null terminator char at the address.
    while (is_file_path(file_path)) file_path++;
    return file_path;
}

char *trim_file_extension(char *file) {
    size_t length = strlen(file);
    int i = 0;

    while (i < length) {
        if (file[i] == '.') {
            file[i] = '\0';
            return file;
        }
        i++;
    }

    return file;
}

int is_file_path(char *file_path) {
    size_t length = strlen(file_path);

    for(int i = 0; i < length; i++) {
        if (file_path[i] == '\\' || file_path[i] == '/') {
            return 1;
        }
    }
    
    return 0;
}
