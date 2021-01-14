#include<stdio.h>
int main1() {
	int n, m;
	scanf("%d %d", &n, &m);

	int sum = 0;

	for (int i = 1; i <= n; i++) {
		if ((i % m == 0) && (i>=m)) {
			sum = sum + i;
		}
	}
	printf("%d \n", sum);

	return 0;
}