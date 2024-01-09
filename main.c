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
        execute(command);
    }
    return (0);
}
