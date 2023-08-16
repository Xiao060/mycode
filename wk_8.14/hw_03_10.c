#include <func.h>

void handler_3(int signum, siginfo_t* info, void* ucontext);

int main(int argc, char* argv[]) {

    struct sigaction act;
    
    // 清空结构体 / 初始化 
    memset(&act, 0, sizeof(act));
    act.sa_sigaction = handler_3;
    act.sa_flags = SA_RESTART | SA_SIGINFO;
    // 增加临时屏蔽
    sigaddset(&act.sa_mask, SIGQUIT);

    sigaction(SIGINT, &act, NULL);

    char buf[4096];
    read(STDIN_FILENO, buf, sizeof(buf));

    return 0;
}


void handler_3(int signum, siginfo_t* info, void* ucontext) {

    printf("before, pid = %d, signum = %d\n", info->si_pid, signum);
    sleep(5);
    printf("after, pid = %d, signum = %d\n", info->si_pid, signum);

    sigset_t set;
    // 获取 pending 集合
    sigpending(&set);

    // 判断信号在不在 set 集合中
    if (sigismember(&set, SIGQUIT)) {
        printf("SIGQUIT is in pending!\n");
    } else {
        printf("SIGQUIT is not in pending!\n");
    }
}
