#include <func.h>

void* threadFunc(void* arg);

int main(int argc, char* argv[]) {
    pthread_t tid;
    int ret = pthread_create(&tid, NULL, threadFunc, NULL);
    THREAD_ERROR_CHECK(ret, "pthread_create");

    printf("I am main thread, tid = %lu\n", pthread_self());

    sleep(1);
    /* usleep(20); */

    return 0;
}

void* threadFunc(void* arg) {
    printf("I am child thread, tid = %lu\n", pthread_self());

    return NULL;
}
