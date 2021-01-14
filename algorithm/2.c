#include<stdio.h>
int main2() {

	int a, b;


	scanf("%d %d", &a, &b);


	int sum = 0;
	for (int i = a; i < b; i++) {
		printf("%d + ",i);
		sum = sum + i;
	}
	sum = sum + b;
	printf("%d = %d \n", b, sum);

	return 0;
}