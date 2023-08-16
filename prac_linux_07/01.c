#include <func.h>

void sigfunc(int signum);

int main(int argc, char* argv[]) {

    signal(SIGINT, sigfunc);
    printf("process begin!\n");
    while(1) ;

    return 0;
}


void sigfunc(int signum) {
    printf("signum = %d is coming\n", signum);
}
