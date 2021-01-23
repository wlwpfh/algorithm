#include<stdio.h>
int main18() {

	int i, n, m;
	int sense;

	int count = 0;

	int max = -1;
	scanf("%d %d", &n, &m);

	for (i = 0; i < n; i++) {
		scanf("%d", &sense);

		if (sense > m)
			count++;
		else
			count = 0;

		if (count > max) //count가 0부터 해당 
			max = count;
	}
	if (max == 0)
		printf("-1 \n");
	else
		printf("%d", max);

	return 0;
}