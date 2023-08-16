#include <func.h>

int main(void) {

    pid_t pid = fork();

    int i = 0;

    if (pid == 0) {
        puts("child");
        printf("child i = %d, &i = %p\n", i, &i);
        ++i;
        printf("child i = %d, &i = %p\n", i, &i);
    } else {
        puts("parent");
        printf("parent i = %d, &i = %p\n", i, &i);
        sleep(1);
        printf("parent i = %d, &i = %p\n", i, &i);
    }

    return 0;
}
