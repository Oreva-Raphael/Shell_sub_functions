#ifndef SH_H
#define SH_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stddef.h>
#include <string.h>
#define token_lim 20

void displayout(const char *string);
void _prompt(void);
char *userinput(char *instruct);
void exec_comm(char *instruct);

#endif
