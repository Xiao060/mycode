#include <func.h>

int main(int argc, char* argv[]) {
    ARGS_CHECK(argc, 2);

    char buf[1000000];
    memset(buf, '1', sizeof(buf));

    int fd = open(argv[1], O_RDWR | O_CREAT, 0666);
    ERROR_CHECK(fd, -1, "open");

    ssize_t ret = write(fd, buf, sizeof(buf));
    ERROR_CHECK(ret, -1, "write");

    close(fd);

    return 0;
}
