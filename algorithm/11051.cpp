#include<stdio.h>
#define MAX 1000
using namespace std;

int arr[1001][1001];

int nCr(int n, int r) {
	if (n == r)
		return arr[n][r] = 1;
	if (r == 1)
		return arr[n][r] = n;
	return arr[n][r] = (nCr(n - 1, r - 1)%10007 + nCr(n - 1, r)%10007) % 10007;

}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	printf("%d", nCr(n, k));

	return 0;
}