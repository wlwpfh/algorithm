#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main38() {
	freopen("input.txt", "rt", stdin);
	int n, i, j, pos;
	scanf("%d", &n);
	vector<int> is(n + 1), os(n + 1);
	for (i = 1; i <= n; i++) {
		scanf("%d", &is[i]);
	}
	for (i = n; i >= 1; i--) {
		pos = i;
		for (j = 1; j <= is[i]; j++) {
			os[pos] = os[pos + 1];
			pos++;
		}
		os[pos] = i;
	}
	for (i = 1; i <= n; i++) {
		printf("%d ", os[i]);
	}
	return 0;
}
