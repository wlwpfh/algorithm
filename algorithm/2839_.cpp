#include<stdio.h>

using namespace std;

int N;

int main() {
	scanf("%d", &N);

	int count = 0;

	while (N >= 0) {
		printf("N: %d, count:%d \n", N, count);
		if (N % 5 == 0) {
			count += (N / 5);
			printf("%d", count);
			return 0;

		} //5kg가 더 유리하니까  
		N -= 3;
		count++;
	}
	printf("-1");

	return 0;

}