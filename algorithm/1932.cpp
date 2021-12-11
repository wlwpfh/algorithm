#include<stdio.h>
#include<algorithm>
using namespace std;
//왼쪽과  오른쪽인지 확인하기  
int arr[501][501];
int dp[501][501] = { 0, };
int main() {

	int i, j, n;
	scanf("%d", &n);
	int answer;
	for (i = 0; i < n; i++) {
		for (j = 0; j <= i; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	dp[0][0] = arr[0][0];
	for (i = 1; i < n; i++) {
		for (j = 0; j < n - 1; j++) {
			dp[i][j] = dp[i - 1][j] + max(arr[i - 1][j], arr[i - 1][j + 1]);
			printf("dp[%d][%d]=%d \n", i, j, dp[i][j]);
		}

	}

	int max = 0;
	for (i = 0; i < 501; i++) {
		if (max < dp[n - 1][i])
			max = dp[n - 1][i];
	}
	printf("%d", max);


	return 0;
}