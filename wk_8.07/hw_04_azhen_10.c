#include <func.h>

int main(int argc, char* argv[]) {
    ARGS_CHECK(argc, 3);

    int fdr = open(argv[1], O_RDONLY);
    ERROR_CHECK(fdr, -1, "open_fdr");

    int fdw = open(argv[2], O_WRONLY);
    ERROR_CHECK(fdw, -1, "open_fdw");

    printf("azhen is reday!\n");


    // 建立监听集合
    fd_set rdset;
    char buf[4096];

    struct timeval timeout;
    time_t last_active = time(NULL);

    while (1) {
        FD_ZERO(&rdset);
        FD_SET(fdr, &rdset);
        FD_SET(STDIN_FILENO, &rdset);

        timeout.tv_sec = 1;
        timeout.tv_usec = 0;

        int ret = select(fdr+1, &rdset, NULL, NULL, &timeout);
        ERROR_CHECK(ret, -1, "select")
        
        time_t now = time(NULL);

        if (FD_ISSET(fdr, &rdset)) {
            memset(buf, 0, sizeof(buf));
            ssize_t rret = read(fdr, buf, sizeof(buf));
            
            // 对方已退出
            if (rret == 0) {
                printf("aqing 已断开连接!\n");
                break;
            }

            printf("aqiang: %s\n", buf);
            last_active = time(NULL);
        }

        if (FD_ISSET(STDIN_FILENO, &rdset)) {
            memset(buf, 0, sizeof(buf));
            ssize_t rret = read(STDIN_FILENO, buf, sizeof(buf));

            if (rret == 0) {
                write(fdw, "Bye~Bye~", 8);
                break;
            }

            write(fdw, buf, strlen(buf));
        }

        if (now  - last_active > 10) {
            printf("aqiang 已被踢出!\n");
            break;
        }
    }

    close(fdw);
    close(fdr);

    return 0;
}







