#include <func.h>

void* threadFunc(void* arg);
void clean_func(void * arg);

int main(int argc, char* argv[]) {

    pthread_t tid;
    pthread_create(&tid, NULL, threadFunc, NULL);

    sleep(5);

    return 0;
}

void* threadFunc(void* arg) {
    char* p = (char*) calloc(1, 1024);
    pthread_cleanup_push(clean_func, p);

    strcpy(p, "Hello World!");
    puts(p);

    pthread_exit(NULL);


    } while (0);
    } while (0);

    /* pthread_cleanup_pop(0); */

    printf("+++++++++++++++\n");

    return NULL;
}

void clean_func(void * arg) {
    char* s = (char*) arg;
    free(s);
    printf("Clear over!\n");
}













