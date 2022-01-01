#include<stdio.h>

using namespace std;

int n, k;
int num[11][11];
int dp(int a, int b) {
	if (a == b || b == 0)
		return 1;
	else {
		return dp(a - 1, b - 1) + dp(a - 1, b);
	}
}

int main() {
	scanf("%d %d", &n, &k);

	printf("%d", dp(n, k));

	return 0;
}