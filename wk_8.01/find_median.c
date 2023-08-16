#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SWAP(arr, i, j) {   \
    int tmp = arr[i];       \
    arr[i] = arr[j];        \
    arr[j] = tmp; }

int quick_selection(int arr[], int left, int right, int k);
int find_median(int arr[], int n);

int main(void){

    int x[] = {6, 9, 1, 5, 2, 7, 2, 8};
    int n = find_median(x, 8);
    printf("%d\n", n);

    return 0;
}


int find_median(int arr[], int n){

    srand(time(NULL));

    int num =  quick_selection(arr, 0, n-1, n/2);
    return num;
}

int quick_selection(int arr[], int left, int right, int k){
    if (left == right) return arr[left];

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

    if (i == k-1)
        return arr[i];
    else if (i > k-1)
        quick_selection(arr, left, i-1, k);
    else
        quick_selection(arr, i+1, right, k);
}










