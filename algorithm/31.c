#include<stdio.h>
char ch[10000] = { 0 };
int main31() {
	int sum = 0; int j = 1;
	scanf("%s", &ch);
	int num = 0;
	for (int i = 1; ch[i] != 'H'; i++) {
		num = num * 10 + (ch[i] - 48);
		j++;
	}
	if (num == 0) num = 1;
	sum = sum + num * 12;
	num = 0;
	for (int i = j + 1; ch[i] != '\0'; i++) {
		num = num * 10 + (ch[i] - 48);
	}
	if (num == 0) num = 1;
	sum = sum + num * 1;
	printf("%d", sum);
	return 0;
}