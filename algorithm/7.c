#include<stdio.h>
#define EOF (-1)
int main7() {

	char c[100];

	scanf("%s", &c);

	for (int i = 0; c[i]!=EOF; i++) {
		if (c[i] >= 65 && 90 >= c[i]) {
			printf("%c", c[i] + 32);
		}
		else if (c[i] >= 97 && 122 >= c[i]) {
			printf("%c", c[i]);
		}
		else {
			;
		}
	}

	return 0;
}