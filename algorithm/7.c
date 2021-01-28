#include<stdio.h>
int main7() {

	char c[100];

	gets(c);

	for (int i = 0; c[i] != '\0'; i++) {
		if ((c[i] - 65) >= 0 && 25 >= (c[i]) - 65) {
			printf("%c", c[i] + 32);
		}
		else if ((c[i] - 97) >= 0 && 25 >= (c[i] - 97)) {
			printf("%c", c[i]);
		}
		else {
			;
		}
	}

	return 0;
}