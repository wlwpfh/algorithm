#include<stdio.h>
int count[50001] = { 0 };
int main9() {

	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) { //약수의 시작이 1부터이니까  
		for (int j = i; j <= n; j = j + i) {
			count[j]++;
		}
	}

	for (int i = 1; i <= n; i++)
		printf("%d", count[i]);


	return 0;
}