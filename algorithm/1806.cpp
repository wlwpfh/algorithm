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
			//������ �� ĭ �̵���Ű�� ���� ���� ����  
		}
		else if (right >= n) {
			break;
		}
		else {
			tmp += arr[right++];
			//�̸��� ��� right�� ���Խ�Ű�� sum�� right�� �� �ϱ�  
		}
	}

	printf("%d", ans == n + 1 ? 0 : ans);
	return 0;
}