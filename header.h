#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <limits.h>

typedef struct s_table{
    char *cmd;
    char *option;
    char *arg;
}   t_table;

#endif