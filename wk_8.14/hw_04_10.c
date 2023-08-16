#include <func.h>

int main(int argc, char* argv[]) {


    sigset_t set;
    sigemptyset(&set);
    sigaddset(&set, SIGINT);
    // 增加屏蔽
    sigprocmask(SIG_BLOCK, &set, NULL);

    sleep(5);

    sigset_t pset;
    sigpending(&pset);

    if (sigismember(&pset, SIGINT)) {
        printf("SIGINT is in pending!\n");
    } else {
        printf("SIGINT is not in pending!\n");
    }

    sigprocmask(SIG_UNBLOCK, &set, NULL);

    while(1) {
        sleep(1);
    }

    return 0;
}
