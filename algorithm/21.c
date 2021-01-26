#include<stdio.h>
int main21() {

	int a[10]; int b[10];
	int a_sum = 0, b_sum = 0;
	char last_win; int d = 0;
	for (int i = 0; i < 10; i++) {
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < 10; i++) {
		scanf("%d", &b[i]);
	}

	for (int i = 0; i < 10; i++) {
		if (a[i] > b[i]) {
			last_win = 'A';
			a_sum += 3;
		}
		else if (a[i] == b[i]) {
			a_sum++;
			b_sum++;
			d++;
		}
		else {
			last_win = 'B';
			b_sum += 3;
		}
	}


	printf("%d %d \n", a_sum, b_sum);
	if (a_sum > b_sum)
		printf("A \n");
	else if (b_sum > a_sum)
		printf("B \n");
	else if (d == 10)
		printf("D \n");
	else
		printf("%c \n", last_win);

	return 0;
}