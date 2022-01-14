#include<stdio.h>
#include<algorithm>
#define MAX_SIZE 300
using namespace std;

int stair[MAX_SIZE + 1];
int dp[MAX_SIZE + 1];

int main() {
	int n;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &stair[i]);
	}

	dp[0] = 0; //���ٴ�
	dp[1] = stair[1];
	dp[2] = stair[1] + stair[2];

	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 3] + stair[i - 1], dp[i - 2]) + stair[i];
		//dp[3] = dp[0] + stair[2] -> �ι�° ĭ���� ���� + stair[3] => �ι�° ĭ + ����° ĭ 
		//dp[3] = dp[1] -> ù��° ĭ���� ���� => ù��° ĭ + ����° ĭ  
	}

	printf("%d", dp[n]);

	return 0;
}