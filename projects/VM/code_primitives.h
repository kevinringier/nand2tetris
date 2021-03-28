#ifndef CODE_PRIMITIVES_H
#define CODE_PRIMITIVES_H

typedef char * Comp;

typedef struct {
    Comp zero;
    Comp one;
    Comp neg_one;
    Comp d;
    Comp a;
    Comp not_d;
    Comp not_a;
    Comp neg_d;
    Comp neg_a;
    Comp d_plus_one;
    Comp a_plus_one;
    Comp d_minus_one;
    Comp a_minus_one;
    Comp d_plus_a;
    Comp d_minus_a;
    Comp a_minus_d;
    Comp d_and_a;
    Comp d_or_a;
    Comp m;
    Comp not_m;
    Comp neg_m;
    Comp m_plus_one;
    Comp m_minus_one;
    Comp d_plus_m;
    Comp d_minus_m;
    Comp m_minus_d;
    Comp d_and_m;
    Comp d_or_m;
} C_COMPUTATION;

extern C_COMPUTATION c_computation;

typedef char * Dest;

typedef struct {
    Dest null;
    Dest m;
    Dest d;
    Dest md;
    Dest a;
    Dest am;
    Dest ad;
    Dest amd;
    Dest dest_suffix;
    Dest zero;
} C_DESTINATION;

extern C_DESTINATION c_destination;

typedef char * Jump;

typedef struct {
    Jump null;
    Jump jgt;
    Jump jeq;
    Jump jge;
    Jump jlt;
    Jump jne;
    Jump jle;
    Jump jmp;
    Jump jump_prefix;
} C_JUMP;

extern C_JUMP c_jump;

typedef char * A_Setter;
typedef char * A_Label;

typedef struct {
    A_Setter prefix;
    A_Label sp;
    A_Label lcl;
    A_Label arg;
    A_Label _this;
    A_Label that;
    A_Label r0;
    A_Label r1;
    A_Label r2;
    A_Label r3;
    A_Label r4;
    A_Label r5;
    A_Label r6;
    A_Label r7;
    A_Label r8;
    A_Label r9;
    A_Label r10;
    A_Label r11;
    A_Label r12;
    A_Label r13;
    A_Label r14;
    A_Label r15;
} A_INSTRUCTION;

extern A_INSTRUCTION a_instruction;

typedef char * LabelChar;

typedef struct {
    LabelChar label_prefix;
    LabelChar label_suffix;
    LabelChar label_function_infix;
} Label;

extern Label label_chars;

void construct_dest_comp(Dest, Comp, char *);

void construct_dest_jump(Dest, Jump, char *);

void construct_a_value(int, char *);

void construct_a_label(A_Label, char *);

void construct_label(char *, char *);

void construct_static_label(char *, int, char *);

#endif
