#include<stdio.h>
#include<vector>
using namespace std;

int N, K, answer;
int money[101];

int main() {

	scanf("%d %d", &N, &K);
	vector<int> dp(K + 1);
	for (int i = 1; i <= N; i++)
		scanf("%d", &money[i]);

	dp[0] = 1;

	for (int i = 1; i <= N; i++) {
		for (int j = money[i]; j <= dp.size(); j++) {
			dp[j] += dp[j - money[i]];
		}
	}

	printf("%d", dp[K]);

	return 0;
}