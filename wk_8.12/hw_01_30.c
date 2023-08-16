#include <func.h>


int main(int argc, char* argv[]) {

    int fds[2];

    int ret = pipe(fds);
    ERROR_CHECK(ret, -1, "pipe");

    if (fork()) {
        // parent close read
        close(fds[0]);

        char buf[1024] = {0};
        int i = 1;
        while(1) {
            ssize_t ret = write(fds[1], buf, sizeof(buf));
            printf("i = %d, ret = %ld, size_of_written = %ld bits\n", 
                   i, ret, i * sizeof(buf));
            i++;
            sleep(1);
        }
    } else {
        // child close both
        close(fds[1]);
        sleep(3);
        close(fds[0]);
    }

    return 0;
}
