#include <func.h>

void handler(int signum);

int main(int argc, char* argv[]) {

    signal(SIGINT, handler);
    /* signal(SIGQUIT, handler); */

    while (1) {
        sleep(1);
    }

    return 0;
}


void handler(int signum) {
    printf("before signum = %d\n", signum);
    sleep(3);
    printf("after signum = %d\n", signum);
}
