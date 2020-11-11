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

int isArg2CommandType(int);

#endif
