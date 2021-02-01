#include<stdio.h>
int main32() {
	int num, i, arr[100] = { 0 };

	scanf("%d", &num);

	for (i = 0; i < num; i++) {
		scanf("%d", &arr[i]);
	}
	int j, temp = 0;

	for (i = 0; i < num; i++) {
		for (j = i; j < num; j++) {
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	for (i = 0; i < num; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}
////
int main32_() {
	int a[100], n, index, i, j, tmp;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (i = 0; i < n - 1; i++) {
		index = i;
		for (j = i + 1; j < n; j++) {
			if (a[j] < a[index])
				index = j; //더 작은 값의 위치
		}
		tmp = a[i];
		a[i] = a[index];
		a[index] = tmp;
	}
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
}