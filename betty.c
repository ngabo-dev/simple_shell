#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 100
/**
 * main - main function
 * Return: 0
 */
int main(void)
{
    char command[MAX_COMMAND_LENGTH];

    while (1)
    {
        printf("Shell> ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        // Remove trailing newline character
        command[strcspn(command, "\n")] = '\0';

        // Exit the shell if the user enters "exit"
        if (strcmp(command, "exit") == 0)
        {
            break;
        }

        // Fork a child process to execute the command
        pid_t pid = fork();

        if (pid < 0)
        {
            fprintf(stderr, "Fork failed\n");
            exit(1);
        }
        else if (pid == 0)
        {
            // Child process
            execlp(command, command, NULL);
            fprintf(stderr, "Command not found: %s\n", command);
            exit(1);
        }
        else
        {
            // Parent process
            wait(NULL);
        }
    }

    return (0);
}
