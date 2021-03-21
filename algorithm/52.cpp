#include<stdio.h>
int a[1501];
int main52_() {
	int num, i, p2, p3, p5, tmp, min = 0;

	scanf("%d", &num);

	a[1] = 1;
	p2 = p3 = p5 = 1;

	for (i = 2; i <= num; i++) {
		if (a[p2] * 2 < a[p3] * 3)
			min = a[p2] * 2;
		else
			min = a[p3] * 3;
		if (a[p5] * 5 < min)
			min = a[p5] * 5;
		if (a[p2] * 2 == min)
			p2++;
		if (a[p3] * 3 == min)
			p3++;
		if (a[p5] * 5 == min)
			p5++;

		a[i] = min;
	}

	printf("%d", a[num]);

	return 0;
}