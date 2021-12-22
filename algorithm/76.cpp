#include<stdio.h>

using namespace std;
int n, r;
int data[100][100];
int binomial1(int a, int b) {
	if (a == b || b == 0)	return 1;
	else return binomial1(a - 1, b - 1) + binomial1(a - 1, b);


}
int binomial2(int a, int b) {
	if (data[a][b] > 0) {
		//이미 값이 구해져 있는 경우
		return data[a][b];
	}
	if (a == b || b == 0)	return 1;
	else return data[a][b] = binomial2(a - 1, b - 1) + binomial2(a - 1, b);
}

int main() {
	scanf("%d %d", &n, &r);

	printf("%d \n", binomial1(n, r));

	printf("%d \n", binomial2(n, r));

	return 0;
}