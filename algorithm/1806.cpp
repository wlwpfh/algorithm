#include<stdio.h>
#include<algorithm>
using namespace std;

int arr[100001];

int main() {


	int ans, tmp = 0;
	int n, s, left = 0, right = 0;

	scanf("%d %d", &n, &s);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	ans = n + 1;

	while (1) {

		if (tmp >= s) {
			ans = min(ans, right - left);
			tmp -= arr[left++];
			//왼쪽을 한 칸 이동시키고 왼쪽 값을 빼기  
		}
		else if (right >= n) {
			break;
		}
		else {
			tmp += arr[right++];
			//미만인 경우 right를 포함시키고 sum에 right값 더 하기  
		}
	}

	printf("%d", ans == n + 1 ? 0 : ans);
	return 0;
}