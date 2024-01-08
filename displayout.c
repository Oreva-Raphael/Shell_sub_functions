#include "sh.h"
/**
 * displayout- this function is to act like printf, to display anything to stdout.
 * 
 * @string: the string the function will display
 * 
 * return: No return value
 */

void displayout(const char *string)
{
    write(STDOUT_FILENO, string, strlen(string));
}
