#include<stdio.h>

using namespace std;
int n, answer = 0, count = 0, K = 0;
int arr[100001];
int main() {
	scanf("%d", &n);

	for (int i = 2; i <= n; i++) {
		arr[i] = i;
	}

	for (int i = 2; i <= n; i++) {
		if (arr[i] == 0)
			continue;
		for (int j = 2 * i; j <= n; j += i) {
			a[j] = 0;

		}
	}

	for (int i = 2; i < 100; i++) {
		if (arr[i] != 0) {

		}
	}
}