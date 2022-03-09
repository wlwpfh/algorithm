#include<stdio.h>
#include<algorithm>
#define MAX_N 100000

using namespace std;

int N, M;
int money[MAX_N];

bool findMinMoney(int amount) {
	int counts = 1;
	//���� ����. �ش� ���� �� �� �ִ��� 
	//��� ����� �ؼ� �������� �����ϸ� true 
	int remain = amount;
	//�ִ��� ���� �ϴ� �־�α�  
	for (int i = 0; i < N; i++) {

		if (remain < money[i]) { //���� ���� ������ ��� -> ����   
			remain = amount;
			counts++;
		}
		remain -= money[i]; //�Ϸ絿�� �� ����  
		//printf("money: %d, ���� ���� �� remain: %d, count:%d \n",money[i],remain,counts);

	}

	return counts <= M;
}

int main() {

	int i;
	int left = 0;
	long long right = 0, mid;
	//left:�ּ����� ��, right: �ִ����� ��  
	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++) {
		scanf("%d", &money[i]);
		left = max(left, money[i]);
		right += money[i];
	}

	//printf("left:%d right:%d \n",left,right);


	while (left <= right) {
		mid = (left + right) / 2;

		if (findMinMoney(mid)) {
			right = mid - 1;

		}
		else {
			left = mid + 1;

		}
	}

	printf("%lld", left);

	return 0;
}