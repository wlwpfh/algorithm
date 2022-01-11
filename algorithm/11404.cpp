#include<stdio.h>
#include<cstring>
#define INF 987654321
#define MAX_SIZE 100
using namespace std;

int N, M;
int dp[MAX_SIZE + 1][MAX_SIZE + 1];

int main() {
	int i, j, k;
	int a, b, c;
	scanf("%d", &N);
	scanf("%d", &M);

	memset(dp, INF, sizeof(dp));

	for (i = 1; i <= N; i++) {
		dp[i][i] = 0;
	}

	for (i = 0; i < M; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if (dp[a][b] > c)
			dp[a][b] = c;
	}

	for (i = 1; i <= N; i++) {
		//출발지  
		for (j = 1; j <= N; j++) {
			//목적지  
			for (k = 1; k <= N; k++) {
				//중간 경유  
				if (i == j || j == k)
					continue;
				if (dp[i][j] == INF || dp[j][k] == INF)
					continue;
				if (dp[i][k] > dp[i][j] + dp[j][k])
					dp[i][k] = dp[i][j] + dp[j][k];
			}
		}
	}

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			if (dp[i][j] == INF)
				printf("0 ");
			else
				printf("%d ", dp[i][j]);
		}
		printf("\n");
	}

	return 0;
}