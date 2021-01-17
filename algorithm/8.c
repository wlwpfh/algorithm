#include<stdio.h>
#include<string.h>
int main8() {
	char c[30];

	scanf("%s", &c);
	
	int balanced = 0;

	for (int i = 0; i < strlen(c); i++) {
		if (c[i] == '(') {
			
			balanced++;
		}
		if (c[i] == ')') {
			
			balanced--;
		}
	}

	if (balanced == 0) {
		printf("YES");
	}
	else
		printf("NO");

	return 0;
}