#include "sh.h"
/**
 * execute- a compound function that parses and executes commands
 * 
 * @instruct: the instruction passed
 * 
 * return: 0 (Successful)
 */
int execute(char *instruct)
{
    size_t i;
    pid_t child;
    size_t token_no;

    (void) instruct;

    char **arr = readcommand(&token_no);

    if (arr != NULL)
    {
        child = fork();

        if (child < 0)
        {
            perror("Fork failed");
            exit(EXIT_FAILURE);
        }
        if (child == 0)
        {
            char *path = "/bin/ls";
            char *execarg[] = {"/bin/ls", "./", NULL};
                    
            if (token_no > 0 && strcmp(arr[0], path) == 0)
            {
                if (execve(execarg[0], execarg, NULL) == -1)
                {
                    perror("execution failed");
                    exit(EXIT_FAILURE);
                }
            }
            else{
                perror("No such file or directory");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            wait (NULL);
            for (i = 0; i < token_no; i++)
            {
                free(arr[i]);
            }
        }
        free (arr);
    }
    else
    {
        exit(EXIT_FAILURE);
    }
}
