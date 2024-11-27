#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Function to read a command from the user
void read_command(char* command, char** args) {
    char* line = NULL;
    size_t len = 0;

    // Read the command line input
    printf("shell> ");
    getline(&line, &len, stdin);

    // Remove the trailing newline character
    line[strcspn(line, "\n")] = '\0';

    // Parse the command into arguments
    char* token = strtok(line, " ");
    int i = 0;
    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;

    // Copy the command (first argument)
    strcpy(command, args[0]);

    free(line);
}

// Function to execute a command
void execute_command(char* command, char** args) {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Failed to fork");
        exit(1);
    } else if (pid == 0) {
        // Child process: Execute the command
        if (execvp(command, args) == -1) {
            perror("shell");
        }
        exit(1);
    } else {
        // Parent process: Wait for the child to finish
        int status;
        waitpid(pid, &status, 0);
    }
}

// Function to change directories
void change_directory(char** args) {
    if (args[1] == NULL) {
        fprintf(stderr, "shell: expected argument to \"cd\"\n");
    } else {
        if (chdir(args[1]) != 0) {
            perror("shell");
        }
    }
}

int main() {
    char command[1024];
    char* args[64];

    while (1) {
        // Read command and arguments
        read_command(command, args);

        // Check for built-in commands
        if (strcmp(command, "exit") == 0) {
            break;
        } else if (strcmp(command, "cd") == 0) {
            change_directory(args);
        } else {
            // Execute other commands
            execute_command(command, args);
        }
    }

    printf("Exiting shell...\n");
    return 0;
}
void execute_command(char* command, char** args) {
    int background = 0;
    int i = 0;

    // Check for '&' at the end of the arguments
    while (args[i] != NULL) {
        if (strcmp(args[i], "&") == 0) {
            background = 1;
            args[i] = NULL; // Remove '&' from arguments
            break;
        }
        i++;
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("Failed to fork");
        exit(1);
    } else if (pid == 0) {
        // Child process: Execute the command
        if (execvp(command, args) == -1) {
            perror("shell");
        }
        exit(1);
    } else {
        // Parent process: Wait if not a background process
        if (!background) {
            int status;
            waitpid(pid, &status, 0);
        }
    }
}

