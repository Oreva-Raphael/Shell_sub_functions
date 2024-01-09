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
    write(1, string, strlen(string));
    fflush(stdout);
}
