#include<stdio.h>
#include<algorithm>

using namespace std;

int N,M;
int city[10004];

bool findLimit(int money) {
	int sum = 0;

	for (int i = 0; i < N; i++) {
		sum += min(money, city[i]);
	}

	return sum <= M;
}

int main() {

	int i, left = 1, right = 0, mid = 0, result = 0;

	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d", &city[i]);
		right = max(right, city[i]);

	}
	scanf("%d", &M);

	while (left <= right) {

		mid = (left + right) / 2;

		if (findLimit(mid)) {
			left = mid + 1;
			result = mid;
		}
		else
			right = mid - 1;

	}

	printf("%d", result);

	return 0;
}