#include<stdio.h>
int main25() {

	int num;
	int count[100]; int score[100] = { 0, };
	scanf("%d", &num);


	for (int i = 0; i < num; i++) {
		scanf("%d", &score[i]);
		count[i] = 1;
	}


	for (int i = 0; i < num; i++) {

		for (int j = 0; j < num; j++) {
			if (score[j] > score[i]) {
				count[i]++;
			}
		}

		printf("%d ", count[i]);
	}

	return 0;
}