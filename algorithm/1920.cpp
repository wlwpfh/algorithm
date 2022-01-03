#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int arr[100000];

int find(int n, int number) {
	int low = 0, high = n, mid;

	while (low <= high) {
		mid = (low + high) / 2;
		if (arr[mid] == number)
			return 1;
		else if (arr[mid] < number) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return 0;
}

int main() {
	int n, m, number;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr, arr + n);

	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		scanf("%d", &number);
		printf("%d \n", find(n - 1, number));
	}

	return 0;
}