#include<stdio.h>
int main36() {
	int num, i, j, tmp, arr[100] = { 0, };
	int income = 0;

	scanf("%d", &num);



	for (i = 0; i < num; i++) {
		scanf("%d", &arr[i]);
	}
	for (j = num - 1; j > 0; j--)
		for (i = 0; i < j; i++) {
			if (arr[i] > arr[i + 1]) {
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
			}
		}

	for (i = 0; i < num; i++)
		printf("%d ", arr[i]);

	return 0;
}