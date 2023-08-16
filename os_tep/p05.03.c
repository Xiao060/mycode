#include <func.h>


int main(int argc, char* argv[]) {
    printf("Hello: %d\n", (int) getpid());

    int rc = fork();
    ERROR_CHECK(rc, -1, "fork");

    if (rc == 0) {
        printf("child: %d\n", (int) getpid());

        char* myargs[3];
        myargs[0] = strdup("wc");
        myargs[1] = strdup("p05.03.c");
        myargs[2] = NULL;

        // 直接将子进程替换掉, 数组中第一项为filename, 数组以 NULL 结尾
        execvp(myargs[0], myargs);


        printf("this shouldn't print out");
    } else {
        int wc = wait(NULL);
        printf("pid: %d;    child pid: %d;    wc: %d\n", (int)getpid(), rc, wc);
    }

    return 0;
}
