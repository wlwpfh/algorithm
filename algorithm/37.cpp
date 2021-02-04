#include<stdio.h>
int main() {
	int num, i, j, work, income;

	scanf("%d %d", &num, &work);

	int arr[10] = { 0 }; //0으로 초기화 

	int tmp = 0;
	for (i = 0; i < work; i++) {
		scanf("%d", &income);

		arr[0] = income;

		for (j = 0; j <= i; j++) {
			if (arr[j] == income) {
				arr[j] = 0;

				while (j > 0 && arr[j] != 0) {
					arr[j] = arr[j - 1];
					j++;
				}

			}
			else {

			}
		}

	}
	printf("\n");
	for (i = 0; i < num; i++)
		printf("%d ", arr[i]);
	return 0;
}