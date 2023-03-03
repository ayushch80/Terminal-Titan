#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void print_prompt() {
    char username[256], hostname[256], cwd[MAX_PATH], prompt[1280];

    // retrieve the username
    if (getenv("USERNAME") != NULL) {
        strcpy(username, getenv("USERNAME"));
    } else {
        strcpy(username, "unknown");
    }

    // retrieve the hostname
    DWORD hostname_len = 256;
    if (!GetComputerName(hostname, &hostname_len)) {
        strcpy(hostname, "unknown");
    }

    // retrieve the current working directory
    if (!GetCurrentDirectory(MAX_PATH, cwd)) {
        strcpy(cwd, "unknown");
    }

    // replace the home directory with "~"
    const char* home_dir = getenv("USERPROFILE");
    if (home_dir != NULL && strstr(cwd, home_dir) == cwd) {
        sprintf(prompt, "~%s", cwd + strlen(home_dir));
    } else {
        strcpy(prompt, cwd);
    }

    // print the prompt in multiple colors
    printf("\x1b[32m%s\x1b[0m", username); // username in green
    printf("\x1b[36m@\x1b[0m"); // @ symbol in cyan
    printf("\x1b[33m%s\x1b[0m", hostname); // hostname in yellow
    printf(":");
    printf("\x1b[34m%s\x1b[0m", prompt); // working directory in blue
    printf("$ ");
}