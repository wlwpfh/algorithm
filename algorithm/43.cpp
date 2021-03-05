#include<stdio.h>
#include<vector>
using namespace std;

int arr[1001], n;

int count(int size) {
	int i, count = 1, sum = 0;

	for (i = 1; i <= n; i++) {
		if (sum + arr[i] > size) {
			count++;
			sum = arr[i]; //새로운 것을 만들고 새롭게 초기화 
		}
		else {
			sum = sum + arr[i];
		}
	}
	return count;
}

int main43_() {
	int m, i, result = 0, max = -1000;
	int low = 1, mid, high = 0;

	scanf("%d %d", &n, &m);



	for (i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		high = high + arr[i];
		if (arr[i] > max) {
			max = arr[i];
		}
	}

	while (low <= high) {
		mid = (low + high) / 2; //최소 용량

		if (count(mid) <= m && mid >= max) {
			result = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}


	}
	printf("%d", result);
	return 0;

}