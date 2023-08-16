#include <func.h>

typedef struct node_s {
    int data;
    struct node_s* next;
} node_t;

typedef struct list_s {
    struct node_s* front;
    struct node_s* rear;
    int size;
} list_t;


int insert_to_tail(list_t* list, int n);
int visit_list(list_t* list);
int destory_list(list_t* list);
void* threadFunc(void* arg);


int main(int argc, char* argv[]) {
    srand(time(NULL));
   
    list_t* list = (list_t*) calloc(1, sizeof(list_t));

    for (int i=0; i < 5; ++i) {
        int num = rand() % 100;
        insert_to_tail(list, num);
        printf("%d  ", num);
    }
    printf("\n");

    pthread_t tid;
    pthread_create(&tid, NULL, threadFunc, list);
    
    pthread_join(tid, NULL);

    return 0;
}


void* threadFunc(void* arg) {
    list_t* list = (list_t*) arg;
    visit_list(list);
    return NULL;
}


int insert_to_tail(list_t* list, int n) {
    node_t* tmp = (node_t*) calloc(1, sizeof(node_t));
    ERROR_CHECK(tmp, -1, "calloc");
    tmp->data = n;

    if (list->size == 0) {
        list->front = tmp;
    } else {
        list->rear->next = tmp;
    }
    
    list->rear = tmp;
    list->size++;

    return 0;
}


int visit_list(list_t* list) {
    node_t* curr = list->front;

    while (curr) {
        printf("%d  ", curr->data);
        curr = curr->next;
    }
    printf("\n");

    return 0;
}


int destory_list(list_t* list) {
    
    node_t* curr = list->front;
    node_t* next;

    while (curr) {
        next = curr->next;
        free(curr);
        curr = next;
    }
    free(list);

    return 0;
}







