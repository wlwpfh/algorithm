#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;

vector<int> v;
int m, count;

void dp(int index, int sum) {
	if (sum == m)
		count++;
	else if (sum < m) {
		dp(v[index])
	}

	else {
		return;
	}
}
int main() {
	int n, i, j, test_case, tmp;

	scanf("%d", &test_case);

	for (i = 1; i <= test_case; i++) {
		scanf("%d", &n);

		memset(v, 0, sizeof(v));

		for (j = 1; j <= n; j++) {
			scanf("%d", &tmp);
			v.push_back(tmp);
		}
		scanf("%d", &m);
		count = 0;



	}

	return 0;
}