#include <func.h>

int main(int argc, char* argv[]) {

    // fds[0] 为读端
    // fds[1] 为写端
    int fds[2];
    int ret = pipe(fds);
    ERROR_CHECK(ret, -1, "pipe");


    if (fork()) {
        // close parent write
        close(fds[1]);

        char buf[4096];
        read(fds[0], buf, sizeof(buf));

        puts(buf);
    } else {
        // close child rad
        close(fds[0]);

        sleep(10);
        write(fds[1], "Hello World!", 12);
    }

    return 0;
}
