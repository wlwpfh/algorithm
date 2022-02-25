#include<stdio.h>
#include<algorithm>
using namespace std;

int N;
int sugar[5001] = { 0,0,0,1,0,1,0 };

int bongji(int number) {
	if (number == N)
		return sugar[number];
	if (sugar[number] > 0) {
		return sugar[number];
	}

	return sugar[number] = min(bongji(number - 3) + 1, bongji(number - 5) + 1);
}


int main() {

	scanf("%d", &N);
	sugar[N] = -1;

	bongji(N);

	if (sugar[N] == 0)
		printf("-1 \n");
	else
		printf("%d \n", sugar[N]);

	for (int i = 0; i <= N; i++)
		printf("%d ", sugar[i]);

	return 0;
}