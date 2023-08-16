#include <func.h>

void* threadFunc(void * arg);

int main(int argc, char* argv[]) {
    
    pthread_t tid1, tid2, tid3;

    pthread_create(&tid1, NULL, threadFunc, (void*) 1);
    pthread_create(&tid2, NULL, threadFunc, (void*) 2);
    pthread_create(&tid3, NULL, threadFunc, (void*) 3);

    void *retval1, *retval2, *retval3;

    pthread_join(tid1, &retval1);
    pthread_join(tid2, &retval2);
    pthread_join(tid3, &retval3);

    printf("retval1 = %ld\n", (long) retval1);
    printf("retval2 = %ld\n", (long) retval2);
    printf("retval3 = %ld\n", (long) retval3);
    return 0;

}


void* threadFunc(void * arg) {
    long n = (long) arg;
    
    printf("child thread, arg = %ld\n", n);

    return NULL;
}
