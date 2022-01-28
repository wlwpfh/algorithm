#include<stdio.h>
#include<algorithm>
using namespace std;
//왼쪽과  오른쪽인지 확인하기  
int arr[501][501] = { 0, };
int dp[501][501] = { 0, };
int n;

int main() {

	int i, j, sum = 0;
	scanf("%d", &n);
	int answer;
	for (i = 0; i < n; i++) {
		for (j = 0; j <= i; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	dp[0][0] = arr[0][0];

	for (i = 0; i < n; i++) {
		for (j = 0; j <= i; j++) {
			if (j == 0) {
				dp[i][j] = arr[i][j] + dp[i - 1][j];
			}
			else if (j == i) {
				dp[i][j] = arr[i][j] + dp[i - 1][j - 1];
			}
			else {
				//비교해서 더 큰 값으로 
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + arr[i][j];
			}

		}
	}


	for (i = 0; i < n; i++) {
		for (j = 0; j <= i; j++) {
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}

	for (i = 0; i < n; i++) {
		if (dp[n - 1][i] > sum)
			sum = dp[n - 1][i];
	}

	printf("%d", sum);

	return 0;
}
