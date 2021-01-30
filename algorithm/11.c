#include<stdio.h>
int main11() {
	int num, i;
	scanf("%d", &num);
	int count = 0;

	for (i = 1; i <= num; i++) { //입력한 해당 수도 포함해야 함. 
		int tmp = i;
		while (tmp > 0) {
			tmp = tmp / 10;
			count++;
		}
	}

	printf("%d\n", count);

	return 0;
}