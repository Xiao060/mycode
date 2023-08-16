#include <func.h>

void func(void);
void* threadFunc(void* arg);

int main(int argc, char* argv[]) {

    func();
    sleep(5);
    return 0;
}

void func(void) {
    char* s = (char*) malloc(1024);
    strcpy(s, "Hello World!");
    
    pthread_t tid;
    pthread_create(&tid, NULL, threadFunc, s);

    free(s);
}

void* threadFunc(void* arg) {

    sleep(1);

    char* s = (char*) arg;
    puts(s);

    return NULL;
}
