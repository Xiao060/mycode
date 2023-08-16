#include <func.h>

int main(int argc, char* argv[]) {
    ARGS_CHECK(argc, 2);

    int fd = open(argv[1], O_RDWR | O_TRUNC | O_CREAT, 0666);
    ERROR_CHECK(fd, -1, "open");

    printf("\n");
    int ret = dup2(fd, STDOUT_FILENO);
    ERROR_CHECK(ret, -1, "dup2 stdout");

    ret = dup2(fd, STDERR_FILENO);
    ERROR_CHECK(ret, -1, "dup2 stderr");

    printf("Hello\n");
    fprintf(stderr, "World\n");

    return 0;
}
