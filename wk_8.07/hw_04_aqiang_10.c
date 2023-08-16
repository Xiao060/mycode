#include <func.h>

int main(int argc, char* argv[]) {
    ARGS_CHECK(argc, 3);

    int fdw = open(argv[1], O_WRONLY);
    ERROR_CHECK(fdw, -1, "open_fdw");

    int fdr = open(argv[2], O_RDONLY);
    ERROR_CHECK(fdr, -1, "open_fdr");

    printf("aqiang is reday!\n");
    
    // 创建监听集合
    fd_set rdset;
    char buf[4096];

    while (1) {
        FD_ZERO(&rdset);
        FD_SET(fdr, &rdset);
        FD_SET(STDIN_FILENO, &rdset);

        int ret = select(fdr+1, &rdset, NULL, NULL, NULL);
        ERROR_CHECK(ret, -1, "select");

        if (FD_ISSET(fdr, &rdset)) {
            memset(buf, 0, sizeof(buf));
            ssize_t rret = read(fdr, buf, sizeof(buf));

            // 对方已退出
            if (rret == 0) {
                printf("azhen 已断开连接\n");
                break;
            }

            printf("azhen: %s\n", buf);
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
    }

    close(fdr);
    close(fdw);
    
    return 0;
}







