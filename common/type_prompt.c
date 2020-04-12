/*************************************************************************
	> File Name: type_prompt.c
	> Author: 少年宇
	> Mail: 
	> Created Time: 2020年04月12日 星期日 19时34分14秒
 ************************************************************************/

#include "head.h"
#include "color.h"

#define MAXHOST 256
#define MAXPATH 1024

void type_prompt() {
    char prompt1[2048] = {0};
    char prompt2[2048] = {0};
    struct passwd *pwd;
    char hostname[MAXHOST] = {0};
    char pathname[MAXPATH] = {0};
    //int len = 0;

    pwd = getpwuid(getuid());                     /*获取passwd结构体*/
    getcwd(pathname, MAXPATH);                    /*获取路径名*/
    
    if (gethostname(hostname, MAXHOST) == 0) {    /*获取主机名*/
        sprintf(prompt1, "[MYSHELL]%s@%s:", pwd->pw_name, hostname);
    } else {
        sprintf(prompt1, "[MYSHELL]%s@unknown:", pwd->pw_name);
    }

    //len = strlen(prompt);

    if (strlen(pathname) < strlen(pwd->pw_dir) || (strncmp(pathname, pwd->pw_dir, strlen(pwd->pw_dir))) != 0) {
        sprintf(prompt2, "%s", pathname);    /*如果不是用户路径*/
    } else {
        sprintf(prompt2, "~%s", pathname + strlen(pwd->pw_dir));
    }
    
    //len = strlen(prompt2);

    char x;
    if (getuid() == 0) {
        x = '#';
    } else {
        x = '$';
    }

    printf(L_GREEN"%s"NONE L_BLUE"%s"NONE "%c\n", prompt1, prompt2, x);
    return ;
}


int main() {

    type_prompt();
    return 0;
}

