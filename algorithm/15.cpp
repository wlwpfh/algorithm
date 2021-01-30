#include<stdio.h>
int main015() {
	int num;

	scanf("%d", &num);

	int top;

	int sum_count = 0;
	int i;
	bool check;
	for (top = 2; top <= num; top++)
	{
		check = true;

		for (i = 2; i * i <= top; i++) {
			if (top % i == 0)
			{
				check = false;
				break;
			}
		}
		if (check == true)
		{
			sum_count++;
			//printf("소수는 %d입니다. \n",top);
		}
	}
	printf("%d", sum_count);

	return 0;
}