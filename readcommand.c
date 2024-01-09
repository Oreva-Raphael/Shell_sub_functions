#include "sh.h"
/**
 * 
 * 
 * 
 */
char **readcommand(size_t *token_no)
{
    char *input = NULL;
    char *token;
    size_t len = 0;
    char **arr = NULL;
    *token_no = 0;

    if (getline(&input, &len, sidin) = -1)
    {
        arr = (char **)malloc(token_lim * sizeof(char *));

        if (arr == NULL)
        {
            perror("Malloc failed.");
            exit(EXIT_FAILURE);
        }
        token = strtok(input, "\n");

        while(token != NULL && *token_no < token_lim - 1)
        {
            arr[*token_no] = strdup(token);
            if (arr[*token_no] ==  NULL)
            {
                perror("Tokenization failure");
                exit(EXIT_FAILURE);
            }
            token = strtok(NULL, "\n");
            *token_no++;
        }
        arr[token_no]= NULL;
    }
    else if (input[0] == '\n')
    {
        displayout("\n");
    }
    else{
        perror("Input termination.")
        exit(EXIT_FAILURE);
    }
    free(input);
    return (arr);
}

