#include <stdio.h>

typedef struct node {
    int val;
    struct node * next;
} Node;

Node* rotateRigth(Node* head, int k);
int length(Node* head);
void print(Node* head);

int main(void){

    Node f = {6, NULL};
    Node e = {9, &f};
    Node d = {4, &e};
    Node c = {5, &d};
    Node b = {3, &c};
    Node a = {2, &b};
    print(&a);
    
    Node* head = rotateRigth(&a, 2);
    print(head);

    return 0;
}


Node* rotateRigth(Node* head, int k){

    int len = length(head);
    if (k % len == 0 || !head)
        return head;

    int idx_head = len - (k % len);
    
    Node* p, * new_head;
    p = NULL;
    new_head = head;
    for (int i = 0; i < idx_head; ++i){
        p = new_head;
        new_head = new_head->next;
    }

    Node* tmp = new_head;
    while (tmp->next){
        tmp = tmp->next;
    }

    tmp->next = head;
    p->next = NULL;

    return new_head;
}


int length(Node* head){
    int nums = 0;
    while(head){
        nums++;
        head = head->next;
    }
    return nums;
}


void print(Node* head){

    while (head){
        printf("%d ", head->val);
        head = head->next;
    }

    printf("\n");
    
}
