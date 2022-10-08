#include<stdio.h>

using namespace std;

int N, M;

int main() {

	while (1) {
		scanf("%d %d", &N, &M);

		if (N == 0 && M == 0)
			break;

		if (N < M)
			for (int i = 1; i * N < 10000; i++) {
				if (M == i * N) {
					printf("factor\n");
					break;
				}
			}
		else if (N > M && N % M == 0)
			printf("multiple\n");
		else
			printf("neither\n");
	}

	return 0;
}