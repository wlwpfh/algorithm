#include<stdio.h>
void binary(int num) {
	int rest;
	if (num < 1) {
		return;
	}
	else {
		rest = num % 2;
		num = num / 2;
		binary(num);
		printf("%d", rest);

	}
}
int main() {
	int num;
	scanf("%d", &num);
	binary(num);
	return 0;
}