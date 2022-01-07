#include<stdio.h>
#define MOD 10007
using namespace std;

int arr[1001][1001];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	arr[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		arr[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j]) % MOD;
		}
	}

	printf("%d", arr[n][k]);

	return 0;
}