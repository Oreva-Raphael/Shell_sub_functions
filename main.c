#include "sh.h"
/**
 * 
 * 
 * 
 */
int main(void)
{
    char command[128];

    while (1)
    {
        _prompt();
        exec_comm(command);
    }
    return (0);
}
