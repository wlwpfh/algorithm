#include<stdio.h>

using namespace std;

int X;

int main() {
	scanf("%d", &X);

	int answer = 0;

	for (int i = 0; i <= 6; i++) {
		if (X & (1 << i))
			answer++;
	}

	printf("%d", answer);

	return 0;
}