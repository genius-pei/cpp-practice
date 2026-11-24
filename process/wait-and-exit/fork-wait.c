#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    // 调用fork创建子进程
    pid_t pid = fork();

    if (pid < 0) {
        // 失败场景
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        // 子进程执行逻辑
        printf("我是子进程，PID：%d，父进程PID：%d\n", getpid(), getppid());
        // 子进程执行完退出
        return 0;
    } else {
        // 父进程执行逻辑
        printf("我是父进程，PID：%d，创建的子进程PID：%d\n", getpid(), pid);
        // 等待子进程结束，避免僵尸进程
        wait(NULL);
        printf("子进程已结束\n");
    }
    return 0;
}
