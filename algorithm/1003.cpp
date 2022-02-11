#include<stdio.h>
#include<memory.h>
using namespace std;

int fib[40] = { 0,1,0, };
int count_0[40], count_1[40];

//fib배열에 다 저장했는데 그 각각의 0과 1을 저장해야 함...


int f(int n) {
	if (n == 0) {
		count_0[n]++;
		return 0;
	}if (n == 1) {
		count_1[n]++;
		return 1;
	}
	if (fib[n] != 0) {
		//printf("fib[%d]는 이미 저장된 수 \n",n);
		count_0[n + 1] += count_0[n];
		count_0[n + 2] += count_0[n];
		count_1[n + 1] += count_1[n];
		count_1[n + 2] += count_1[n];
		printf("count_0[%d+2]:%d, count_1[%d+2]:%d \n ", n, count_0[n + 2] / 2, n, count_1[n + 2] / 2);
		return fib[n];
	}
	//printf("fib[%d]=f(%d)+f(%d) \n",n,n-1,n-2);


	return fib[n] = f(n - 1) + f(n - 2);
}

int main() {
	int T, i, tmp;
	scanf("%d", &T);


	for (i = 0; i < T; i++) {
		scanf("%d", &tmp);
		//memset(fib,0,sizeof(fib));

		//fib[1]=1;
		//count_0=0, count_1=0,tmp_0=0, tmp_1=0;
		f(tmp);

		printf("%d %d\n", count_0[tmp] / 2, count_1[tmp] / 2);
	}

	return 0;
}