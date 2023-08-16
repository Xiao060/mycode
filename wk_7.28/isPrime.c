#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool isPrime(long long n);

int main(void){
  
  long long n;
  /* scanf("%d", &n); */
  
  while(scanf("%d", &n)){
    bool x = isPrime(n);
    if (x)
      printf("%d is Prime!\n", n);
    else 
      printf("%d is not prime\n");
    
  }
  

  return 0;
}


bool isPrime(long long n){
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
