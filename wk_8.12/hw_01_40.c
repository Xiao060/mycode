#include <func.h>


int main(int argc, char* argv[]) {

    int fds[2];

    int ret = pipe(fds);
    ERROR_CHECK(ret, -1, "pipe");

    if (fork()) {
        // parent close write
        close(fds[1]);

        char buf[1024];
        while(1) {
            memset(buf, 0, sizeof(buf));

            ssize_t ret = read(fds[0], buf, sizeof(buf));
            printf("buf = %s, ret = %ld\n", buf, ret);
        }

    } else {
        // child close both
        close(fds[0]);

        char buf[1024] = "Hello World";
        for (int i=0; i < 5; ++i) {
            write(fds[1], buf, strlen(buf));
            sleep(1);
        }

        close(fds[1]);
    }

    return 0;
}
