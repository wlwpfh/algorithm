#include<stdio.h>
#include<vector>
using namespace std;

int K;
vector<pair<int, int> >dp(46);

int main() {

	int count_push = 0, i;

	scanf("%d", &K);

	// b-> ba로 a->b로 .. 
	// a = 0 ,b= 1;


	dp[0].first = 1; //a
	dp[0].second = 0; //b

	dp[1].first = 0;
	dp[1].second = 1;
	//처음엔 a로 시작했음 

	//for문을 돌면서 직전의 dp배열이 어떤 값을 갖고 있는지 보고 
	// 만약 b라면 ba로 바꿔야 함. 

	for (i = 2; i <= K; i++) {
		dp[i].first = dp[i - 2].first + dp[i - 1].first;
		dp[i].second = dp[i - 2].second + dp[i - 1].second;
	}



	printf("%d %d", dp[K].first, dp[K].second);

	return 0;
}