#include <stdio.h>
#include <stdlib.h>

/**
 * main - Simple Shell
 *
 * Return: Always 0
 */
int main(void)
{
    char *buffer = NULL;
    size_t bufsize = 0;
    ssize_t characters;

    while (1)
    {
        printf("$ ");  /* Display shell prompt */

        /* Read input from the user */
        characters = getline(&buffer, &bufsize, stdin);

        /* Check for end of file or error */
        if (characters == -1)
        {
            perror("getline");
            break;
        }

        /* Print the entered command */
        printf("You entered: %s", buffer);
    }

    /* Free the allocated memory */
    free(buffer);

    return 0;
}
