#include <func.h>

int main(int argc, char* argv[]) {

    int fds[2];

    int ret = pipe(fds);
    ERROR_CHECK(ret, -1, "pipe");

    if (fork()) {
        // parent close read
        close(fds[0]);

        char buf[4096] = {0};
        int i = 1;
        while (1) {
            write(fds[1], buf, sizeof(buf));
            printf("write_i = %d, sum_of_char = %ld\n", i, i * sizeof(buf));
            i++;
        }
        
    } else {
        // child close write
        close(fds[1]);

        sleep(100);
    }

    return 0;
}
