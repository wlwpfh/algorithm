#include<stdio.h>
#define MOD 100000

using namespace std;

int W, H;
long long dp[101][101][4];
// 아래 -> 아래 0 
// 오른쪽 -> 아래 1
// 오른쪽 -> 오른쪽 2 
// 아래 -> 오른쪽 3   
int main() {
	int answer = 0;
	scanf("%d %d", &W, &H);

	for (int i = 1; i <= H; i++)
		dp[i][1][0] = 1;

	for (int j = 1; j <= W; j++)
		dp[1][j][2] = 1;

	for (int i = 2; i <= H; i++) {
		for (int j = 2; j <= W; j++) {
			//위에서 이동  
			//아래아래로 갈려면 전에 아래아래 or 오른쪽 아래로 와야 함.  
			dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1]) % MOD;
			dp[i][j][1] = dp[i - 1][j][2];
			//옆에서 ㅣ동  
			dp[i][j][2] = (dp[i][j - 1][2] + dp[i][j - 1][3]) % MOD;
			dp[i][j][3] = dp[i][j - 1][0];
		}
	}

	for (int i = 0; i < 4; i++)
		answer += dp[H][W][i];

	printf("%d", answer);

}