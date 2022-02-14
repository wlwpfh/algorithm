#include<stdio.h>
#include<algorithm>

#define MAX_N 100
#define MAX_K 100000
using namespace std;

int P[MAX_N + 1][MAX_K + 1];

int main() {

	int N, K, W[MAX_N + 1], V[MAX_N + 1];
	int i, j;
	scanf("%d %d", &N, &K);

	for (i = 1; i <= N; i++)
		scanf("%d %d", &W[i], &V[i]);


	//���� W�� �´ٸ� �ְ� �ƤӤ���  

	for (i = 1; i <= N; i++) {
		P[i][0] = 0;
		for (j = 1; j <= K; j++) {
			P[0][j] = 0;

			if (j >= W[i]) //���� ��  
				P[i][j] = max(P[i - 1][j], P[i - 1][j - W[i]] + V[i]);
			else //�� ���� �� 
				P[i][j] = P[i - 1][j];
		}
	}


	printf("%d", P[N][K]);
	return 0;
}