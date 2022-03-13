#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int N, M;
int arr[300];
int max_value;//����� �ִ� 
bool findMaxSum(int mid) {
	int sum = 0, counts = 1;

	for (int i = 0; i < N; i++) {
		sum += arr[i];

		if (sum > mid) {
			sum = arr[i]; //�̰͸� ���� 
			counts++;
		}
		//printf("sum:%d, mid:%d, count:%d \n",sum, mid, counts);
	}

	return counts <= M;
}

int main() {

	scanf("%d %d", &N, &M);
	int max_value = 0, sum = 0, i, ans = 0;
	//������ ���� ������ �ִ�, N���� �Է��� ��  
	for (i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		max_value = max(max_value, arr[i]);
		sum += arr[i];
	}

	int left = max_value;
	int right = sum;


	while (left <= right) {
		int mid = (left + right) / 2;

		if (findMaxSum(mid)) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	printf("%d \n", left);
	//�� �׷��� ���ϱ�  
	sum = 0;
	for (i = 0; i < N; i++) {
		sum += arr[i];
		if (sum > left) {
			M--; //�׷� ���� ���� ���ؼ� 
			sum = arr[i];
			printf("%d ", ans);
			ans = 0; //�ٸ� �ɷ� �ٲٱ� ���ؼ�  
		}
		ans++; //�ϴ� ��� �� ���� �ϱ� ���ؼ� 

		if (N - i == M)
			break;
		//�ϳ��� ����ϱ� ���ؼ� 

	}

	//���� �׷쿡 �ϳ���  
	while (M) {
		printf("%d ", ans);
		ans = 1;
		M--;
	}



	return 0;
}