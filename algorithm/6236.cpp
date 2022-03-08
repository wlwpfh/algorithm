#include<stdio.h>
#include<algorithm>
#define MAX_N 100000

using namespace std;

int N, M;
int money[MAX_N];

bool findMoney(int size) {
	int h = 0;

	for (int i = 0; i < N; i++) {
		h += max(0, money[i] - size);

	}

	if (h >= M)
		return true;
	else
		return false;
}

int main() {

	int i;
	int lb = 0, ub = 0, mid;
	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++) {
		scanf("%d", &money[i]);
		ub = max(ub, money[i]);
	}

	while (lb + 1 < ub) {
		mid = lb + (ub - lb) / 2;
		if (findMoney(mid))
			lb = mid;
		else
			ub = mid;
	}

	printf("%d", lb);

	return 0;
}