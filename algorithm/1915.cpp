#include<stdio.h>
#include<algorithm>
#define MAX
using namespace std;

// 정사각형이니까 가로세로의 길이가 같아야 함. 
// 누적해서 업데이트  
int N, M;
int dp[1001][1001] = { 0, };

int setMin(int a, int b, int c) {
	int n = a;
	if (n > b)
		n = b;
	if (n > c)
		n = c;
	return n;

}

int main() {
	int i, j;
	int ans = 0;
	scanf("%d %d", &N, &M);
	int map[N][M] = { 0, };
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++) {
			scanf("%1d", &map[i][j]);
			dp[i][j] = map[i][j];

			if (dp[i][j] == 1) {
				dp[i][j] += setMin(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
				//printf("dp[%d][%d]=%d \n",i,j,dp[i][j]);
				//자신의 근처 값들로 확인하기
				// 그 중 가장 작은 값을 가지고 있는 것을 가져오기 
				ans = max(ans, dp[i][j]);
			}
		}
	}



	printf("%d", ans * ans);
	return 0;
}

// 반례
//3 3
//000
//000
//100 