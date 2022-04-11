#include<string>
#define MAXN 100
#define MAXK 1000000000
using namespace std;

int dp[MAXN * 2 + 1][MAXN + 1];
//n이 제일 클 것이고 n+m을 해봤자 2n과 같거나 작기 때문에 2maxn+1로 설정했음. 

int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	n += m;
	//n은 a의 개수, m은 z의 개수
	//현재 n은 a와 z의 개수를 합친 것  
	dp[0][0] = 1;

	for (int i = 1; i <= n; i++) {
		dp[i][0] = 1;
		//조합할 때 iC0은 1이니까  
		for (int j = 1; j <= n; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];

			if (dp[i][j] > MAXK)
				dp[i][j] = MAXK;
			//해당 수가 넘어갈 경우  
		}
	} //조합으로 푸는 것  
	//nCr= n-1Cr-1 +n-1Cr;
	//a와 z를 이용하여 만들어낼 수 있는 가지수  

	if (dp[n][m] < k) {
		printf("-1 \n");
		return 0;
	}//문자열의 길이가 k보다 안되는 경우
	//다 했는데 만들 수 있는 가지수가 더 적은 경우   

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++)
			printf("%d ", dp[i][j]);
		printf("\n");
	}

	while (n) {
		//길이가 n이니까 문자 하나씩 출력
		//k번째 문자열   
		if (dp[n - 1][m] >= k)
			printf("a");
		//
		else {
			printf("z");
			k -= dp[n - 1][m--];

		}


		n--;
		//길이를 하나씩 줄여나간다.  
	}



	return 0;
}