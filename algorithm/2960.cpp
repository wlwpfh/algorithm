#include<stdio.h>
#include<cmath>

using namespace std;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	int arr[n + 1];

	int i, j;
	for (i = 2; i <= n; i++)
		arr[i] = i;

	for (i = 2; i <= sqrt(n); i++) {
		if (arr[i] == 0)
			continue;

		for (j = i * i; j <= n; j += i)
			arr[j] = 0;
		printf("i: %d ,j:%d, arr[j]=%d \n", i, j, arr[j]);
	}

	return 0;
}