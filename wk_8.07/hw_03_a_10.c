#include <func.h>

int main(int argc, char* argv[]) {

    ARGS_CHECK(argc, 2);

    printf("1.Helloworld!\n");


    // 2 管道写端
    int fdw = open(argv[1], O_WRONLY);
    ERROR_CHECK(fdw, -1, "open");

    int backup_fd = 10;
    int ret = dup2(STDOUT_FILENO, backup_fd);
    ERROR_CHECK(ret, -1, "dup2_1");

    ret = dup2(fdw, STDOUT_FILENO);
    ERROR_CHECK(ret, -1, "dup2_2")

    printf("2.Helloworld!\n");


    // 3    
    ret = dup2(backup_fd, STDOUT_FILENO);
    ERROR_CHECK(ret, -1, "dup2_3");

    printf("3.Helloworld!\n");

    close(fdw);
    return 0;
}
