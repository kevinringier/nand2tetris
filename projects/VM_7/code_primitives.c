#include "code_primitives.h"
#include <string.h>
#include <stdio.h>
#include "util.h"

char *newline = "\n";

C_COMPUTATION c_computation = {
    .zero = "0",
    .one = "1",
    .neg_one = "-1",
    .d = "D",
    .a = "A",
    .not_d = "!D",
    .not_a = "!A",
    .neg_d = "-D",
    .neg_a = "-A",
    .d_plus_one = "D+1",
    .a_plus_one = "A+1",
    .d_minus_one = "D-1",
    .a_minus_one = "A-1",
    .d_plus_a = "D+A",
    .d_minus_a = "D-A",
    .a_minus_d = "A-D",
    .d_and_a = "D&A",
    .d_or_a = "D|A",
    .m = "M",
    .not_m = "!M",
    .neg_m = "-M",
    .m_plus_one = "M+1",
    .m_minus_one = "M-1",
    .d_plus_m = "D+M",
    .d_minus_m = "D-M",
    .m_minus_d = "M-D",
    .d_and_m = "D&M",
    .d_or_m = "D|M"
};

C_DESTINATION c_destination = {
    .null = "null",
    .m = "M",
    .d = "D",
    .md = "MD",
    .a = "A",
    .am = "AM",
    .ad = "AD",
    .amd = "AMD",
    .dest_suffix = "=", // if dest is empty, the "=" is omitted
    .zero = "0" // always jump condition
};

C_JUMP c_jump = {
    .null = "null", // no jump
    .jgt = "JGT", // if out > 0 jump
    .jeq = "JEQ", // if out = 0 jump
    .jge = "JGE", // if out >= 0 jump
    .jlt = "JLT", // if out < 0 jump
    .jne = "JNE", // if out != 0 jump
    .jle = "JLE", // if out <= 0 jump
    .jmp = "JMP", // jump
    .jump_prefix = ";" // if jump is empty, the ";" is omitted
};

A_INSTRUCTION a_instruction = {
    .prefix = "@",
    .sp = "SP",
    .lcl = "LCL",
    .arg = "ARG",
    ._this = "THIS",
    .that = "THAT",
    .r0 = "R0",
    .r1 = "R1",
    .r2 = "R2",
    .r3 = "R3",
    .r4 = "R4",
    .r5 = "R5",
    .r6 = "R6",
    .r7 = "R7",
    .r8 = "R8",
    .r9 = "R9",
    .r10 = "R10",
    .r11 = "R11",
    .r12 = "R12",
    .r13 = "R13",
    .r14 = "R14",
    .r15 = "R15"
};

Label label_chars = {
    .label_prefix = "(",
    .label_suffix = ")"
};

void construct_dest_comp(Dest c_dest, Comp c_comp, char *dest) {
    strcat(dest, c_dest);
    strcat(dest, c_destination.dest_suffix);
    strcat(dest, c_comp);
    strcat(dest, newline);
}

void construct_dest_jump(Dest c_dest, Jump c_j, char *instruction) {
    strcat(instruction, c_dest);
    strcat(instruction, c_jump.jump_prefix);
    strcat(instruction, c_j);
    strcat(instruction, newline);
}

void construct_a_value(int value, char *dest) {
    printf("BEFORE A PREFIX: %s\n", dest);
    strcat(dest, a_instruction.prefix);
    printf("A INSTRUCTION PREFIX: %s\n", a_instruction.prefix);
    printf("CONSTRUCTING A VALUE: %s\n", dest);
    // format value and store in buffer;
    char str_val[10];
    printf("FORMAT");
    sprintf(str_val, "%d", value);

    printf("CAT FORMATtED");
    strcat(dest, str_val);
    strcat(dest, newline);
}

void construct_a_label(A_Label label, char *dest) {
    strcat(dest, a_instruction.prefix);
    strcat(dest, label);
    strcat(dest, newline);
}

void construct_label(char *label, char *instruction) {
    strcat(instruction, label_chars.label_prefix);
    strcat(instruction, label);
    strcat(instruction, label_chars.label_suffix);
    strcat(instruction, newline);
}


