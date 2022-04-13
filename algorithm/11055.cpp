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
				//dp[i]���� ������� ���� ���� �ְ� �� �����߿� �ϳ��� �ϴ� j���� ���� ���߿��� arr[i]�� ������ �� Ŀ���ϱ�  
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