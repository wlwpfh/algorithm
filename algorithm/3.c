#include<stdio.h>
int main3() {
	int n;
	int sum = 1;

	scanf("%d", &n);

	printf("1 ");

	for (int i = 2; i <= (n / 2) ; i++) {
		if (n % i == 0) {
			printf("+ %d ", i);
			sum += i;
		}
		
	}
	
	
	printf("= %d", sum);


	return 0;
}