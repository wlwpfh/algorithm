#include<stdio.h>
#include<algorithm>
using namespace std;

int arr[1001];

int main() {

	int x;
	scanf("%d", &x);

	for (int i = 2; i < x + 1; i++) {
		arr[i] = arr[i - 1] + 1;

		if (i % 2 == 0)
			arr[i] = min(arr[i], arr[i / 2] + 1);
		if (i % 3 == 0)
			arr[i] = min(arr[i], arr[i / 3] + 1);
	}

	printf("%d", arr[x]);

	return 0;
}