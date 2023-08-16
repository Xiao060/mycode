#include <func.h>


int main(int argc, char* argv[]) {

    int rc = fork();
    ERROR_CHECK(rc, -1, "fork");

    if (rc == 0) {
        close(STDOUT_FILENO);

        open("./p05.04.output", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);

        char* myargs[3];
        myargs[0] = strdup("wc");
        myargs[1] = strdup("p05.04.c");
        myargs[2] = NULL;

        execvp(myargs[0], myargs);
    } else {
        int wc = wait(NULL);
    }

    return 0;
}
