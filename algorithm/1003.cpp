#include<stdio.h>

using namespace std;

int fib[40] = { 0,1,0, };
int count_0, count_1;

int fibonacci(int n) {
	if (n == 0 || n == 1) {
		return fib[n];
	}
	else
		return fib[n] = fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
	int T, i, tmp;
	scanf("%d", &T);


	for (i = 0; i < T; i++) {
		scanf("%d", &tmp);

		//tmp=fibonacci(tmp);
		//printf("%d %d\n",count_0,count_1);		
		//printf("tmp:%d \n",tmp);
		//count_0=0, count_1=0;
		if (tmp == 0)
			printf("1 0\n");
		else
			printf("%d %d\n", fibonacci(tmp - 1), fibonacci(tmp));
	}

	return 0;
}