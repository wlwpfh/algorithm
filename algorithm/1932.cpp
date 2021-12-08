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
	for (i = 0; i < n - 1; i++) {
		for (j = i - 1; j < i; j++) {
			dp[i + 1][j] = dp[i + 1][j] + max(arr[i][j], arr[i][++j]);
			printf("dp[%d][%d]=%d \n", i, j, dp[i][j]);
		}

	}

	//	printf("%d", max(dp[n-1][0], dp[n-1][n-1]));


	return 0;
}