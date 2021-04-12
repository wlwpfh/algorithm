#include<stdio.h>
int arr[11], num, total = 0, count = 0;

int path[11];

void makingTotal(int level, int tmp) {
	if (level == num + 1) {
		if (tmp == total) {
			count++;

			for (int i = 1; i <= num; i++) {
				printf("%d ", path[i]);
			}
			printf("\n");
		}

	}
	else {
		path[level] = arr[level];
		makingTotal(level + 1, tmp + arr[level]);
		path[level] = -arr[level];
		makingTotal(level + 1, tmp - arr[level]);
		path[level] = 0;
		makingTotal(level + 1, tmp);
	}


}

int main61_2() {

	int i;

	scanf("%d %d", &num, &total);

	for (i = 1; i <= num; i++) {
		scanf("%d", &arr[i]);

	}

	makingTotal(1, 0);

	if (count == 0) {
		printf("-1");
	}
	else {
		printf("%d", count);
	}

	return 0;
}