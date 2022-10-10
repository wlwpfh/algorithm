#include<stdio.h>
#define MOD 100000

using namespace std;

int W, H;
long long dp[101][101][4];
// �Ʒ� -> �Ʒ� 0 
// ������ -> �Ʒ� 1
// ������ -> ������ 2 
// �Ʒ� -> ������ 3   
int main() {
	int answer = 0;
	scanf("%d %d", &W, &H);

	for (int i = 1; i <= H; i++)
		dp[i][1][0] = 1;

	for (int j = 1; j <= W; j++)
		dp[1][j][2] = 1;

	for (int i = 2; i <= H; i++) {
		for (int j = 2; j <= W; j++) {
			//������ �̵�  
			//�Ʒ��Ʒ��� ������ ���� �Ʒ��Ʒ� or ������ �Ʒ��� �;� ��.  
			dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1]) % MOD;
			dp[i][j][1] = dp[i - 1][j][2];
			//������ �ӵ�  
			dp[i][j][2] = (dp[i][j - 1][2] + dp[i][j - 1][3]) % MOD;
			dp[i][j][3] = dp[i][j - 1][0];
		}
	}

	for (int i = 0; i < 4; i++)
		answer += dp[H][W][i];

	printf("%d", answer);

}