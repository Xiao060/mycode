#include <func.h>

int main(int argc, char* argv[]) {
    ARGS_CHECK(argc, 3);

    int fd1 = open(argv[1], O_RDWR | O_TRUNC | O_CREAT, 0666);
    ERROR_CHECK(fd1, -1, "open fd1");

    int fd2 = open(argv[2], O_RDWR | O_TRUNC | O_CREAT, 0666);
    ERROR_CHECK(fd2, -1, "open fd2");

    printf("\n");
    int ret = dup2(fd1, STDOUT_FILENO);
    ERROR_CHECK(ret, -1, "dup2 stdout");

    ret = dup2(fd2, STDERR_FILENO);
    ERROR_CHECK(ret, -1, "dup2 stderr");

    printf("Hello\n");
    fprintf(stderr, "World\n");

    return 0;
}
