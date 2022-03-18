#include<stdio.h>
#include<algorithm>
#define MIN -987654321
using namespace std;

int N, M;
int arr[101];
int sum[101];
int dp[101][51];
// N까지의 index를 m개의 구간 

int main() {
	int i, j, k;

	scanf("%d %d", &N, &M);

	for (i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
		// 
		sum[i] = sum[i - 1] + arr[i];
		//누적합  
	}

	for (i = 1; i <= M; i++)
		dp[0][i] = MIN;

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			dp[i][j] = dp[i - 1][j];
			//일단  
			for (k = 1; k <= i; k++) {
				if (k >= 2)
					dp[i][j] = max(dp[i][j], dp[k - 2][j - 1] + sum[i] - sum[k - 1]);
				//i선택X & j구간 선택 , j-1번째 구간 & i선택
				// 				해당 구간의 합  
				else if (j == 1 && k == 1) {
					dp[i][j] = max(dp[i][j], sum[i]);
					//위의 식에서 k가 1인 겨ㅜ 
				}
			}
		}
	}

	printf("%d", dp[N][M]);

	return 0;
}