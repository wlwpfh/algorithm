#include<iostream>
using namespace std;

int main() {
	long long ll;
	scanf("%lld", &ll);
	int arr[10];

	int sum = 0, i = 1, j = 9, res = 0;

	while (sum + j < ll) {
		res = res + (i * j);
		sum = sum + j;
		i++;
		j = j * 10;
		printf("i: %d, j:%d, res:%d \n", i, j, res);
	}

	return 0;
}