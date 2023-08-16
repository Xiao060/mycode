#include <func.h>

typedef struct node_s {
    int val;
    struct node_s* next;
} node_t;

void* threadFunc(void* arg);


int main(int argc, char* argv[]) {

    node_t e = {9, NULL};
    node_t d = {54, &e};
    node_t c = {15, &d};
    node_t b = {34, &c};
    node_t a = {12, &b};

    pthread_t tid;
    // node_t* -> void*
    pthread_create(&tid, NULL, threadFunc, &a);


    pthread_join(tid, NULL);

    return 0;
}


void* threadFunc(void* arg) {

    node_t* curr = (node_t*) arg;

    int i = 0; 
    while (curr) {
        printf("val%d = %d\n", i++, curr->val);
        curr = curr->next; 
    } 

    return NULL;
}






