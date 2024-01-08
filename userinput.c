#include "sh.h"
/**
 * userinput -  receives the command from the stdin
 * 
 * @instruct: the command to be passed into the function
 * 
 * return: a pointer to an array of characters
 */

char *userinput(char *instruct)
{   
    char *line = NULL;
    size_t len = 0;

    if (getline(&line, &len, stdin) != -1)
    {
        // Removing the newline character from the input
        line[strcspn(line, "\n")] = '\0';
        // Allocating memory for the instruction and copying the line to it
        instruct = malloc(strlen(line) + 1);
        if (instruct == NULL) {
            perror("Memory allocation error");
            exit(EXIT_FAILURE);
        }
        strcpy(instruct, line);

        free(line);  // Freeing the dynamically allocated line buffer
        return instruct;
    }
    else{
        perror("Input termination");
        free(line);
        exit(EXIT_FAILURE);
    }
    return (NULL);
}
