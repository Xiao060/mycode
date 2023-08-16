#include <stdio.h>

#define SIZE(a) (sizeof(a) / sizeof(a[0]))
int findMin(int arr[], int n);

int main(void){

    int nums1[] = {3, 4, 5, 1, 2};
    int nums2[] = {4, 5, 6, 7, 0, 1, 2};

    int min1 = findMin(nums1, SIZE(nums1));
    int min2 = findMin(nums2, SIZE(nums2));

    printf("min1 = %d\n", min1);
    printf("min2 = %d\n", min2);

    return 0;
}


int findMin(int arr[], int n){
    if (arr[0] < arr[n-1])
        return arr[0];

    int left = 0, right = n-1;

    while (left <= right){
        int mid  = left + (right - left >> 1);
        
        int cmp = arr[left] - arr[mid];
        if (cmp > 0){
            int cmp2 = arr[mid-1] - arr[mid];
            if (cmp2 < 0)
                right = mid - 1;
            else 
                return arr[mid];
        } else {
            int cmp2 = arr[mid] - arr[mid+1];
            if (cmp2 < 0)
                left = mid + 1;
            else 
                return arr[mid + 1];
        }
    }
}
