#include <func.h>

int main(void) {

    pid_t pid = fork();

    char* p = (char*) malloc(6);
    strcpy(p, "hello");

    if (pid == 0) {
        puts("child");
        printf("child p = %s, p = %p\n", p, p);
        strcpy(p, "world");
        printf("child p = %s, p = %p\n", p, p);
    } else {
        puts("parent");
        printf("parent p = %s, p = %p\n", p, p);
        sleep(1);
        printf("parent p = %s, p = %p\n", p, p);
    }

    return 0;
}
