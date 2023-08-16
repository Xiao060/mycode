// 只实现了前 3 个要求
// 此处使用的 sigprocmask 添加屏蔽, 
// 需要注意的是 添加后 mask 始终包含 此信号,
// 若不解除, 则 此信号 会一直留在 pending 中, 永远不会执行
#include <func.h>

void handler(int signum);

int main(int argc, char* argv[]) {


    struct sigaction act;
    // 清空结构体 / 初始化 
    memset(&act, 0, sizeof(act));
    act.sa_handler = handler;
    act.sa_flags = SA_RESTART;

    sigaction(SIGINT, &act, NULL);

    char buf[4096] = {0};
    read(STDIN_FILENO, buf, sizeof(buf));

    return 0;
}


void handler(int signum) {
    // 增加的新集合
    sigset_t set;
    sigemptyset(&set);
    sigaddset(&set, SIGQUIT);
    // 在递送过程中 增加 屏蔽
    sigprocmask(SIG_BLOCK, &set, NULL);


    printf("before signum = %d\n", signum);
    sleep(5);
    printf("after signum = %d\n", signum);

    sigset_t pset;
    // 获取 pending 集合
    sigpending(&pset);

    // 判断信号在不在 set 集合中
    if (sigismember(&pset, SIGQUIT)) {
        printf("SIGQUIT is in pending!\n");
    } else {
        printf("SIGQUIT is not in pending!\n");
    }


    // 在递送过程中 解除 屏蔽
    sigprocmask(SIG_UNBLOCK, &set, NULL);
}
