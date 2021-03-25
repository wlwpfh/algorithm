#include<stdio.h>

void recursive(int num) {

	if (num == 0) {
		return;
	}
	else {
		recursive(num - 1);
		printf("%d ", num);
	}

}
int main56_() {
	int num;

	scanf("%d", &num);

	recursive(num);

	return 0;
}