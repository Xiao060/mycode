#include <func.h>

int main(int argc, char* argv[]) {
    ARGS_CHECK(argc, 3);

    int fd1 = open(argv[1], O_RDWR);
    ERROR_CHECK(fd1, -1, "open1");

    int fd2 = open(argv[2], O_RDWR);
    ERROR_CHECK(fd2, -1, "open2");

    char buff1[1024], buff2[1024];

    while (1) {
        memset(buff1, 0, sizeof(buff1));
        memset(buff2, 0, sizeof(buff2));

        ssize_t ret1 = read(fd1, buff1, sizeof(buff1));
        ERROR_CHECK(ret1, -1, "read1");

        ssize_t ret2 = read(fd2, buff2, sizeof(buff2));
        ERROR_CHECK(ret2, -1, "read2");

        if (ret1 != ret2) {
            printf("文件内容不一致!\n");
            break;
        }

        int cmp = strcmp(buff1, buff2);
        if (cmp != 0) {
            printf("文件内容不一致!\n");
            break;
        }

        if (ret1 == 0 && ret2 == 0) {
            printf("文件内容一致!\n");
            break;
        }
    }
    close(fd2);
    close(fd1);
    return 0;
}
