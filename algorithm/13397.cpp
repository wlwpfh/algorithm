#include<stdio.h>
#include<algorithm>

using namespace std;

int N, M, tmp_diff;
int arr[5002];

int findArea(int num) {
	//�ּ��� ���� �� �� �ִ���  
	int counts = 1, left = arr[0], right = arr[0];
	//�׳� �ϴ� �� �ʱ�ȭ  
	for (int i = 1; i < N; i++) {
		if (arr[i] < left)
			left = arr[i];
		if (arr[i] > right)
			right = arr[i]; //������� �߿��� ���� �װ��� �װŸ� ã���ϱ�
		//���� ���� �������� i��° �������� ���� ū ���� ���� ���� ���� ���ϴ� ����  

		if ((right - left) > num) {
			left = arr[i];
			right = arr[i];
			counts++;
			//�ϳ� �� ���ְ� �ʱ�ȭ  
		}
	}

	return counts <= M;
}

int main() {

	int i, max_value = 0, res = 987654321;

	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++) {
		scanf("%d", &arr[i]);

		max_value = max(max_value, arr[i]);
	}

	int left = 0, right = max_value, mid;

	while (left <= right) {
		mid = (left + right) / 2;

		if (findArea(mid)) {
			right = mid - 1;
			res = min(res, mid);
			//mid�� ���� ���� ���̴ϱ� �װŸ� res�� �����ϱ�  
		}
		else
			left = mid + 1;

	}
	printf("%d", res);

	return 0;
}