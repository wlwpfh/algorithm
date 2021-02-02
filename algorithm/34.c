#include<stdio.h>
int main34() {
	int num, i, j, tmp = 0, arr[100] = { 0 };

	scanf("%d", &num);

	for (i = 0; i < num; i++) {
		scanf("%d", &arr[i]);
	}

	for (i = 0; i < num - 1; i--) {
		for (j = 0; j < num - i - 1; j++)
		{
			if (arr[j] > arr[j + 1]) {
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;

			}
		}
	}

	for (i = 0; i < num; i++)
		printf("%d ", arr[i]);


	return 0;
}