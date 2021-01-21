#include<stdio.h>
int digit_sum(int x);
int main10() {
	int n;
	int m;
	int sum;
	scanf("%d", &n);

	int max_num=0;
	int max = -2000000;

	for (int i = 0; i < n; i++) {
		scanf("%d", &m);

		sum = digit_sum(m);

		if (sum > max)
		{
			max = sum;
			max_num = m;
		}
		else if (sum == max) {
			if (m >= max_num)
				max_num = m;
		}
		else
			;
	}

	printf("%d", max_num);

	return 0;
}
int digit_sum(int x) {
	int tmp = 0;
	int sum = 0;

	while (x > 0) {
		tmp = x % 10;
		sum = sum + tmp;
		x = x / 10;
	}

	return sum;

}