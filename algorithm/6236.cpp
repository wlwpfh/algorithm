#include<stdio.h>
#include<algorithm>
#define MAX_N 100000

using namespace std;

int N, M;
int money[MAX_N];

bool findMinMoney(int amount) {
	int counts = 1;
	//돈이 들어옴. 해당 돈이 할 수 있는지 
	//모든 경우들로 해서 가능한지 가능하면 true 
	int remain = amount;
	//최대의 돈을 일단 넣어두기  
	for (int i = 0; i < N; i++) {

		if (remain < money[i]) { //가진 돈이 부족한 경우 -> 인출   
			remain = amount;
			counts++;
		}
		remain -= money[i]; //하루동안 돈 쓰기  
		//printf("money: %d, 쓰고 남은 돈 remain: %d, count:%d \n",money[i],remain,counts);

	}

	return counts <= M;
}

int main() {

	int i;
	int left = 0;
	long long right = 0, mid;
	//left:최소한의 돈, right: 최대한의 돈  
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