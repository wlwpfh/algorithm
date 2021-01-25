#include<stdio.h>
int main19() {
	int num;
	scanf("%d", &num);

	int height[100] = { 0 };

	int max, count = 0;

	for (int i = 0; i < num; i++) {
		scanf("%d", &height[i]);
	}

	max = height[num - 1];

	for (int i = num - 1; i >= 0; i--) {
		if (height[i] > max)
		{
			max = height[i];
			count++;
		}
	}
	printf("%d", count);


	return 0;
}