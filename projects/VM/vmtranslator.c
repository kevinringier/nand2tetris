#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "util.h"
#include "code.h"

int main(int argc, char *argv[]) {
	FILE *fptr;
    FILE *wfptr;

    // TODO: open and read all files within a directory
    // TODO: add function scope
    fptr = open_stream(argv[1]);
    char *output_file_destination = get_write_to_file_path(argv[1]);
    wfptr = open_write_stream(output_file_destination);
    char *parsed_file_name = parse_file_name(argv[1]);

    char *program_initializer = calloc(2048, sizeof(char));
    //initialize_memory_addresses(program_initializer);
    jump_to_app_start(program_initializer);
    initialize_function_labels(program_initializer);
    create_app_start_label(program_initializer);
    fputs(program_initializer, wfptr);
    free(program_initializer);

    while(has_more_commands(fptr)) {
        char *line = advance(fptr);

        printf("CURRENT FULL COMMAND: %s\n", line);
       
        int command = commandType(line);

        printf("MAPPED COMMAND TYPE: %d\n", command);
        printf("LINE PRE ARG1: %s\n", line);

        char *instruction = calloc(1024, sizeof(char));

        if (command != C_RETURN) {
            char *arg_one = parse_arg_one(line, command); 
            printf("ARG1 RETURN VAL: %s\n", arg_one);
            

            if (is_arg2_command_type(command)) {
                char *arg_two = parse_arg_two(line);
                int index = atoi(arg_two);
                printf("ARG2 RETURN VAL: %s\n", arg_two);

                if (is_function(command)) { // index here represents number of local variables
                    write_function(arg_one, index, instruction);
                } else if (is_call(command)) {
                    write_call(arg_one, index, instruction);
                } else {
                    char *arg_two = parse_arg_two(line);
                    int index = atoi(arg_two);
                    printf("ARG2 RETURN VAL: %s\n", arg_two);
                    write_push_pop(command, arg_one, index, parsed_file_name, instruction);
                }
                free(arg_two);
                //write function or call
                    // this should be else if for function and call rather than else
                    // testing if function label works
                    // if function albel works, work on generate function return label followed by call function
                    // then read multiple files
                    // then generate unique labels in functions
            } else {
                if (is_program_flow_command(command)) {
                    write_program_flow(command, arg_one, instruction);
                } else {
                    write_arithmetic(arg_one, instruction);
                }
                free(arg_one);
            }
        } else {
            write_return(instruction);
        }

        printf("\nINSTRUCTION\n");
        printf("%s\n", instruction);
        fputs(instruction, wfptr);
        free(instruction);
        free(line); 
    }

	fclose(fptr);
    close_write(wfptr);
    free(output_file_destination);

    return 0;
}
