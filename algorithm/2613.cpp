#include<stdio.h>
#include<algorithm>
using namespace std;

int N, M;
int arr[300];

bool findMaxSum(int number) {

}

int main() {

	scanf("%d %d", &N, &M);
	int max_value = 0, sum = 0;
	//������ ���� ������ �ִ�, N���� �Է��� ��  
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		max_value = max(max_value, arr[i]);
		sum += arr[i];
	}

	int left = max_value - 1;
	int right = sum;


	while (left <= right) {
		int mid = (left + right) / 2;

		if (findMaxSum(mid))
			right = mid - 1;
		else
			left = mid + 1;
	}

	printf("%d \n", left);
	//�� �׷��� ���ϱ�  


	// ���� ���� max_value�� ������ ���Խ�Ű�� ���� �׷��� �����ٰ� �ϱ�
	//�� ������ count++�ؼ� count==M�̸� �ϴ� �Ѵ��� �ȳѴ��� Ȯ���ϱ� 




	return 0;
}