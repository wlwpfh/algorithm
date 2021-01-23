#include<stdio.h>
int main017() {

	bool ans[10];

	int n, i;
	scanf("%d", &n);

	int num, sum;

	for (i = 0; i < n; i++) {
		scanf("%d %d", &num, &sum);

		int count;
		int count_sum = 0;

		for (count = 1; count <= num; count++) {
			count_sum += count;
		}

		if (count_sum == sum) {
			ans[i] = true;
		}

	}
	for (i = 0; i < n; i++)
		if (ans[i] == true)
			printf("YES \n");
		else
			printf("NO \n");

	return 0;
}