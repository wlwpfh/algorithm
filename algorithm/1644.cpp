#include<stdio.h>
#include<vector>
using namespace std;
int N, answer = 0, K = 0, sum = 0;
int arr[4000001];
vector<int> v;
int main() {
	scanf("%d", &N);

	for (int i = 2; i <= N; i++) {
		arr[i] = i;
	}

	for (int i = 2; i * i <= N; i++) {
		if (arr[i] == 0)
			continue;
		for (int j = i + i; j <= N; j += i)
			arr[j] = 0;
	}
	int left = 0, right = 0;

	for (int i = 2; i <= N; i++) {
		if (arr[i] != 0)
			v.push_back(i);
	}// �Ҽ��� �ֱ�  

	while (1) {
		if (sum > N) {
			sum -= v[left++];
			//�־��� ������ ����
			//������ ��ĭ �� �̵� 
		}
		else if (right == v.size())
			break;
		//right�� ������ �� ��� (�ش� ������ �� ���)
		else {
			sum += v[right++];
		}
		if (sum == N)
			answer++;
	}
	printf("%d", answer);
	return 0;
}