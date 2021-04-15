#include<stdio.h>
#include<vector>

int data[10], tmp[10];

using namespace std;

void div(int low, int high) {
	int mid, a, b, c;

	if (low < high) {
		mid = (low + high) / 2;
		div(low, mid);
		div(mid + 1, high);

		a = low;
		b = mid + 1;
		c = low;

		while (c <= mid && b <= high) {
			if (data[a] < data[b])
				tmp[c++] = data[a++];
			else
				tmp[c++] = data[b++];
		}

		while (a <= mid) { //누군가가 남은 경우엔 
			tmp[c++] = data[a++];
		}
		while (b <= high) {
			tmp[c++] = data[b++];
		}

		for (int i = low; i <= high; i++) {
			data[i] = tmp[i];
		} //기존의 값도 바꾸기 
	}
}

int main() {
	int i, n;

	for (i = 1; i <= n; i++) {
		scanf("%d", &data[i]);
	}
	div(1, n);

	for (i = 1; i <= n; i++) {
		printf("%d ", data[i]);
	}

	return 0;
}