#ifndef CODE_H
#define CODE_H

#include <stdio.h>
#include "util.h"
#include "code_primitives.h"

FILE *open_write_stream(char *);

void initialize_memory_addresses(char *);

void init_memory(int address, A_Label, char *);

void initialize_function_labels(char *);

void create_app_start_label(char *);

void jump_to_app_start(char *);

void infinite_loop(char *);

void write_arithmetic(char *, char *);

void arithmetic_add(char *);

void arithmetic_subtract(char *);

void arithmetic_negate(char *);

void arithmetic_equality(char *);

void arithmetic_greater_than(char *);

void arithmetic_less_than(char *);

void arithmetic_bitwise_and(char *);

void arithmetic_bitwise_or(char *);

void arithmetic_bitwise_not(char *);

void generate_return_address_and_jump_to_label(char *, char *);

void write_value_to_segment(char *, int, char *, char *);

void write_equality_labels(char *);

void write_greater_than_labels(char *);

void write_less_than_labels(char *);

void write_push_pop(int, char *, int, char *, char *);

void close_write(FILE *);

void extract_segment_value(char *, int, char *, char *);

void extract_constant_segment(int, char *);

void push_d_register_to_stack(char *);

void increment_stack_pointer(char *);

void decrement_stack_pointer(char *);

void writeInit(char *);

void writeLabel(char *, char *);

void writeGoto(char *, char *);

void writeIf(char *, char *);

void write_call(char *, int, char *);

char *generate_function_return(char *);

void write_return(char *);

void write_function(char *, int, char *);

void write_program_flow(int, char *, char *);

void write_init();

void write_static_variable(char *, int, char *);

#endif
