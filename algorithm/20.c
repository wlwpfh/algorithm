#include<stdio.h>
int main20() {
	int a[100];
	int b[100];
	int num;
	scanf("%d", &num);

	for (int i = 0; i < num; i++)
	{
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < num; i++)
	{
		scanf("%d", &b[i]);
	}

	for (int i = 0; i < num; i++) {
		if (a[i] - b[i] == 1 || a[i] - b[i] == -2)
			printf("A \n");
		else if (a[i] - b[i] == 0)
			printf("D \n");
		else
			printf("B \n");
	}
	return 0;
}