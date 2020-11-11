#include "code.h"
#include "util.h"
#include "code_primitives.h"
#include <string.h>
#include <stdlib.h>

FILE *open_write_stream(char *fileName) {
    return fopen(fileName, "w");
}

void close_write(FILE *fptr) {
    fclose(fptr);
}

void write_arithmetic(char *command, char *instruction) {
    if (strcmp(command, "add") == 0) {
        arithmetic_add(instruction);
    } else if (strcmp(command, "sub") == 0) {
        arithmetic_subtract(instruction);
    } else if (strcmp(command, "neg") == 0) {
        arithmetic_negate(instruction);
    } else if (strcmp(command, "eq") == 0) {
        arithmetic_equality(instruction);
    } else if (strcmp(command, "gt") == 0) {
        arithmetic_greater_than(instruction);
    } else if (strcmp(command, "lt") == 0) {
        arithmetic_less_than(instruction);
    } else if (strcmp(command, "and") == 0) {
        arithmetic_bitwise_and(instruction);
    } else if (strcmp(command, "or") == 0) {
        arithmetic_bitwise_or(instruction);
    } else if (strcmp(command, "not") == 0) {
        arithmetic_bitwise_not(instruction);
    }
}

void initialize_memory_addresses(char *instruction) {
    init_memory(256, a_instruction.sp, instruction);
    init_memory(300, a_instruction.lcl, instruction);
    init_memory(400, a_instruction.arg, instruction);
    init_memory(3000, a_instruction._this, instruction);
    init_memory(3010, a_instruction.that, instruction);
}

void init_memory(int address, A_Label label, char *instruction) {
    construct_a_value(address, instruction);
    construct_dest_comp(c_destination.d, c_computation.a, instruction);
    construct_a_label(label, instruction);
    construct_dest_comp(c_destination.m, c_computation.d, instruction);
}

void initialize_function_labels(char *instruction) {
    write_equality_labels(instruction);
    write_greater_than_labels(instruction);
    write_less_than_labels(instruction);
}

void create_app_start_label(char *instruction) {
    construct_label("APP_START", instruction);
}

void jump_to_app_start(char *instruction) {
    construct_a_label("APP_START", instruction);
    construct_dest_jump(c_destination.zero, c_jump.jmp, instruction);
}

void infinite_loop(char *instruction) {

}

void arithmetic_add(char *instruction) {
    decrement_stack_pointer(instruction);
    construct_dest_comp(c_destination.a, c_computation.m, instruction);
    construct_dest_comp(c_destination.d, c_computation.m, instruction);
    decrement_stack_pointer(instruction);
    construct_a_label(a_instruction.sp, instruction);
    construct_dest_comp(c_destination.a, c_computation.m, instruction);
    construct_dest_comp(c_destination.m, c_computation.d_plus_m, instruction);
    increment_stack_pointer(instruction);
}

void arithmetic_subtract(char *instruction) {
    decrement_stack_pointer(instruction);
    construct_dest_comp(c_destination.a, c_computation.m, instruction);
    construct_dest_comp(c_destination.d, c_computation.m, instruction);
    decrement_stack_pointer(instruction);
    construct_a_label(a_instruction.sp, instruction);
    construct_dest_comp(c_destination.a, c_computation.m, instruction);
    construct_dest_comp(c_destination.m, c_computation.m_minus_d, instruction);
    increment_stack_pointer(instruction);
}

void arithmetic_negate(char *instruction) {
    decrement_stack_pointer(instruction);
    construct_dest_comp(c_destination.a, c_computation.m, instruction);
    construct_dest_comp(c_destination.m, c_computation.neg_m, instruction);
    increment_stack_pointer(instruction);
}

void arithmetic_equality(char *instruction) {
    decrement_stack_pointer(instruction);
    construct_dest_comp(c_destination.a, c_computation.m, instruction);
    construct_dest_comp(c_destination.d, c_computation.m, instruction);
    decrement_stack_pointer(instruction);
    construct_a_label(a_instruction.sp, instruction);
    construct_dest_comp(c_destination.a, c_computation.m, instruction);
    construct_dest_comp(c_destination.m, c_computation.d_minus_m, instruction);
    generate_return_address("EQUALITY_TRUE", instruction);
}

