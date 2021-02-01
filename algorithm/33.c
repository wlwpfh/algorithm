#include<stdio.h>
int main33() {
	int num, i, j, tmp, arr[100] = { 0 };
	scanf("%d", &num);
	for (i = 0; i < num; i++) {
		scanf("%d", &arr[i]);
	}
	for (i = 0; i < num - 1; i++) {
		for (j = i + 1; j < num; j++) {
			if (arr[j] > arr[i])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			else if (arr[i] == arr[j])
				arr[j] = 0;
		}
	}

	printf("%d", arr[2]);
	return 0;
}