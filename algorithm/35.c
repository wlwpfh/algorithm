#include<stdio.h>
#include<stdlib.h>
int main35() {
	int num;
	scanf("%d", &num);

	int i, j, tmp = 0, arr[100] = { 0, };

	for (i = 0; i < num; i++) {
		scanf("%d", &arr[i]);
	}

	for (i = 0; i < num - 1; i++) { //버블 정렬 이용 
		for (j = 0; j < num - i - 1; j++)
			if (arr[j] > 0 && arr[j + 1] < 0) {
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
	}

	for (i = 0; i < num; i++)
		printf("%d ", arr[i]);

	return 0;
}