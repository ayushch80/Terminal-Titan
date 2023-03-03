#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <dirent.h>
#include <sys/stat.h>
#include "print_prompt.h"
#include "list_directory.h"
#include "print_file_contents.h"

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 64

int main() {
    char command[MAX_COMMAND_LENGTH];
    char* arguments[MAX_ARGUMENTS];
    int num_arguments = 0;

    while (true) {
        print_prompt();

        // Read command from user input
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        command[strlen(command) - 1] = '\0'; // Remove trailing newline

        // Parse command into arguments
        char* argument = strtok(command, " ");
        num_arguments = 0;

        while (argument != NULL && num_arguments < MAX_ARGUMENTS)
        {
            arguments[num_arguments] = argument;
            num_arguments++;
            argument = strtok(NULL, " ");
        }
        arguments[num_arguments] = NULL;

        // Check for built-in commands
        if (strcmp(arguments[0], "exit") == 0)
        {
            break;
        }
        if (strcmp(arguments[0], "cd") == 0)
        {
            if (num_arguments < 2)
            {
                // No argument provided, change to home directory
                chdir(getenv("USERPROFILE"));
            }
            else
            {
                // Change to specified directory
                if (chdir(arguments[1]) != 0)
                {
                    printf("Error: Directory not found.\n");
                }
            }
        }
        else if (strcmp(arguments[0], "ls") == 0)
        {
            if (num_arguments < 2)
            {
                list_directory(".");
            }
            else
            {
                list_directory(arguments[1]);
            }
        }
        else if (strcmp(arguments[0], "cat") == 0)
        {
            if (num_arguments < 2)
            {
                printf("Error: File path not provided.\n");
            }
            else
            {
                print_file_contents(arguments[1]);
            }
        }
        else
        {
            // Concatenate all arguments into a single string
            char command_line[MAX_COMMAND_LENGTH];
            command_line[0] = '\0'; // initialize to empty string
            for (int i = 0; i < num_arguments; i++)
            {
                strcat(command_line, arguments[i]);
                if (i < num_arguments - 1)
                {
                    strcat(command_line, " ");
                }
            }
            
            system(command_line);
        }
    }

    return 0;
}
