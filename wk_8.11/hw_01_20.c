#include <func.h>

int main(int argc, char* argv[]) {

    if (fork()) {
        printf("parent, pid = %d, ppid = %d\n", getpid(), getppid());
        sleep(10);
    } else {
        printf("child, pid = %d, ppid = %d\n", getpid(), getppid());
    }

    return 0;
}
