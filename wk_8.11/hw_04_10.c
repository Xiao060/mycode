#include <func.h>


int main(int argc, char* argv[]) {

    if (fork()) {
        printf("parent\n");

        int status;
        pid_t ret = wait(&status);
        ERROR_CHECK(ret, -1, "wait");

        if (WIFEXITED(status)) {
            printf("WEXITSTATUS = %d\n", WEXITSTATUS(status));
        } 

        if (WIFSIGNALED(status)){
            printf("WTERMSIG = %d\n", WTERMSIG(status));
        }

    } else {
        printf("child\n");
        exit(-1);
    }

    return 0;
}
