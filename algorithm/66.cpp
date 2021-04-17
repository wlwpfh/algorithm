#include<stdio.h>
#include<vector>

using namespace std;

int n, m, count;
vector<int>adlist(30);

void path_finding(int num) {
	int i;
	if (num == n) {
		count++;
	}
	else {
		for (i = 1; i <= n; i++) {
			printf("%d ", adlist[i]);
		}
	}
}

int main() {
	int i, a, b;
	scanf("%d %d", &n, &m);

	for (i = 1; i <= m; i++) {
		scanf("%d %d", &a, &b);
		adlist[a] = b;
		adlist[b] = a;
	}

	path_finding(1);

	printf("%d \n", count);
	return 0;
}