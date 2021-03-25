#include<stdio.h>
void binary(int num) {
	int rest;
	if (num < 1) {
		return;
	}
	else {
		num = num / 2;
		rest = num % 2;
		printf("%d", rest);
		binary(num);

	}
}
int main() {
	int num;
	scanf("%d", &num);
	binary(num);
	return 0;
}