#include<stdio.h>
#include<stdlib.h>
int main5() {
	char num[20];

	
		scanf("%s", &num);
	

	//¿ÃÇØ: 2019³â
	int year;

	if (num[7] == '1' || num[7] == '2') {
		year = 1900 + 10 * (num[0]-48) + (num[1]-48);
	}
	else {
		year = 2000 + 10 * (num[0] - 48) + (num[1] - 48);
	}

	char sex;

	if (num[7] == '1'|| num[7] == '3')
		sex = 'M';
	else
		sex = 'W';

	printf("%d %c", 2019 - year + 1, sex);

	return 0;
}