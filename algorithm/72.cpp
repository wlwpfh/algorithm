#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;

int main() {
	int i, n, k, sum = 0;
	queue<int> Q;
	scanf("%d %d", &n, &k);
	vector<int>check(n + 1);

	int num, curr = k;
	check[k] = 1;
	Q.push(k);
	while (1) {
		printf("현재 당번: %d, 미래 예상 당번: %d \n", curr, curr + k);
		if (Q.size() == n - 1)
			break;
		if (k + curr > n) {
			curr = (k + curr) % k;
		}
		else {
			curr = curr + k;
		}

		if (check[curr] == 0) {
			check[curr] = 1;
			Q.push(curr);
			printf("넣은 것: %d \n", curr);
		}

	}
	for (i = 1; i < check.size(); i++) {
		if (check[i] == 0)
			printf("%d ", i);
	}
	return 0;
}