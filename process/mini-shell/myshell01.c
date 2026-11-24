#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define FORMATE "[%s@%s %s]# "
#define LINE_SIZE 1024

char commandline[LINE_SIZE];
char *args[64];

char* getusername()
{
    return getenv("USER");
}

char* gethost()
{
    return getenv("HOSTNAME");
}

char* getmypwd()
{
    return getenv("PWD");
}

void interact(char* cline, int size)
{
    printf(FORMATE, getusername(), gethost(), getmypwd());
    fflush(stdout);

    fgets(cline, size, stdin);
    cline[strcspn(cline, "\n")] = '\0';
}

void parse_command()
{
    int i = 0;
    args[i] = strtok(commandline, " ");

    while(args[i] != NULL)
    {
        i++;
        args[i] = strtok(NULL, " ");
    }
}

// ======================
// 仅实现 cd 内建命令
// ======================
int builtin_cd()
{
    // 如果不是 cd，返回 0，继续执行系统命令
    if (strcmp(args[0], "cd") != 0)
        return 0;

    // 是 cd，自己执行
    if (args[1] == NULL)
    {
        // 没参数 → 回到家目录
        chdir(getenv("HOME"));
    }
    else
    {
        // 有参数 → 切换到目标目录
        chdir(args[1]);
    }

    // 更新 PWD 环境变量，让提示符路径刷新
    char buf[1024];
    getcwd(buf, sizeof(buf));
    setenv("PWD", buf, 1);

    return 1;
}

void execute_cmd()
{
    if(args[0] == NULL)
        return;

    pid_t pid = fork();

    if(pid == 0)
    {
        execvp(args[0], args);
        perror("exec error");
        exit(1);
    }
    else if(pid > 0)
    {
        wait(NULL);
    }
}

int main()
{
    while(1)
    {
        interact(commandline, sizeof(commandline));
        if(strlen(commandline) == 0) continue;

        parse_command();

        // 如果是 cd，执行完直接跳过系统命令
        if(builtin_cd())
            continue;

        // 其他命令正常执行
        execute_cmd();
    }

    return 0;
}
