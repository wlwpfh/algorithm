#include<stdio.h>
int arr[100000] = { 0, };
int main23() {
	int num;
	scanf("%d", &num);
	int i;
	for (i = 0; i < num; i++) {
		scanf("%d", &arr[i]);
	}
	int max_distance = 1; int tmp;
	int value = 0;
	for (i = 1; i < num; i++) {
		value = arr[i] - arr[i - 1];
		if (value >= 0) {
			max_distance++;

		}
		else {
			max_distance = 1;
		}
		if (max_distance > tmp)
			tmp = max_distance;

	}
	printf("%d", tmp);
	return 0;
}