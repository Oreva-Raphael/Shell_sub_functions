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
    char *input = NULL;
    char *token;
    size_t len = 0;
    char **arr = NULL;
    int token_no = 0;
    int i;
    pid_t child;

    (void) instruct;

    if (getline (&input, &len, stdin) != -1)
    {
        arr = (char **)malloc(token_lim * sizeof(char *));
           
        if (arr == NULL)
        {
            perror("Malloc failed.");
            exit(EXIT_FAILURE);
        }
        token = strtok(input, "\n");

        while(token != NULL && token_no < token_lim - 1)
        {
            arr[token_no] = strdup(token);
            if (arr[token_no] ==  NULL)
            {
                perror("Tokenization failure");
                exit(EXIT_FAILURE);
            }
            token = strtok(NULL, "\n");
            token_no++;
        }
        arr[token_no]= NULL;
        
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
            if(input[0] == '\n')
            {
                displayout("\n");
            }
            else{
                perror("Unknown command");
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
        perror("Input termination");
        exit(EXIT_FAILURE);
    }
    free(input);
    return (0);
}
