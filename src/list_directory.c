#include <stdio.h>
#include <dirent.h>

void list_directory(char* directory_path)
{
    DIR* directory = opendir(directory_path);
    if (directory == NULL)
    {
        printf("Error: Directory not found.\n");
        return;
    }

    struct dirent* dir_entry;
    while ((dir_entry = readdir(directory)) != NULL)
    {
        printf("%s\n", dir_entry->d_name);
    }

    closedir(directory);
}