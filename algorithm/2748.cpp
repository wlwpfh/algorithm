#include<stdio.h>

using namespace std;

long long arr[90];

int fibo(int n) {
	if (n == 1 || n == 2)
		return 1;
	if (arr[n] != 0)
		return arr[n];
	else
		arr[n] = fibo(n - 1) + fibo(n - 2);
	return arr[n];
}

int main() {


	int i, n;

	scanf("%d", &n);

	printf("%lld", fibo(n));
	return 0;
}