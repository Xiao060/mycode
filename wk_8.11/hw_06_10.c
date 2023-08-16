// 可执行程序 1 
#include <func.h>

int main(int argc, char* argv[]) {

    ARGS_CHECK(argc, 2);

    if (fork()) {
        printf("parent start!\n");
        wait(NULL);
        printf("parent over!\n");

    } else {
        printf("child start!\n");
        execl(argv[1], argv[1], NULL);
    }

    return 0;
}





