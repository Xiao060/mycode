#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SWAP(arr, i, j) {   \
    int tmp = arr[i];       \
    arr[i] = arr[j];        \
    arr[j] = tmp; }


void quick_sort(int arr[], int left, int right);
int print(int arr[], int n);


int main(void){

    int x[] = {6, 9, 1, 5, 2, 7, 2, 8};
    print(x, 8);

    quick_sort(x, 0, 7);
    print(x, 8);

    return 0;
}



void quick_sort(int arr[], int left, int right){
    if (left >= right) return;

    int idx = left + rand() % (right - left + 1);
    int value = arr[idx];
    SWAP(arr, left, idx);
    
    int i = left;
    int j = right;

    while (i < j){
        while (i < j && arr[j] >= value)
            j--;

        arr[i] = arr[j];

        while (i < j && arr[i] <= value)
            i++;

        arr[j] = arr[i];
    }
    arr[i] = value;

    quick_sort(arr, left, i-1);
    quick_sort(arr, i+1, right);
}


int print(int arr[], int n){
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);

    printf("\n");
}









