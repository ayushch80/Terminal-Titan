#include <stdio.h>

#define MAX_COMMAND_LENGTH 1024

void print_file_contents(char* file_path)
{
    FILE* file = fopen(file_path, "r");
    if (file == NULL)
    {
        printf("Error: File not found.\n");
        return;
    }

    char line[MAX_COMMAND_LENGTH];
    while (fgets(line, MAX_COMMAND_LENGTH, file) != NULL)
    {
        printf("%s", line);
    }

    fclose(file);
}