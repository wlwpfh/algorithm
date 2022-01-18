#include<stdio.h>
#include<cmath>
#define MAX 1000
using namespace std;

int arr[101];
int prime[MAX + 1];
int main() {

	int i, j, N, answer = 0, max;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);

	}
	max = arr[N - 1];

	prime[0] = 0;
	prime[1] = 0;

	for (i = 2; i <= max; i++) {
		prime[i] = i;
	}

	for (i = 2; i <= sqrt(max); i++) {
		if (prime[i] == 0)
			continue;

		for (j = i * i; j <= N; j += i) {
			prime[j] = 0;
			printf("%d는 소수가 아님 \n", j);
		}
	}

	for (i = 0; i < N; i++)
		if (prime[arr[i]] != 0) {
			printf("%d가 소수 \n", arr[i]);
			answer++;
		}

	printf("%d", answer);

	return 0;
}