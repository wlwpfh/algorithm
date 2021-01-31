#include<stdio.h>
int main29() {
	int num;
	scanf("%d", &num); //100000
	int count = 0;

	int i, tmp, digit;
	for (i = 1; i <= num; i++) {
		tmp = i;

		while (tmp > 0) {
			digit = tmp % 10;
			if (digit == 3) count++;
			tmp = tmp / 10;
		}
	}
	printf("%d", count);

	return 0;
}