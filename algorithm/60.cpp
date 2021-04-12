#include<stdio.h>

int num, arr[11], total = 0;
bool flag = false;
void subset_sum(int level, int sum) {
	if (sum > (total / 2))
		return; //넘어온 수가 큰 경우 

	if (flag == true)
		return;

	if (level == num + 1) {
		if (sum == (total - sum)) {
			flag = true;
		}
	}
	else {
		subset_sum(level + 1, sum + arr[level]);
		subset_sum(level + 1, sum);
	}
}

int main60_() {
	int i;

	scanf("%d", &num);

	for (i = 1; i <= num; i++) {
		scanf("%d", &arr[i]);
		total = total + arr[i];
	}

	subset_sum(1, 0);

	if (flag == true)
		printf("YES \n");
	else
		printf("NO \n");

	return 0;
}