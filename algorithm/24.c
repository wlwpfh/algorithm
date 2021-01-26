#include<stdio.h>
int main24() {
	int check[100] = { 0, };

	int num, first, second, diff;

	scanf("%d", &num);

	scanf("%d", &first);

	for (int i = 1; i < num; i++) {
		scanf("%d", &second);
		diff = second - first;

		if (diff > 0)
			check[diff] = 1;
		else
			check[-diff] = 1;

		first = second;
	}
	for (int i = 1; i < num; i++) {
		if (check[i] != 1)
		{
			printf("NO \n");
			return 0;
		}
	}

	printf("YES \n");

	return 0;
}