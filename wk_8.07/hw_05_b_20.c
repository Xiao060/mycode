#include <func.h>

typedef struct train_s  {
    int length;
    char data[1000];
} train_t;


int main(int argc, char* argv[]) {

    ARGS_CHECK(argc, 2);

    int fdr = open(argv[1], O_RDONLY);
    ERROR_CHECK(fdr, -1, "open pipe");

    train_t train;
    // 先接收文件名长度, 再接收文件名
    read(fdr, &train.length, sizeof(int));
    read(fdr, train.data, train.length);

    // 创建目录
    mkdir("dir", 0777);

    // 获取文件的相对路径
    // filepath = 文件名 + "\" + train.data;
    // train.data 长度为 1000, 故 filepath 应大于 1000
    char filepath[2048] = {0};
    sprintf(filepath, "%s/%s", "dir", train.data);

    int fd = open(filepath, O_RDWR | O_TRUNC | O_CREAT, 0666);
    ERROR_CHECK(fd, -1, "open file");

    while (1) {
        memset(train.data, 0, sizeof(train.data));
        read(fdr, &train.length, sizeof(int));

        if (train.length == 0) {
            break;
        }

        read(fdr, train.data, train.length);
        write(fd, train.data, train.length);
    }

    close(fd);
    close(fdr);

    return 0;
}






