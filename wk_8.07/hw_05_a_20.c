#include <func.h>

typedef struct train_s {
    // 占用 4B, 存储内容长度
    int length;
    char data[1000];
} train_t;

int main(int argc, char* argv[]) {
    ARGS_CHECK(argc, 3);

    // 管道
    int fdw = open(argv[1], O_WRONLY);
    ERROR_CHECK(fdw, -1, "open pipe");

    // 磁盘文件
    int fd = open(argv[2], O_RDONLY);
    ERROR_CHECK(fd, -1, "open file");

    train_t train;
    train.length = strlen(argv[2]);
    memcpy(train.data, argv[2], train.length);

    // 先传输文件名长度, 再传输文件名
    write(fdw, &train.length, sizeof(int));
    write(fdw, train.data, train.length);

    while(1) {
        memset(train.data, 0, sizeof(train.data));

        ssize_t rret = read(fd, train.data, sizeof(train.data));

        train.length = rret;
        write(fdw, &train.length, sizeof(int));

        // 如果文件读完, 只传输长度, 然后退出, 不必再传输问件内容
        if (rret == 0) {
            break;
        }

        write(fdw, train.data, train.length);
    }

    close(fd);
    close(fdw);

    return 0;
}










