#include<stdio.h>
#include<algorithm>
using namespace std;

int N;
int arr[1004];
int dp[1004];

int main() {
	int i, j, max_value = 0;
	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		dp[i] = arr[i];
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < i; j++) {
			if (dp[j] + arr[i] >= dp[i] && arr[i] > arr[j]) {
				//dp[i]에는 현재까지 더한 값을 넣고 그 조건중에 하나로 일단 j까지 넣은 것중에서 arr[i]를 넣으면 더 커지니까  
				dp[i] = dp[j] + arr[i];
			}
			else {
				;
			}
		}
		max_value = max(max_value, dp[i]);
	}

	printf("%d", max_value);

	return 0;
}