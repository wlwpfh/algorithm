#include<stdio.h>
#define MAX_N 100000

using namespace std;

int N, M;
long long sum[MAX_N + 1];

int main() {
	int a, b, i, tmp, j, k;
	scanf("%d %d", &N, &M);

	sum[0] = 0;
	for (i = 1; i <= N; i++) {
		scanf("%d", &tmp);

		sum[i] = tmp + sum[i - 1];
	}

	for (i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);

		printf("%lld\n", sum[b] - sum[a - 1]);

	}


	return 0;
}