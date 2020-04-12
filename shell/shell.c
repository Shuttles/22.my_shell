/*************************************************************************
	> File Name: shell.c
	> Author: 少年宇
	> Mail: 
	> Created Time: 2020年04月12日 星期日 19时22分01秒
 ************************************************************************/

#include "../common/head.h"

#define TRUE 1

int main() {
    pid_t pid;
    while (TRUE) {                        /*repeat forever*/
        type_prompt();                    /*display prompt on the screen*/
        read_command(command, parameters);/*read input from terminal*/
        if ((pid = fork()) < 0) {
            perror("fork");
            return 1;
        }
        if (pid == 0) {
            /*Child code*/
            execve(command, parameters, 0);/*execute command*/
        } else {
            /*Parent code*/
            wait(NULL);                    /*wait for child to exit*/
        }
    }

    return 0;
}
