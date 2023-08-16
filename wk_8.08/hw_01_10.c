#include <func.h>


int main(int argc, char* argv[]) {

    ARGS_CHECK(argc, 2);

    int fdr = open(argv[1], O_RDWR);
    ERROR_CHECK(fdr, -1, "open fdr");

    int fdw = open(argv[1], O_RDWR);
    ERROR_CHECK(fdw, -1, "open fdw");

    char buf[4096] = {0};
    fd_set rdset;
    fd_set wrset;
    int cnt = 1;
    
    while (1) {
        FD_ZERO(&rdset);
        FD_SET(fdr, &rdset);

        FD_ZERO(&wrset);
        FD_SET(fdw, &wrset);

        int ret = select(fdw+1, &rdset, &wrset, NULL, NULL);
        ERROR_CHECK(ret, -1, "select");

        if (FD_ISSET(fdr, &rdset)) {
            printf("read reday!, cnt = %d\n", cnt++);
            ssize_t rret = read(fdr, buf, 1024);
            ERROR_CHECK(rret, -1, "read");
        }

        if (FD_ISSET(fdw, &wrset)) {
            printf("write ready!, cnt = %d\n", cnt++);
            ssize_t wret = write(fdw, buf, 4096);            
            ERROR_CHECK(wret, -1, "write");
        }

        sleep(1);
    }

    return 0;
}














