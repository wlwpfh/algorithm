#include<stdio.h>
int main015() {
	int num;

	scanf("%d", &num);

	int top;

	int sum_count = 0;

	bool check;
	for (top = 2; top <= num; top++)
	{
		check = true;
		int i;
		for (i = 2; i < top; i++) {
			if (top % i == 0)
			{
				check = false;
				break;
			}
		}
		if (check == true)
		{
			sum_count++;
		}
	}
	printf("%d", sum_count);

	return 0;
}