//#include<string>
//#define MAX_SIZE 201
//
//using namespace std;
//
//int dp[MAX_SIZE][MAX_SIZE];
//
//int combi(int n, int r) {
//	if (n == r)
//		return dp[n][r] = 1;
//	if (r == 1)
//		return dp[n][r] = n;
//
//	return dp[n][r] = combi(n - 1, r - 1) + combi(n - 1, r);
//}
//
//int main() {
//	int n, m, k;
//	string answer = "";
//	scanf("%d %d %d", &n, &m, &k);
//
//	int res = combi(n + m - 1, m);
//	int tmp_k = k;
//	if (k > res * 2) {
//		printf("-1");
//		return 0;
//	}
//	else {
//		while (answer.length() == k) {
//			if (tmp_k <= res) {
//				answer += "a";
//				tmp_k -= 1;
//				res = combi(n - 1 + m - 1, m);
//			}
//			else {
//				answer += "z";
//				tmp_k -= 1;
//				res = combi(n + m - 1 - 1, m - 1);
//			}
//		}
//	}
//
//	printf("%s", answer.c_str());
//
//
//	return 0;
//}

#include<string>
#define MAXN 100
#define MAXK 1000000000
using namespace std;

int dp[MAXN * 2 + 1][MAXN];

int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	n += m;

	dp[0][0] = 1;

	for (int i = 1; i <= n; i++) {
		dp[i][0] = 1;
		for (int j = 1; j <= i && j <= m; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];

			if (dp[i][j] > MAXK)
				dp[i][j] = MAXK;
		}
	}

	if (dp[n][m] < k) {
		printf("-1 \n");
		return 0;
	}

	while (n > 0) {
		if (dp[n - 1][m] >= k)
			printf("a");
		else {
			printf("z");
			k -= dp[n - 1][m--];
		}


		n--;
	}
	return 0;
}