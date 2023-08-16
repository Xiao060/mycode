#include <stdio.h>
#include <stdbool.h>


bool isUglyNumber(long long n);

int main(void){

    int n;
    scanf("%d", &n);

    if (isUglyNumber(n))
        printf("%d is ugly number!\n", n);
    else 
        printf("%d is not ugly number!\n", n);

    return 0;
}

bool isUglyNumber(long long n){
    if (n <= 0)
        return false;

    while (n % 2 == 0){
        n /= 2;
    } 

    while (n % 3 == 0){
        n /= 3;
    }

    while (n % 5 == 0){
        n /= 5;
    }

    return n == 1;
}

