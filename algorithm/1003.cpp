#include<stdio.h>

using namespace std;

int fib[41] = { 0,1 };


int f(int n) {
	if (n == 0) {
		return 0;
	}
	if (fib[n] != 0) {

		return fib[n];
	}
	return fib[n] = f(n - 1) + f(n - 2);
}

int main() {
	int T, i, tmp;
	scanf("%d", &T);

	for (i = 0; i < T; i++) {
		scanf("%d", &tmp);

		if (tmp == 0)
			printf("1 0 \n");
		else if (tmp == 1)
			printf("0 1 \n");
		else {
			f(tmp);
			printf("%d %d \n", f(tmp - 1), f(tmp));
		}

	}

	return 0;
}