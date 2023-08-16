#include <func.h>

int main(int argc, char* argv[]) {

    printf("Hello world (pid: %d)\n", (int) getpid());

    int rc = fork();
    
    ERROR_CHECK(rc, -1, "fork");

    if (rc == 0) 
        printf("Hello, I am child (pid: %d)\n", (int) getpid());
    else 
        printf("Hello, I am parent of %d (pid: %d)\n", rc, getpid());

    return 0;
}