void arithmetic_greater_than(char *instruction) {
    decrement_stack_pointer(instruction);
    construct_dest_comp(c_destination.a, c_computation.m, instruction);
    construct_dest_comp(c_destination.d, c_computation.m, instruction);
    decrement_stack_pointer(instruction);
    construct_a_label(a_instruction.sp, instruction);
    construct_dest_comp(c_destination.a, c_computation.m, instruction);
    construct_dest_comp(c_destination.m, c_computation.m_minus_d, instruction);
    generate_return_address("GREATER_FALSE", instruction);
}

void arithmetic_less_than(char *instruction) {
    decrement_stack_pointer(instruction);
    construct_dest_comp(c_destination.a, c_computation.m, instruction);
    construct_dest_comp(c_destination.d, c_computation.m, instruction);
    decrement_stack_pointer(instruction);
    construct_a_label(a_instruction.sp, instruction);
    construct_dest_comp(c_destination.a, c_computation.m, instruction);
    construct_dest_comp(c_destination.m, c_computation.d_minus_m, instruction);
    generate_return_address("LESS_TRUE", instruction);
}

void arithmetic_bitwise_and(char *instruction) {
    decrement_stack_pointer(instruction);
    construct_dest_comp(c_destination.a, c_computation.m, instruction);
    construct_dest_comp(c_destination.d, c_computation.m, instruction);
    decrement_stack_pointer(instruction);
    construct_a_label(a_instruction.sp, instruction);
    construct_dest_comp(c_destination.a, c_computation.m, instruction);
    construct_dest_comp(c_destination.m, c_computation.d_and_m, instruction);
    increment_stack_pointer(instruction);
}

void arithmetic_bitwise_or(char *instruction) {
    decrement_stack_pointer(instruction);
    construct_dest_comp(c_destination.a, c_computation.m, instruction);
    construct_dest_comp(c_destination.d, c_computation.m, instruction);
    decrement_stack_pointer(instruction);
    construct_a_label(a_instruction.sp, instruction);
    construct_dest_comp(c_destination.a, c_computation.m, instruction);
    construct_dest_comp(c_destination.m, c_computation.d_or_m, instruction);
    increment_stack_pointer(instruction);
}

void arithmetic_bitwise_not(char *instruction) {
    decrement_stack_pointer(instruction);
    construct_dest_comp(c_destination.a, c_computation.m, instruction);
    construct_dest_comp(c_destination.m, c_computation.not_m, instruction);
    increment_stack_pointer(instruction);
}

void generate_return_address(char *jump_to_label, char *instruction) {
    static int return_address = 0;
    char return_address_label[64];
    strcpy(return_address_label, "RET_ADDRESS_CALL");
    char current_address_formatted[64];
    sprintf(current_address_formatted, "%d", return_address);
    strcat(return_address_label, current_address_formatted);
    construct_a_label(return_address_label, instruction);
    construct_dest_comp(c_destination.d, c_computation.a, instruction);
    construct_a_label(jump_to_label, instruction);
    construct_dest_jump(c_destination.zero, c_jump.jmp, instruction);
    construct_label(return_address_label, instruction);
    return_address++;
}

void write_equality_labels(char *instruction) {
    construct_label("EQUALITY_TRUE", instruction);
    construct_a_label(a_instruction.r13, instruction);
    construct_dest_comp(c_destination.m, c_computation.d, instruction);
    construct_a_label(a_instruction.sp, instruction);
    construct_dest_comp(c_destination.a, c_computation.m, instruction);
    construct_dest_comp(c_destination.d, c_computation.m, instruction);
    construct_a_label("EQUALITY_FALSE", instruction);
    construct_dest_jump(c_destination.d, c_jump.jne, instruction);
    construct_a_label(a_instruction.sp, instruction);
    construct_dest_comp(c_destination.a, c_computation.m, instruction);
    construct_dest_comp(c_destination.m, c_computation.neg_one, instruction);
    increment_stack_pointer(instruction);
    construct_a_label(a_instruction.r13, instruction);
    construct_dest_comp(c_destination.a, c_computation.m, instruction);
    construct_dest_jump(c_destination.zero, c_jump.jmp, instruction);
    construct_label("EQUALITY_FALSE", instruction);
    construct_a_label(a_instruction.sp, instruction);
    construct_dest_comp(c_destination.a, c_computation.m, instruction);
    construct_dest_comp(c_destination.m, c_computation.zero, instruction);
    increment_stack_pointer(instruction);
    construct_a_label(a_instruction.r13, instruction);
    construct_dest_comp(c_destination.a, c_computation.m, instruction);
    construct_dest_jump(c_destination.zero, c_jump.jmp, instruction);
}

