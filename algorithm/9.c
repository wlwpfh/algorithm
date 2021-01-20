#include<stdio.h>
int cnt[50000];
int main9() {

	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i % j == 0)
				cnt[i - 1]++;
		}
	} 

	for (int i = 1; i <= n; i++)
		printf("%d ", cnt[i - 1]);


	return 0;
}