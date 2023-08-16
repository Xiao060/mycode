#include <func.h>

int main(int argc, char* argv[]) {

    printf("pid = %d, tid = %lu\n", getpid(), pthread_self());

    return 0;
}
