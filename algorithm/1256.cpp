#include<string>
#define MAX_SIZE 201

using namespace std;

int dp[MAX_SIZE][MAX_SIZE];

int combi(int n, int r) {
	if (n == r)
		return dp[n][r] = 1;
	if (r == 1)
		return dp[n][r] = n;

	return dp[n][r] = combi(n - 1, r - 1) + combi(n - 1, r);
}

int main() {
	int n, m, k;
	string answer = "";
	scanf("%d %d %d", &n, &m, &k);

	int res = combi(n + m - 1, m);
	int tmp_k = k;
	if (k > res * 2) {
		printf("-1");
		return 0;
	}
	else {
		while (answer.length() == k) {
			if (tmp_k <= res) {
				answer += "a";
				tmp_k -= 1;
				res = combi(n - 1 + m - 1, m);
			}
			else {
				answer += "z";
				tmp_k -= 1;
				res = combi(n + m - 1 - 1, m - 1);
			}
		}
	}

	printf("%s", answer.c_str());


	return 0;
}