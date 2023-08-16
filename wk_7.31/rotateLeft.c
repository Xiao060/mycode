#include <stdio.h>

void rotateLeft(int arr[], int n, int k);
int next_idx(int idx, int n, int k);
void print(int arr[], int n);


int main(void) {
    int nums[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };

    rotateLeft(nums, 9, 3);

    print(nums, 9); 

    return 0;
}


void rotateLeft(int arr[], int n, int k) {
    if (k == 0)
        return;

    int max = n > k ? n : k;
    int min = n < k ? n : k;

    // 求最大公约数
    while (min != 0) {
        int tmp = min;
        min = max % min;
        max = tmp;
    }

    int idx, store_idx, tmp, idx_value;
    for (int i = 0; i < max; ++i) {
        idx = i;
        store_idx = next_idx(idx, n, k);
        idx_value = arr[idx]; 

        while (1) {
            tmp = arr[store_idx];
            arr[store_idx] = idx_value;
            idx_value = tmp;
            idx = store_idx;
            store_idx = next_idx(idx, n, k);

            if (idx == i)
                break;
        }
    }
}

// 根据 idx 求移位后的索引
int next_idx(int idx, int n, int k) {
    int new_idx = idx - k;

    while (new_idx < 0)
        new_idx += n;

    return new_idx; 
}


void print(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

