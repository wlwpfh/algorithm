#include<stdio.h>
#include<string.h>
int main6() {

	char c[50];


	scanf("%s", &c);
	int num = 0;

	int a = strlen(c);

	for (int i = 0; i < a; i++) {
		if ((c[i] - 48) >= 0 && (c[i]) <= 57) { //자연수인 경 
			num = 10 * num + (c[i] - 48);
		}
		else {
			;
		}
	}
	printf("%d ", num);

	int count = 0;

	for (int i = 1; i <= num; i++) {
		if (num % i == 0) {
			count++;
		}
	}
	printf("%d", count);
	return 0;
}