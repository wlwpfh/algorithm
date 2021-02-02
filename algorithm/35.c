#include<stdio.h>
#include<stdlib.h>
int main() {
	int num;
	scanf("%d", &num);

	int i, count = 0, tmp = 0, arr[100] = { 0, };

	for (i = 0; i < num; i++) {
		scanf("%d", &arr[i]);

		if (arr[i] > 0)
			count++;
	}

	for (i = 0; i < num; i++) {
		if (arr[i] > 0) {
			arr[num - 1 - i - count] = arr[i];
			arr[i] = 0;
		}
		printf("%d ", arr[i]);
	}

	for (i = 0; i < 100; i++)
		if (arr[i] != 0)
			printf("%d ", arr[i]);

	return 0;
}