#include<stdio.h>
#include<string.h>

using namespace std;

int n, m, count;
int arr[31][31];
int dp(int left, int right) {
	if (arr[left][right] != 0)
		return arr[left][right];
	if (left == right || right == 0)
		return arr[left][right] = 1;
	else {
		return arr[left][right] = dp(left - 1, right - 1) + dp(left - 1, right);
	}
}

int main() {

	int answer, test_case, i;
	scanf("%d", &test_case);
	for (i = 1; i <= test_case; i++) {
		scanf("%d %d", &n, &m);
		count = 0;
		memset(arr, 0, sizeof(arr));
		answer = dp(m, n);
		printf("%d\n", answer);
	}

	return 0;
}