#include <func.h>

int main(int argc, char* agrv[]) {
    printf("Hello World (pid: %d)\n", (int) getpid());

    int rc = fork();
    ERROR_CHECK(rc, -1, "fork");

    if (rc == 0)
        printf("Hello, I am child (pid: %d)\n", (int) getpid());
    else {
        int wc = wait(NULL);
        printf("Hello, I am parent of %d (wc: %d) (pid: %d)\n", rc, wc, (int) getpid());
    }

    return 0;
}
