#include<stdio.h>

using namespace std;

int n, result = 0;
int t[16], p[16];

void dfs(int level, int sum) {
	if (level == n + 1) {
		if (sum > result)
			result = sum;
	}
	else {
		if (level + t[level] <= n + 1)
			dfs(level + t[level], sum + p[level]);

		dfs(level + 1, sum);
	}

}

int main() {
	scanf("%d", &n);
	int i;
	for (i = 1; i <= n; i++) {
		scanf("%d %d", &t[i], &p[i]);

	}

	dfs(1, 0);

	printf("%d", result);

	return 0;
}