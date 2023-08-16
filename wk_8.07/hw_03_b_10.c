#include <func.h>

int main(int argc, char* argv[]) {

    ARGS_CHECK(argc, 2);

    // 管道读端
    int fdr = open(argv[1], O_RDONLY);
    ERROR_CHECK(fdr, -1, "open");


    char buf[1024];
    int ret = read(fdr, buf, sizeof(buf));
    ERROR_CHECK(ret, -1, "read");

    // write(STDOUT_FILENO, buf, strlen(buf));
    printf("%s", buf);

    close(fdr);
    return 0;

}
