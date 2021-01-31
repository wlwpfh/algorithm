#include<stdio.h>
#include<vector>
int main28() {

	int num;
	int i, j, tmp;
	scanf("%d", &num);
	int two = 0, five = 0;
	for (i = 2; i <= num; i++) {
		tmp = i;
		j = 2;

		while (1) { //소인수분해 과정
			if (tmp % j == 0)
			{
				if (j == 2)
					two++;
				else if (j == 5)
					five++;
				tmp = tmp / j;
			}
			else
				j++;

			if (tmp == 1)
				break;

		}
	}
	if (two < five)
		printf("%d \n", two);
	else
		printf("%d \n", five);

	return 0;
}