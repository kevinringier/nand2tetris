#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "util.h"
#include "code.h"

int main(int argc, char *argv[]) {
	FILE *fptr;
    FILE *wfptr;

	// fptr = openStream("C:\\Users\\Kevin\\Desktop\\eq-false.vm");
    fptr = openStream(argv[1]);
    wfptr = open_write_stream("C:\\Users\\Kevin\\Desktop\\output.asm");

    char *program_initializer = calloc(2048, sizeof(char));
    //initialize_memory_addresses(program_initializer);
    jump_to_app_start(program_initializer);
    initialize_function_labels(program_initializer);
    create_app_start_label(program_initializer);
    fputs(program_initializer, wfptr);
    free(program_initializer);

    while(hasMoreCommands(fptr)) {
        char *line = advance(fptr);

        printf("CURRENT FULL COMMAND: %s\n", line);
       
        int command = commandType(line);

        printf("MAPPED COMMAND TYPE: %d\n", command);
        printf("LINE PRE ARG1: %s\n", line);

        if (command != C_RETURN) {
            char *arg_one = parse_arg_one(line, command); 
            printf("ARG1 RETURN VAL: %s\n", arg_one);
            char *instruction = calloc(256, sizeof(char));

            if (isArg2CommandType(command)) {
                char *arg_two = parse_arg_two(line); // this looks off 
                int index = atoi(arg_two);
                printf("ARG2 RETURN VAL: %s\n", arg_two);
                write_push_pop(command, arg_one, index, instruction);
                free(arg_two); // i don't think I should be freeing this, what to do?
            } else {
                write_arithmetic(arg_one, instruction);
            }
            printf("\nINSTRUCTION\n");
            printf("%s\n", instruction);
            fputs(instruction, wfptr);
            free(instruction);
            free(arg_one); // same here
        }

        free(line); 
    }
	fclose(fptr);
    close_write(wfptr);
    return 0;
}
