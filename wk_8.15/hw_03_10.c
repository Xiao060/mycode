#include <func.h>
#define NUM 10000000

void* threadFunc(void* arg);

int n = 0;

int main(int argc, char* argv[]) {

    pthread_t tid;
    // int* -> void*
    pthread_create(&tid, NULL, threadFunc, &n);

    for (int i=0; i < NUM; ++i) {
        ++n;
    }

    pthread_join(tid, NULL);

    printf("n = %d\n", n);

    return 0;
}


void* threadFunc(void* arg) {
    int* n = (int*) arg;

    for (int i=0; i < NUM; ++i) {
        ++(*n);
    }

    return NULL;
}
