#include <stdio.h>
#include <math.h>
#include <stdlib.h>


long long* generateUglyNumbers(int n);
void print(long long* nums, int n);


int main(void){

    long long* nums = generateUglyNumbers(2000);
    print(nums, 2000);
    free(nums);

    return 0;
}


long long* generateUglyNumbers(int n){
    long long* ugly_nums = malloc(sizeof(long long) * n);
    if (!ugly_nums){
        perror("generateUglyNumbers");
        return NULL;
    }
    ugly_nums[0] = 1;

    int p2, p3, p5;
    p2 = p3 = p5 = 0;

    long long tmp1, tmp2, tmp3;
    for (int i=1; i<n; i++){
        tmp1 = ugly_nums[p2] * 2;
        tmp2 = ugly_nums[p3] * 3;
        tmp3 = ugly_nums[p5] * 5;

        // 三目运算符, 可读性稍差; 两个分支可读性更好一些
        long long min = tmp1 < tmp2 ? tmp1 : tmp2;
        min = min < tmp3 ? min : tmp3;

        ugly_nums[i] = min;

        if (min == tmp1)
            p2++;

        if (min == tmp2)
            p3++;

        if (min == tmp3)
            p5++;
    }
    return ugly_nums;
}


void print(long long* nums, int n){
    for (int i=0; i<n; ++i){
        printf("%lld\n", nums[i]);
    }
}
