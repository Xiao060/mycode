#include <func.h>

int global = 100;

void* threadFunc(void* arg);

int main(int argc, char* argv[]) {
    pthread_t tid;
    int ret = pthread_create(&tid, NULL, threadFunc, NULL);
    THREAD_ERROR_CHECK(ret, "pthread_create");

    sleep(1);

    printf("I am main thread, tid = %lu, global = %d\n", 
           pthread_self(), global++);

    sleep(1);

    return 0;
}

void* threadFunc(void* arg) {
    printf("I am child thread, tid = %lu, global = %d\n", 
           pthread_self(), global++);

    return NULL;
}
