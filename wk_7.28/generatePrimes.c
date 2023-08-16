#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

bool isPrime(long long n);
long long* generatePrimes(int n);
void print(long long* nums, int n);

int main(void) {

	int n;
	scanf("%d", &n);

	long long* nums = generatePrimes(n);

	print(nums, n);

	return 0;
}



bool isPrime(long long n) {
	if (n == 2 || n == 3)
		return true;

	int reminder = n % 6;
	if (reminder != 1 && reminder != 5) {
		return false;
	}

	for (int i = 2; i <= sqrt(n); ++i)
		if (n % i == 0)
			return false;

	return true;
}




long long* generatePrimes(int n) {
	long long* nums = malloc(sizeof(long long) * n);

	if (n < 1) {
		printf("Error: n should be >= 1!\n");
		exit(0);
	}

	for (int i = 0; i < n && i < 2; ++i)
			nums[i] = i + 2; 

	if (n <= 2) 
		return nums; 
		
	int size = 2;
	long long tmp;
	for (long long i = 6; ; i += 6) {
		tmp = i - 1;
		if (size < n && isPrime(tmp)) {
			nums[size] = tmp;
			size++;
		}

		if (size == n)
			return nums;

		tmp = i + 1;
		if (size < n && isPrime(tmp)) {
			nums[size] = tmp;
			size++;
		}

		if (size == n)
			return nums;
	}
}

void print(long long* nums, int n) {
	for (int i = 0; i < n; ++i)
		printf("%lld ", nums[i]);
	printf("\n");
}










