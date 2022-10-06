#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int N, dp[1001];
vector<int> v;

int main() {
	int tmp, answer = 0;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &tmp);
		v.push_back(tmp);
	}

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (v[j] < v[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		answer = max(answer, dp[i]);
	}

	printf("%d", answer + 1);

	return 0;
}