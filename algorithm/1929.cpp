#include<stdio.h>
#include<cmath>
using namespace std;

int M, N;
bool prime[1000001];
void primeCheck(int m, int n) {
	int squre = sqrt(n);
	prime[1] = true;
	for (int i = 2; i <= squre; i++) {
		if (prime[i])
			continue;

		for (int j = i * i; j <= n; j += i)
			prime[j] = true;
	}

	for (int i = m; i <= n; i++)
		if (!prime[i])
			printf("%d \n", i);

	return;
}

int main() {

	scanf("%d %d", &M, &N);

	primeCheck(M, N);

	return 0;
}