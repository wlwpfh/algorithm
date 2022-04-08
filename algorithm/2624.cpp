#include<stdio.h>

using namespace std;

int T, K;
int p[102];
int n[102];
int DP[10005];

int main() {
	int i, j, l;

	scanf("%d", &T); //금액 
	scanf("%d", &K); //동전의 가지 수  

	for (i = 0; i < K; i++)
		scanf("%d %d", &p[i], &n[i]);
	//동전의 금액과 개수 

	DP[0] = 1;



	for (i = 0; i < K; i++) {
		//총 동전 가지의 수를 탐색 

		for (j = T; j >= 0; j--) {
			//만들려고 하는 값


			for (l = 1; l <= n[i]; l++) {
				//해당 동전의 개수  
				if (j - p[i] * l >= 0)
					//현재 돈의로 최대 낼 수 있는지 

					DP[j] += DP[j - p[i] * l];
				else
					break;
			}
		}
	}

	//처음에는 dp값이 없고 우측이 dp[0]=1이 되어야 좌측값이 그 때서야 수가 증가하고
	//이게 계속 반복되면 결국 됨... 

	printf("%d", DP[T]);


	return 0;
}