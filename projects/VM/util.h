#ifndef UTIL_H
#define UTIL_H

typedef struct VMContext {
    int SP;
    int LCL;
    int ARG;
    int THIS;
    int THAT;
} VMContext;

void incrementSP(VMContext *);

void decrementSP(VMContext *);

enum {C_INVALID, C_ARITHMETIC, C_PUSH, C_POP, C_LABEL, C_GOTO, C_IF, C_FUNCTION, C_RETURN, C_CALL};

char *trimWhiteSpace(char *);

char *trimComment(char *);

int isEmptyLine(char *);

int isFullLineComment(char *);

int isComment(char *);

int is_arg2_command_type(int);

int is_function(int);

int is_call(int);

int is_program_flow_command(int);

char *get_write_to_file_path(char *);

char *trim_file_path(char *);

char *trim_file_extension(char *);

int is_file_path(char *);

#endif