void write_greater_than_labels(char *instruction) {
    construct_label("GREATER_FALSE", instruction);
    construct_a_label(a_instruction.r13, instruction);
    construct_dest_comp(c_destination.m, c_computation.d, instruction);
    construct_a_label(a_instruction.sp, instruction);
    construct_dest_comp(c_destination.a, c_computation.m, instruction);
    construct_dest_comp(c_destination.d, c_computation.m, instruction);
    construct_a_label("GREATER_TRUE", instruction);
    construct_dest_jump(c_destination.d, c_jump.jgt, instruction);
    construct_a_label(a_instruction.sp, instruction);
    construct_dest_comp(c_destination.a, c_computation.m, instruction);
    construct_dest_comp(c_destination.m, c_computation.zero, instruction);
    increment_stack_pointer(instruction);
    construct_a_label(a_instruction.r13, instruction);
    construct_dest_comp(c_destination.a, c_computation.m, instruction);
    construct_dest_jump(c_destination.zero, c_jump.jmp, instruction);
    construct_label("GREATER_TRUE", instruction);
    construct_a_label(a_instruction.sp, instruction);
    construct_dest_comp(c_destination.a, c_computation.m, instruction);
    construct_dest_comp(c_destination.m, c_computation.neg_one, instruction);
    increment_stack_pointer(instruction);
    construct_a_label(a_instruction.r13, instruction);
    construct_dest_comp(c_destination.a, c_computation.m, instruction);
    construct_dest_jump(c_destination.zero, c_jump.jmp, instruction);
}

void write_less_than_labels(char *instruction) {
    construct_label("LESS_TRUE", instruction);
    construct_a_label(a_instruction.r13, instruction);
    construct_dest_comp(c_destination.m, c_computation.d, instruction);
    construct_a_label(a_instruction.sp, instruction);
    construct_dest_comp(c_destination.a, c_computation.m, instruction);
    construct_dest_comp(c_destination.d, c_computation.m, instruction);
    construct_a_label("LESS_FALSE", instruction);
    construct_dest_jump(c_destination.d, c_jump.jle, instruction);
    construct_a_label(a_instruction.sp, instruction);
    construct_dest_comp(c_destination.a, c_computation.m, instruction);
    construct_dest_comp(c_destination.m, c_computation.neg_one, instruction);
    increment_stack_pointer(instruction);
    construct_a_label(a_instruction.r13, instruction);
    construct_dest_comp(c_destination.a, c_computation.m, instruction);
    construct_dest_jump(c_destination.zero, c_jump.jmp, instruction);
    construct_label("LESS_FALSE", instruction);
    construct_a_label(a_instruction.sp, instruction);
    construct_dest_comp(c_destination.a, c_computation.m, instruction);
    construct_dest_comp(c_destination.m, c_computation.zero, instruction);
    increment_stack_pointer(instruction);
    construct_a_label(a_instruction.r13, instruction);
    construct_dest_comp(c_destination.a, c_computation.m, instruction);
    construct_dest_jump(c_destination.zero, c_jump.jmp, instruction);
}

void write_push_pop(int command, char *segment, int index, char *instruction) {
    if (command == C_PUSH) {
        extract_segment_value(segment, index, instruction);
        push_d_register_to_stack(instruction);
        increment_stack_pointer(instruction);
    } else if (command == C_POP) {
        // write stack to d
        decrement_stack_pointer(instruction);
        construct_a_label(a_instruction.sp, instruction);
        construct_dest_comp(c_destination.a, c_computation.m, instruction);
        construct_dest_comp(c_destination.d, c_computation.m, instruction);
        // write d to temporary memory
        construct_a_label(a_instruction.r13, instruction);
        construct_dest_comp(c_destination.m, c_computation.d, instruction);
        
        write_value_to_segment(segment, index, instruction);
    }
}

