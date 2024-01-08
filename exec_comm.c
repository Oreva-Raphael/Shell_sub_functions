#include "sh.h"
/**
 * exec_command - function to execute the command based on "userinput(instruct)"
 * 
 * @instruct: the command being executed
 * 
 */ 
void exec_comm(char *instruct)
{
    pid_t child;
    char **arr = NULL;
    int token_no = 0;
    int i;

    child = fork();
    if (child < 0){
        perror("Fork failed.");
        exit(EXIT_FAILURE);
    }
    if (child == 0){
        char *path = "/bin/ls"; //to define the command
        char *string = userinput(instruct);
        char *token;

        arr = (char **)malloc(token_lim * sizeof(char *)); //casting to char * type
        if (arr == NULL){
            perror("Memory allocation wrong");
            exit(EXIT_FAILURE);
        }

        token = strtok(string, "\n");
        while ((token != NULL && token_no < token_lim -1)){
            arr[token_no] = strdup(token);
            if (arr[token_no] == NULL){
                perror("tokenization error.");
                exit(EXIT_FAILURE);
            }
            token = strtok(NULL, "\n");
            token_no++;
        }
        arr[token_no] = NULL;

        if (strcmp(arr[0], path) == 0) /*to ensure the command is strictly = path*/
        {
            char *content[] = {"/bin/ls", "./", NULL};  //to go along with the execve requrements.          

            if (execve(content[0], content, NULL) == -1){
                perror("execution failure");
                exit(EXIT_FAILURE);
            }
        }
        else{
            perror("Incorrect format or command format invalid.");
            exit(EXIT_FAILURE);
        }
        for (i = 0; i < token_lim; i++){
            free(arr[i]);
        }
        free(arr);
    }
    else{
        wait(NULL);
    }
}
