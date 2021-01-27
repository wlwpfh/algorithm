#include<stdio.h>
int order[10000];
int main26() {
	int num;
	scanf("%d", &num);
	int i; int count = 1;
	scanf("%d", &order[0]);
	printf("1 ");

	for (i = 1; i < num; i++) {
		count = 1;
		scanf("%d", &order[i]);

		for (int j = 0; i > j; j++) {
			if (order[j] >= order[i])
			{
				count = count + 1;

			}

		}
		printf("%d ", count);

	}

	return 0;
}