void extract_segment_value(char *segment, int index, char *instruction) {
    if (strcmp(segment, "constant") == 0) {
        extract_constant_segment(index, instruction);
    } else {
      // store index in d
      construct_a_value(index, instruction);
      construct_dest_comp(c_destination.d, c_computation.a, instruction);

      if (strcmp(segment, "local") == 0) {
          construct_a_label(a_instruction.lcl, instruction);
          construct_dest_comp(c_destination.a, c_computation.m, instruction);
      } else if (strcmp(segment, "argument") == 0) {
          construct_a_label(a_instruction.arg, instruction);
          construct_dest_comp(c_destination.a, c_computation.m, instruction);
      } else if (strcmp(segment, "this") == 0) {
          construct_a_label(a_instruction._this, instruction);
          construct_dest_comp(c_destination.a, c_computation.m, instruction);
      } else if (strcmp(segment, "that") == 0) {
          construct_a_label(a_instruction.that, instruction);
          construct_dest_comp(c_destination.a, c_computation.m, instruction);
      } else if (strcmp(segment, "pointer") == 0) {
          construct_a_label(a_instruction.r3, instruction);
      } else if (strcmp(segment, "temp") == 0) {
          construct_a_label(a_instruction.r5, instruction);
      } else if (strcmp(segment, "static") == 0) {
        construct_a_value(16, instruction);
      }

      // add index
      construct_dest_comp(c_destination.a, c_computation.d_plus_a, instruction);

      // write pointed to value to d
      construct_dest_comp(c_destination.d, c_computation.m, instruction);

      // write d to stack
      construct_a_label(a_instruction.sp, instruction);
      construct_dest_comp(c_destination.a, c_computation.m, instruction);
      construct_dest_comp(c_destination.m, c_computation.d, instruction);
    }
}

void write_value_to_segment(char *segment, int index, char  *instruction) {
    // assumes value to write is stored in r13 (temporary storage)

    // store index in d
    construct_a_value(index, instruction);
    construct_dest_comp(c_destination.d, c_computation.a, instruction);

    if (strcmp(segment, "local") == 0) {
        construct_a_label(a_instruction.lcl, instruction);
        construct_dest_comp(c_destination.a, c_computation.m, instruction);
    } else if (strcmp(segment, "argument") == 0) {
        construct_a_label(a_instruction.arg, instruction);
        construct_dest_comp(c_destination.a, c_computation.m, instruction);
    } else if (strcmp(segment, "this") == 0) {
        construct_a_label(a_instruction._this, instruction);
        construct_dest_comp(c_destination.a, c_computation.m, instruction);
    } else if (strcmp(segment, "that") == 0) {
        construct_a_label(a_instruction.that, instruction);
        construct_dest_comp(c_destination.a, c_computation.m, instruction);
    } else if (strcmp(segment, "pointer") == 0) {
        construct_a_label(a_instruction.r3, instruction);
    } else if (strcmp(segment, "temp") == 0) {
        construct_a_label(a_instruction.r5, instruction);
    } else if (strcmp(segment, "static") == 0) {
      construct_a_value(16, instruction);
    }

    // add index
    construct_dest_comp(c_destination.d, c_computation.d_plus_a, instruction);
    
    // write current val in temporary address r14
    construct_a_label(a_instruction.r14, instruction);
    construct_dest_comp(c_destination.m, c_computation.d, instruction);

    // write value in temp address 13 to d register
    construct_a_label(a_instruction.r13, instruction);
    construct_dest_comp(c_destination.d, c_computation.m, instruction);

    // write value in temp address 14 to a register
    construct_a_label(a_instruction.r14, instruction);
    construct_dest_comp(c_destination.a, c_computation.m, instruction);

    // write d to m
    construct_dest_comp(c_destination.m, c_computation.d, instruction);
}

void extract_constant_segment(int index, char *dest) {
    construct_a_value(index, dest);
    construct_dest_comp(c_destination.d, c_computation.a, dest);
}

void push_d_register_to_stack(char *dest) {
    construct_a_label(a_instruction.sp, dest);
    construct_dest_comp(c_destination.a, c_computation.m, dest);
    construct_dest_comp(c_destination.m, c_computation.d, dest);
}

void increment_stack_pointer(char *dest) {
    construct_a_label(a_instruction.sp, dest);
    construct_dest_comp(c_destination.m, c_computation.m_plus_one, dest);
}

void decrement_stack_pointer(char *dest) {
    construct_a_label(a_instruction.sp, dest);
    construct_dest_comp(c_destination.m, c_computation.m_minus_one, dest);
}
