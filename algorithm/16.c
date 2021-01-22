#include<stdio.h>
#include<string.h>
int main16() {

	int a[55] = { 0, };
	int b[55] = { 0, };

	char input[100] = { 0 };

	scanf("%s", &input);

	for (int i = 0; input[i] != '\0'; i++) {
		if (input[i] >= 65 && 90 >= input[i]) //대문자일 때
			a[input[i] - 65]++;
		else
			a[input[i] - 71]++;

	}

	scanf("%s", &input);

	for (int i = 0; input[i] != '\0'; i++) {
		if (input[i] >= 65 && 90 >= input[i]) //대문자일 때
			b[input[i] - 65]++;
		else
			b[input[i] - 71]++;

	}

	for (int i = 0; i < 52; i++) {
		if (a[i] != b[i])
		{
			printf("NO");
			return 0;
		}
	}
	printf("YES");

	return 0;
}