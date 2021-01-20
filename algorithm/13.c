#include<stdio.h>
#include<string.h>
int main13() {
	char num[100];

	scanf("%s", &num);

	int count[10] = { 0, };

	for (int i = 0; i < strlen(num); i++) {
		count[num[i] - 48]++;
	}

	int max = 0;

	for (int i = 1; i < 10; i++) {
		if (count[i] >= count[max]) {
			max = i;
		}
		else
			;
	}

	printf("%d", max);

	return 0;
}